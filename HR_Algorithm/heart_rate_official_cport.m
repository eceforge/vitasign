 %#codegen
function [heart_rate, last_hr_delta, hr_delta_sum, num_peak_deltas, data] = heart_rate_official_cport(data, fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, prev_hr_delta, hr_delta_sum, toss_thresh, num_peak_deltas, neg_peak_deviance_threshold, sample_time, shouldOutput)  

%------ Heart Rate Detection Algorithm ----------
%  Detects and calculates Heart rate from an EKG Signal. 
%  The QRS Detection algorithm is based on Pan-Tompkin's famous paper
%
% Inputs: 
%   data                    EKG data
%   fs                      sampling rate
%   threshold_1             threshold for filtering out peaks for channel 1
%                           used in dual threshold processing
%   threshold_2             threshold for filtering out peaks for channel 2
%                           use in dual threshold processing
%   threshold_3             threshold for filtering out peaks for channel 3 
%                           used in 4th level processing
%   pos_deviance_threshold  threshold for filtering out peak values which 
%                           deviate above the average peak values 
%   neg_deviance_threshold  threshold for filtering out peak values which
%                           devivate below an average EKG signal
%                           
%   sample_time   length in time(s) over which HR is estimated
%   
%
% Outputs:
%   heart_rate  Estimated heart rate in beats per minute
%
% % % % % % % % % % % % % % % %
%
% Gbenga Badipe


% QRS Detection
% shows the effect of each filter according to Pan-Tompkins algorithm.
% Note that, the decision  algorithm is different then the mentioned algorithm.

% by Faruk UYSAL

% Clears outputs and figures
%clc
%close all

% Ensures the the input args are of the correct data type

% Defines Signed and Unsigned Fixed point objects
Fixed_Point_Properties_signed = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
F_signed = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

% DEBUG CODE
% fipref('DataTypeOverride', 'TrueDoubles', 'LoggingMode', 'on'); % turns on datatype override to see the dynamic range of algo's values
% fipref('DataTypeOverride', 'ForceOff'); % turns off datatype override

% F.sub(fi(3), fi(2))
% asserts that the input parameters are of fixed point
assert(isa(shouldOutput,'uint32'));
assert(isfi(data));
assert(isa(fs, 'uint32'));
assert(isfi(threshold_1));
assert(isfi(threshold_2));
assert(isfi(threshold_3));
assert(isfi(pos_deviance_threshold));
assert(isfi(neg_deviance_threshold));
assert(isa(sample_time, 'uint32'));
assert(isfi(prev_hr_delta));
assert(isfi(hr_delta_sum));
assert(isfi(neg_peak_deviance_threshold));
assert(isfi(toss_thresh));
assert(isfi(num_peak_deltas));

% asserts that input parameters are of specific fixed point parameters
assert(isequal(numerictype(data), Fixed_Point_Properties_signed) && isequal(fimath(data), F_signed));
% assert(isequal(numerictype(fs),Fixed_Point_Properties) && isequal(fimath(fs), F));
% assert(isequal(numerictype(data), Fixed_Point_Properties) && isequal(fimath(data), F));
assert(isequal(numerictype(threshold_1),Fixed_Point_Properties) && isequal(fimath(threshold_1), F));
assert(isequal(numerictype(threshold_2),Fixed_Point_Properties) && isequal(fimath(threshold_2), F));
assert(isequal(numerictype(threshold_3),Fixed_Point_Properties) && isequal(fimath(threshold_3), F));
assert(isequal(numerictype(pos_deviance_threshold),Fixed_Point_Properties) && isequal(fimath(pos_deviance_threshold), F));
assert(isequal(numerictype(neg_deviance_threshold),Fixed_Point_Properties) && isequal(fimath(neg_deviance_threshold), F));
assert(isequal(numerictype(hr_delta_sum),Fixed_Point_Properties) && isequal(fimath(hr_delta_sum), F));
assert(isequal(numerictype(num_peak_deltas),Fixed_Point_Properties) && isequal(fimath(num_peak_deltas), F));
assert(isequal(numerictype(toss_thresh),Fixed_Point_Properties) && isequal(fimath(toss_thresh), F));
assert(isequal(numerictype(neg_peak_deviance_threshold),Fixed_Point_Properties) && isequal(fimath(neg_peak_deviance_threshold), F));

% Ensures that the prev time delta is unsigned and has fractional bits
% specified by Fixed_Point_Properties
assert(isequal(numerictype(prev_hr_delta),Fixed_Point_Properties) && isequal(fimath(prev_hr_delta), F));
% assert(isequal(numerictype(sample_time),Fixed_Point_Properties) && isequal(fimath(sample_time), F));
       
%  Assures that the first threshold is less than the second threshold
assert(threshold_1 < threshold_2);

%  Assures that the third threshold is in between the first and the second
% threshold
assert(threshold_3 < threshold_2 && threshold_3 > threshold_1);

%x1 = load('ecg3.dat'); % load the ECG signal from the file
assert (all ( size (data) == [500 1] ));

% x1 = data;
N = uint32(length(data));       % Signal length


% Assures that the number of samples sent in aren't greater than the
% specified sample size
assert(divide(Fixed_Point_Properties, fi(N, Fixed_Point_Properties, F), fi(fs, Fixed_Point_Properties, F)) >= sample_time);


% x1 = x1/ max( abs(x1 )); % normalize to one
% max_x = fi(max(abs(data)), Fixed_Point_Properties_signed, F_signed);
%CANCELLATION DC DRIFT AND NORMALIZATION
data = data - mean (data);    % cancel DC conponents
max_val = fi(0, Fixed_Point_Properties, F);

% Finds the maximum of the absolute value of the array
for i=1:uint32(length(data))
    abs_data = fi(abs(data(i)), Fixed_Point_Properties, F);
    if (abs_data > max_val)
        max_val = abs_data;
     end
end 
% % for i=1:length(x1)
% %     divide(Fixed_Point_Properties_signed, x1(i), max_x) % normalize to one
% % end
data = divide(Fixed_Point_Properties_signed, data, max_val); % normalize to one
% assert(isequal(numerictype(data),Fixed_Point_Properties_signed) && isequal(fimath(data), F_signed));

%------ MOST FILTERING NOW OCCURS IN ANALOG SEE 'front_end_filters.m' FOR EMULATED FRONT END FILTERS

%DERIVATIVE FILTER

% Make impulse response
h = divide(Fixed_Point_Properties_signed, fi([-1 -2 0 2 1], Fixed_Point_Properties_signed, F_signed), fi(8, Fixed_Point_Properties_signed, F_signed));
% Apply filter
data = conv (data ,h);
data = data (2+ (1: N));
% max_val = fi(max(abs(data)), Fixed_Point_Properties_signed, F_signed);

max_val = fi(0, Fixed_Point_Properties, F);
% Finds the absolute value of the array
for i=1:uint32(length(data))
    abs_data = fi(abs(data(i)), Fixed_Point_Properties, F);
    if (abs_data > max_val)
        max_val = abs_data;
     end
end 
data = divide(Fixed_Point_Properties_signed, data, max_val);

% UPDATES FIXED POINT DEFINITION TO BE UNSIGNED(CURRENTLY REVERESED TO BE
% SIGNED B/C OF SPACE CONSTRAINTS
Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

  
 
%SQUARING
for i=1:uint32(length(data))
    data(i) = data(i) * data(i);
end 
% data = fi(data.^2, Fixed_Point_Properties, F);
% squared_data = data;

% Changes the fixed point properties of the data to be unsigned after
% squaring
% data_unsigned = fi(data, Fixed_Point_Properties, F);

% Normalizes the result of the squaring
% data_unsigned = divide(Fixed_Point_Properties, data_unsigned, max( data_unsigned )); % normalize to one
% assert(isequal(numerictype(data_unsigned),Fixed_Point_Properties) && isequal(fimath(data_unsigned), F));

%MOVING WINDOW INTEGRATION

% Make impulse response
h = divide(Fixed_Point_Properties, fi(ones (1, 7), Fixed_Point_Properties, F), 7);

% Delay = 15; % Delay in samples

% Apply filter
data = fi(conv (data ,h), Fixed_Point_Properties, F);
data = data (3+(1: N));

% Normalizes the signal 
data = divide(Fixed_Point_Properties, data, max(data)); % normalize to one

%FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM

max_voltage = max(data);
assert(isequal(numerictype(max_voltage),Fixed_Point_Properties) && isequal(fimath(max_voltage), F));

thresh = mean (data);
scaled_thresh = thresh * max_voltage;
% Outputs an array with each value indicating whether the value at that
% index is greater than thresh * max_h
% poss_reg = int32((data_unsigned > thresh*max_voltage)');
% poss_reg =(data_unsigned > thresh*max_voltage)';


left = uint32(zeros(1, N));
right = uint32(zeros(1, N));
%  Finds(the indices) all the heart beats which are preceded by a
%  non-beat(left)
% Finds all the heart beats where  the heart beats are proceeded by a
% non-beat(right)
left_index = uint32(1);
right_index = uint32(1);
for i=1:uint32(N)
    if (data(i) > scaled_thresh)
        % Checks for the edge cases
        if(i == 1)
            left(left_index) = i;
            left_index = left_index + 1;
            continue;
        elseif(i == N)
            right(right_index) = i;
            right_index = right_index + 1;
            continue;
        else
            % Checks if a beat is proceeded or preceeded by a beat
            if(data(i - 1) <= scaled_thresh)
                left(left_index) = i;
                left_index = left_index + 1;
            end
            if(data(i + 1) <= scaled_thresh)
                right(right_index) = i;
                right_index = right_index + 1;
            end
        end
    else
%         left(i) = uint32(0);
%         right(i) = uint32(0);
    end
end

%  Finds(the indices) all the heart beats which are preceded by a non-beat
% left = uint32(find(diff([int32(0) poss_reg]) == int32(1))) % Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1
% Finds all the heart beats where  the heart beats are proceeded by a
% non-beat
% right = uint32(find(diff([poss_reg 0]) == int32(-1)))

% Don't need poss_reg after this call
left_num_cols = uint32(length(left));

%  Finds(the indices) all the heart beats which are preceded by a non-beat
% left = find(diff([0 poss_reg])==1); % Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1
% Finds all the heart beats where  the heart beats are proceeded by a
% non-beat
% right = find(diff([poss_reg 0])==-1);

%left=left-(6+16);  % cancel delay because of LP and HP
%right=right-(6+16);% cancel delay because of LP and HP
% [~, left_num_cols] = size(left);

% R_peak_vals = fi(zeros(uint32(1), left_num_cols), Fixed_Point_Properties, F);
R_peak_indices_channel_1 = uint32(zeros(uint32(1), left_num_cols));
max_val = fi(0, Fixed_Point_Properties, F);
max_index = uint32(0);
num_cols_indices = uint32(0);
for i=1:left_num_cols
     if(left(i) == 0)
         break;
     end
%      [R_peak_vals(i) R_peak_indices(i)] = max(data(left(i):right(i)) );
%      [data_unsigned(i) R_peak_indices_channel_1(i)] = max(data_unsigned(left(i):right(i)) );
%      Finds the max value from left(i) to right(i)
     for j=left(i):right(i)
         % Compares to find the maximum
         if(fi(sqrt(data(j)), Fixed_Point_Properties, F) > max_val)
             max_val = fi(sqrt(data(j)), Fixed_Point_Properties, F);
             max_index = j;
         end
     end
     
     % Saves the peak's index and value
     data(i) = max_val;
     R_peak_indices_channel_1(i) = max_index;
     num_cols_indices = num_cols_indices + 1;
      
     % Resets max for next iteration
     max_val = fi(0, Fixed_Point_Properties, F);
end

% there is no selective wave
% R_peak_indices_channel_1=R_peak_indices_channel_1(R_peak_indices_channel_1~=uint32(0));


% VITASIGN'S CODE BELOW

% Level 1 Detection: Detects all peaks 
% R_peak_vals = R_peak_vals;
% R_peak_indices = R_peak_indices;

% Level 2 Detection: Uses two channels to detect heart beats based on two threshold
% [num_rows_vals, num_cols_vals] = size(R_peak_vals);
% [~, num_cols_indices] = size(R_peak_indices);
% num_cols_indices = uint32(length(R_peak_indices_channel_1));

% Creates a copy of the indices which store the indices where the 'R' peaks
% lie
% if(shouldOutput)
%      num_cols_indices;
% end

% R_peak_indices_channel_1 = R_peak_indices(1:num_cols_indices); 
R_peak_indices_channel_2 = R_peak_indices_channel_1(1:left_num_cols);
% R_peak_indices_combined = zeros(1, length(R_peak_indices_channel_2)); % REPLACE THIS WITH A ZEROS ARRAY

[R_peak_indices_channel_1, noise_lvl_channel_1, signal_lvl_channel_1] = dualThreshold(data, threshold_1, uint32(R_peak_indices_channel_1), max_voltage, pos_deviance_threshold, neg_deviance_threshold, num_cols_indices, shouldOutput);
[R_peak_indices_channel_2, noise_lvl_channel_2, signal_lvl_channel_2] = dualThreshold(data, threshold_2, uint32(R_peak_indices_channel_2), max_voltage, pos_deviance_threshold, neg_deviance_threshold, num_cols_indices, shouldOutput);
% CAN RELEASE DATA HERE 

% if(shouldOutput)
%     chan1 = length(find(R_peak_indices_channel_1))
%     chan2 = length(find(R_peak_indices_channel_2))
% end
% Ensures that noise and signal levels are fixed point
assert(isfi(noise_lvl_channel_1));assert(isfi(signal_lvl_channel_1));
assert(isfi(noise_lvl_channel_2));assert(isfi(signal_lvl_channel_2));

assert(isequal(numerictype(noise_lvl_channel_1),Fixed_Point_Properties) && isequal(fimath(noise_lvl_channel_1), F));
assert(isequal(numerictype(noise_lvl_channel_2),Fixed_Point_Properties) && isequal(fimath(noise_lvl_channel_2), F));

assert(isequal(numerictype(signal_lvl_channel_1),Fixed_Point_Properties) && isequal(fimath(signal_lvl_channel_1), F));
assert(isequal(numerictype(signal_lvl_channel_2),Fixed_Point_Properties) && isequal(fimath(signal_lvl_channel_2), F));

% Level 3 DETECTION: REFINES HEART BEAT DETECTION ACCURACY BY CHANNEL
% COMPARISON
% Combines both channels to refine beat detection
for i=1:num_cols_indices
    % Documents the other cases %
    
    % If the signal's amplitude passes both the channels then there is a
    % high chance of a beat
    %if (R_peak_indices_channel_1(i) ~= 0 && R_peak_indices_channel_2(i) ~=0)
    
    % If the signal's amplitude is less than channel 1's threshold(the
    % lower threshold) and higher than channel 2's threshold(the higher
    % threshold) then there's a chance that there is a beat
    %This case will not happen b/c channel 1's threshold is < channel's 2 threshold
    %if (R_peak_indices_channel_1(i) == 0 && R_peak_indices_channel_2(i) ~=0)   
    
    % If the signal's amplitude fails both the channels then there is a
    % high chance that the it's not a beat
    if (R_peak_indices_channel_1(i) == uint32(0) && R_peak_indices_channel_2(i) == uint32(0))
        R_peak_indices_channel_2(i) = uint32(0);
    elseif (R_peak_indices_channel_1(i) ~= uint32(0) && R_peak_indices_channel_2(i) == uint32(0))
  
        % Uses the decision of the channel w/ the highest Detection.
        % Ensures that Ds is between 0 and 1
        % strength(Ds)
        
        % If the delta between the peak value and the noise level is < 0
        % then due to unsigned fixed point rules this value is 0 which is what we
        % want anyways so this proves to be a useful overflow case.
        if (signal_lvl_channel_1 < noise_lvl_channel_1)
            Ds_1 = fi(0, Fixed_Point_Properties, F);
        else
            Ds_1 = min(1, divide(Fixed_Point_Properties, ((data(i) * 100 - noise_lvl_channel_1 * 100)), (signal_lvl_channel_1 * 100 - noise_lvl_channel_1 * 100)));
        end
%         Ds_1 = max(0, Ds_1);

        if (signal_lvl_channel_2 < noise_lvl_channel_2)
            Ds_2  = fi(0, Fixed_Point_Properties, F);
        else
           Ds_2 = min(1, divide(Fixed_Point_Properties, ((data(i) * 100 - noise_lvl_channel_2 * 100)), (signal_lvl_channel_2 * 100 - noise_lvl_channel_2 * 100)));
        end
%         Ds_2 = max(0, Ds_2);
      
        if (Ds_1 > Ds_2)
            R_peak_indices_channel_2(i) = R_peak_indices_channel_1(i);
        else
            R_peak_indices_channel_2(i) = R_peak_indices_channel_2(i);
        end
    end
end

% if(shouldOutput)
%     final = length(find(R_peak_indices_channel_2))
% end
% LEVEL 5 DETECTION: 
%Refines heart beat detection by considering a heart beat's refactory period    

% Sets R values to zero which failed any of the previous phases
last_R_index = fi(0, Fixed_Point_Properties, F);
% Sample time delta is based off the Fs passed in
% time_delta = divide(Fixed_Point_Properties, fi(1, Fixed_Point_Properties, F), fi(100, Fixed_Point_Properties, F));
time_delta = divide(Fixed_Point_Properties, 1, 100);

% Heart beat delta sum is the summation of the time between heart beats. It's used for
% HR calculation
heart_beat_current_sum = fi(0, Fixed_Point_Properties, F);
heart_beat_last_sum = fi(0, Fixed_Point_Properties, F);

% Heart beat count is the amount of heart beats detected
heart_beat_count = fi(0, Fixed_Point_Properties, F);

for i=1:num_cols_indices
    if (R_peak_indices_channel_2(i) == uint32(0))
        data(i) = uint32(0);
     % Filters out any R_values which happen too soon after a previous
     % beat detection. Updates the average HR delta which will be used to
     % calculate HR
    else
        % Updates the index
        current_R_index = fi(R_peak_indices_channel_2(i), Fixed_Point_Properties, F);
        
        %Filters out any R_values which happen too soon after a previous
        % beat detection.
        peak_delta = ((current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta);
        if (last_R_index ~= 0 && peak_delta < .200)
            data(i) = 0;
            R_peak_indices_channel_2(i) = 0;
         
        % Initializes the first delta which is when the first heart
        % beat occurs
        elseif(last_R_index == 0)
%             assert(isequal(numerictype(prev_hr_delta),Fixed_Point_Properties) && isequal(fimath(prev_hr_delta), F));
%             heart_beat_delta = (current_R_index - 1) * time_delta + prev_hr_delta;
%             heart_beat_current_sum = heart_beat_delta + 0; % For future iterations: Add the previous delta from the previous data window. i.e. the amount of secs between the last peak in the sample and the next one in the next sample
            
            % Updates the last index
            last_R_index = fi(R_peak_indices_channel_2(i), Fixed_Point_Properties, F);
            
            % Updates the heart beat count
%             heart_beat_count = heart_beat_count + 1;
            
        % Updates the last index if the R_value is valid
        else   
              heart_beat_delta = (current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta;
              
              % Calcs the HR peak delta average
              if(num_peak_deltas ~= 0)
                hr_delta_avg = divide(Fixed_Point_Properties, hr_delta_sum, num_peak_deltas);
              end
              
              % Tosses out peaks which occur below the deviance threshold of the average peak delta
              if (num_peak_deltas < toss_thresh || (num_peak_deltas >= toss_thresh && meets_deviance_threshold(heart_beat_delta, hr_delta_avg, fi(100, Fixed_Point_Properties, F), neg_peak_deviance_threshold)))
                  % Updates the number of peaks and sum
                  num_peak_deltas = num_peak_deltas + 1;
                  hr_delta_sum = hr_delta_sum + heart_beat_delta;
              else
                  continue;
              end
              
              heart_beat_current_sum = heart_beat_current_sum + (current_R_index - 1) * time_delta;
              heart_beat_last_sum = heart_beat_last_sum + (last_R_index - 1) * time_delta;
    %             heart_beat_delta = (current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta;
    %             heart_beat_current_sum = heart_beat_current_sum + heart_beat_delta;
                % Updates the heart beat count
              heart_beat_count = heart_beat_count + 1;

             % Updates the last index
             last_R_index = fi(R_peak_indices_channel_2(i),   Fixed_Point_Properties, F);
            
        end
    end
end

last_hr_delta = fi(0, Fixed_Point_Properties, F);

% CALCULATES HEART RATE USING AVERAGE TIME TIME DELTAS BETWEEN BEATS
%   Provides less quantized HR values

% Produces a result which is avg heart beat delta(s)
heart_beat_delta_sum = heart_beat_current_sum - heart_beat_last_sum;

% Avoids dividing by zero
if (heart_beat_delta_sum == 0)  
    heart_rate = heart_beat_delta_sum * heart_beat_delta_sum; % This is to ensure the Q value of HR is 20
    return;
end
% heart_rate = heart_beat_delta_sum * heart_beat_delta_sum; % This is to ensure the Q value of HR is 20
% heart_beat_delta_sum = fi(heart_rate, Fixed_Point_Properties, F);
% heart_beat_delta_sum = heart_beat_delta_sum + heart_beat_delta_sum;

intermediate_heart_rate  = divide(Fixed_Point_Properties, heart_beat_delta_sum, heart_beat_count);
% Inverses it to produce HBPM
intermediate_heart_rate = divide(Fixed_Point_Properties, 1, intermediate_heart_rate);
heart_rate = intermediate_heart_rate * 60;

end

% RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE
% THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS
function [meets_deviance_req] = meets_deviance_threshold(hr_value, signal_level, pos_deviance_threshold, neg_deviance_threshold)
        Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
        F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
        % asserts that the input parameters are of fixed point
        assert(isfi(hr_value));
        assert(isfi(signal_level));
        assert(isfi(pos_deviance_threshold));
        assert(isfi(neg_deviance_threshold));
        % asserts that input parameters are of specific fixed point parameters
        assert(isequal(numerictype(hr_value), Fixed_Point_Properties) && isequal(fimath(hr_value), F));
        assert(isequal(numerictype(signal_level), Fixed_Point_Properties) && isequal(fimath(signal_level), F));
        assert(isequal(numerictype(pos_deviance_threshold), Fixed_Point_Properties) && isequal(fimath(pos_deviance_threshold), F));
        assert(isequal(numerictype(neg_deviance_threshold), Fixed_Point_Properties) && isequal(fimath(neg_deviance_threshold), F));
    %Accounts for the first signal value
    if (signal_level == 0)
        meets_deviance_req = 1;
        return;
    end
    
    if (hr_value < signal_level)
        deviance = divide(Fixed_Point_Properties, ((signal_level * 100 - hr_value * 100)), signal_level);
        is_neg = 1;
    else
        deviance = divide(Fixed_Point_Properties, ((hr_value * 100 - signal_level * 100)), signal_level);
        is_neg = 0;
    end
    % Checks value against NEG and POS deviance threshold
    if (is_neg)
        if (deviance < neg_deviance_threshold * 100)
            meets_deviance_req = 1;
        else
%             fprintf('Does not meet neg deviance threshold %d\n', double(deviance));
            meets_deviance_req = 0;
        end
    else
        if (deviance < pos_deviance_threshold * 100)
            meets_deviance_req = 1;
        else
%             fprintf('Does not meet pos deviance threshold %d\n', double(deviance));
            meets_deviance_req = 0;
        end
    end
end

%DUAL THRESHOLD PROCESSSING
% Filters out R_peaks which don't meet the threshold reqs
    function [indices, noise_lvl, signal_lvl, R_peak_vals] = dualThreshold(R_peak_vals, threshold, indices, max_voltage, pos_deviance_threshold, neg_deviance_threshold, num_cols_indices, ~)
        Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
        F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
        
        % asserts that the input parameters are of fixed point
        assert(isfi(R_peak_vals));
        assert(isfi(threshold));
        assert(isa(indices,'uint32'));
        assert(isfi(max_voltage));
        assert(isfi(pos_deviance_threshold));
        assert(isfi(neg_deviance_threshold));
        % asserts that input parameters are of specific fixed point parameters
        assert(isequal(numerictype(R_peak_vals), Fixed_Point_Properties) && isequal(fimath(R_peak_vals), F));
        assert(isequal(numerictype(threshold), Fixed_Point_Properties) && isequal(fimath(threshold), F));
        assert(isequal(numerictype(max_voltage), Fixed_Point_Properties) && isequal(fimath(max_voltage), F));
        assert(isequal(numerictype(pos_deviance_threshold), Fixed_Point_Properties) && isequal(fimath(pos_deviance_threshold), F));
        assert(isequal(numerictype(neg_deviance_threshold), Fixed_Point_Properties) && isequal(fimath(neg_deviance_threshold), F));
        noise_sum = fi(0, Fixed_Point_Properties, F); signal_sum = fi(0, Fixed_Point_Properties, F);
        noise_count = fi(0, Fixed_Point_Properties, F); signal_count = fi(0, Fixed_Point_Properties, F); % Setting signal count to 1 ensures that the first value doesn't dominate the avg signal level
        noise_lvl = fi(0, Fixed_Point_Properties, F); signal_lvl = fi(0,Fixed_Point_Properties, F);
        for index=1:num_cols_indices
           if (R_peak_vals(index) * max_voltage > threshold) 
               
               % Filters out any signal value which exceeds the allowed deviance from
               % the average signal value 
               if (~meets_deviance_threshold(R_peak_vals(index), signal_lvl, pos_deviance_threshold, neg_deviance_threshold) && index > 2)
                   % Sets all the indices which R_vals don't meet the threshold to 0
                   indices(index) = 0;               
                   % Updates the average noise signal lvl
                   noise_sum = noise_sum  + R_peak_vals(index);
                   noise_count = noise_count + 1;
                   
                   % Calculates the noise level
                   noise_lvl = divide(Fixed_Point_Properties, noise_sum, noise_count);
                   continue;
               end               
                % Updates the average signal lvl
               signal_sum = signal_sum + R_peak_vals(index);
               signal_count = signal_count + 1;
               
               % Calculates the signal level
               signal_lvl = divide(Fixed_Point_Properties, signal_sum, signal_count);
           else
               % Sets all the indices which R_vals don't meet the threshold to 0
               indices(index) = 0; 
               % Updates the average noise signal lvl
               noise_sum = noise_sum  + R_peak_vals(index);
               noise_count = noise_count + 1;
               % Calculates the noise level
               noise_lvl = divide(Fixed_Point_Properties, noise_sum, noise_count);
           end          
        end
    end  