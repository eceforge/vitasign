%#codegen
function [heart_rate] = heart_rate_official_cport(data, fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size, shouldPlot)  
%TO DO -
% Uncomment the line:
% REMOVE AFTER TESTING
    %indices(i) = 0;

%data - EKG data
%fs - sampling rate
%threshold_1 - threshold for filtering out peaks for channel 1
%threshold_2 - threshold for filtering out peaks for channel 2
%threshold_3 - threshold for filtering out peaks for channel 3
%sample_size - length in time(s) over which HR is estimated

% QRS Detection
% shows the effect of each filter according to Pan-Tompkins algorithm.
% Note that, the decision  algorithm is different then the mentioned algorithm.

% by Faruk UYSAL

%clear all
%close all

% [GB] Assures that the first threshold is less than the second threshold
assert(threshold_1 < threshold_2);

% [GB] Assures that the third threshold is in between the first and the second
% threshold
assert(threshold_3 < threshold_2 && threshold_3 > threshold_1);
%x1 = load('ecg3.dat'); % load the ECG signal from the file

x1 = data;
N = length (x1);       % Signal length
t = (0:N-1)/fs;        % time index
NFFT = 2 ^(ceil(log2(N))); %[GB] Next power of 2 from length of the signal

% Assures that the number of samples sent in aren't greater than the
% specified sample size
assert(N/fs >= sample_size);

% UNCOMMENT TO SEE PLOT OF ORIGINAL EKG

    %figure(1)
    %sub%plot(2,1,1)
    %plot(t,x1)
    %xlabel('second');ylabel('Volts');title('Input ECG Signal')
    %sub%plot(2,1,2)
    %plot(t(200:600),x1(200:600))
    %xlabel('second');ylabel('Volts');title('Input ECG Signal 1-3 second')
    %xlim([1 3]);

%CANCELLATION DC DRIFT AND NORMALIZATION
x1 = x1 - mean (x1 );    % cancel DC conponents
x1 = x1/ max( abs(x1 )); % normalize to one

% UNCOMMENT TO SEE PLOT OF EKG AFTER NORMALIZATION AND REMOVAL OF DC DRIFT

    %figure(3)
    %sub%plot(2,1,1)
    %plot(t,x1)
    %xlabel('second');ylabel('Volts');title(' ECG Signal after cancellation DC drift and normalization')
    %sub%plot(2,1,2)
    %plot(t(200:600),x1(200:600))
    %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
    %xlim([1 3]);
 % UNCOMMENT TO SEE FFT OF ORIGINAL EKG
    if (shouldPlot)
        %Plots the fft of the original signal
        transform=fft(x1,NFFT)/N;%[GB] Transform from discrete values to the frequency domain
        %transform=transform;
        %windows=[windows,abs(transform)];
        freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index
     %   fprintf('Plotting\n');
        figure(2) 
        plot(freq,2*abs(transform(1:NFFT/2+1)));
        title('FFT EKG Signal');
        xlabel('Frequency (Hz)');
        ylabel('|X(f)|');
    end
%LOW PASS FILTERING

% LPF (1-z^-6)^2/(1-z^-1)^2
%b=[1 0 0 0 0 0 -2 0 0 0 0 0 1];
%a=[1 -2 1];


%h_LP=filter(b,a,[1 zeros(1,12)]); % transfer function of LPF
if(shouldPlot)
    %figure(21)
    %freqz(b,a,1000,fs)
end

% x2 = conv (x1 ,h_LP);
Fc  = 16;
low_pass_order = 2;   % FIR filter order
low_pass_spec = fdesign.lowpass('N,Fc',low_pass_order,Fc,fs);
low_pass = design(low_pass_spec,'window','window',@hamming);
x2 = filter(low_pass, x1);
%x2 = x2 (6+[1: N]); %cancle delay
x2 = x2/ max( abs(x2 )); % normalize , for convenience .

% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING LOW PASSED

    %figure(3)
    %sub%plot(2,1,1)
    %plot([0:length(x2)-1]/fs,x2)
    %xlabel('second');ylabel('Volts');title(' ECG Signal after LPF')
    %xlim([0 max(t)]);
    %sub%plot(2,1,2)
    %plot(t(200:600),x2(200:600))
    %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
    %xlim([1 3]);
 
% UNCOMMENT TO SEE FFT PLOT OF EKG AFTER BEING LOW PASSED
    if(shouldPlot)
        % Takes the fft of the signal %
        transform=fft(x2,NFFT)/N;%[GB] Transform from discrete values to the frequency domain

        % Plots the fft of the filtered signal
    %   transform=transform;
        %windows=[windows,abs(transform)];
        freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index
    %    fprintf('Plotting\n');
        figure(4)
        plot(freq,2*abs(transform(1:NFFT/2+1)));
        title('FFT LP Filtered EKG Signal');
        xlabel('Frequency (Hz)');
        ylabel('|X(f)|');
    end

%HIGH PASS FILTERING

% HPF = Allpass-(Lowpass) = z^-16-[(1-z^-32)/(1-z^-1)]
%b = [-1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 32 -32 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1];
%a = [1 -1];

%h_HP=filter(b,a,[1 zeros(1,32)]); % impulse response iof HPF
if(shouldPlot)
%     freqz(h_HP);
end
Fc  = 5;
high_pass_order = 2;   % FIR filter order
high_pass_spec = fdesign.highpass('N,Fc',high_pass_order,Fc,fs);
high_pass = design(high_pass_spec,'window','window',@hamming);
%x3 = conv (x2 ,h_HP);
%x3 = x3 (16+[1: N]); %cancle delay
x3 = filter(high_pass, x2);
x3 = x3/ max( abs(x3 ));


% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING HIGH PASSED

    %figure(5)
    %sub%plot(2,1,1)
    %plot([0:length(x3)-1]/fs,x3)
    %xlabel('second');ylabel('Volts');title(' ECG Signal after HPF')
    %xlim([0 max(t)]);
    %sub%plot(2,1,2)
    %plot(t(200:600),x3(200:600))
    %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
    %xlim([1 3]);
% UNCOMMENT TO SEE FFT PLOT OF EKG AFTER BEING HIGH PASSED
if(shouldPlot)
    % Takes the fft of the signal %
    transform=fft(x3,NFFT)/N;%[GB] Transform from discrete values to the frequency domain

    % Plots the fft of the filtered signal
  %  transform=transform;
    %windows=[windows,abs(transform)];
    freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index
    %fprintf('Plotting\n');
    figure(6)
    plot(freq,2*abs(transform(1:NFFT/2+1)));
    title('FFT HP Filtered EKG Signal');
    xlabel('Frequency (Hz)');
    ylabel('|X(f)|');
end

%DERIVATIVE FILTER

% Make impulse response
h = [-1 -2 0 2 1]/8;
% Apply filter
x4 = conv (x3 ,h);
x4 = x4 (2+ (1: N));
x4 = x4/ max( abs(x4 ));

% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING A DERIVATIVE FILTER IS APPLIED

    %figure(7)
    %subplot(2,1,1)
    %plot([0:length(x4)-1]/fs,x4)
    %xlabel('second');ylabel('Volts');title(' ECG Signal after Derivative')
    %subplot(2,1,2)
    %plot(t(200:600),x4(200:600))
    %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
    %xlim([1 3]);
 
%SQUARING

x5 = x4 .^2;
x5 = x5/ max( abs(x5 ));

% UNCOMMENT TO SEE PLOT OF EKG AFTER SQUARING
    %figure(8)
    %subplot(2,1,1)
    %plot([0:length(x5)-1]/fs,x5)
    %xlabel('second');ylabel('Volts');title(' ECG Signal Squarting')
    %subplot(2,1,2)
    %plot(t(200:600),x5(200:600))
    %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
    %xlim([1 3]);
 
%MOVING WINDOW INTEGRATION

% Make impulse response
h = ones (1 ,31)/31;
% Delay = 15; % Delay in samples

% Apply filter
x6 = conv (x5 ,h);
x6 = x6 (15+(1: N));
% Normalizes the signal 
x6 = x6 / max( abs(x6 ));

% UNCOMMENT TO SEE PLOT OF EKG AFTER A MWI IS APPLIED

    %figure(9)
    %subplot(2,1,1)
    %plot([0:length(x6)-1]/fs,x6)
    %xlabel('second');ylabel('Volts');title(' ECG Signal after Averaging')
    %subplot(2,1,2)
    %plot(t(200:600),x6(200:600))
    %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
    %xlim([1 3]);
 
%FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM

%figure(7)
%subplot(2,1,1)
max_h = max(x6);
max_voltage = max_h;
thresh = mean (x6 );
%[GB] Outputs an array with each value indicating whether the value at that
% index is greater than thresh * max_h
poss_reg =(x6>thresh*max_h)';

% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING INTEGRATED?

    %figure (10)
    %subplot(2,1,1)
    %hold on
    %plot (t(200:600),x1(200:600)/max(x1))
    %box on
    %xlabel('second');ylabel('Integrated')
    %xlim([1 3]);

    %subplot(2,1,2)
    %plot (t(200:600),x6(200:600)/max(x6))
    %xlabel('second');ylabel('Integrated')
    %xlim([1 3]);

% [GB] Finds(the indices) all the heart beats which are preceded by a non-beat
left = find(diff([0 poss_reg])==1); %[GB] Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1
% [GB] Finds all the heart beats where  the heart beats are proceeded by a
% non-beat
%left(1:10);
right = find(diff([poss_reg 0])==-1);
%left=left-(6+16);  % cancel delay because of LP and HP
%right=right-(6+16);% cancel delay because of LP and HP
R_value = zeros(N);
R_loc = zeros(N);
for i=1:length(left)  
    [R_value(i) R_loc(i)] = max( x1(left(i):right(i)) );
    R_loc(i) = R_loc(i)-1+left(i); % add offset

%     [Q_value(i) Q_loc(i)] = min( x1(left(i):R_loc(i)) );
%     Q_loc(i) = Q_loc(i)-1+left(i); % add offset

%     [S_value(i) S_loc(i)] = min( x1(left(i):right(i)) );
%     S_loc(i) = S_loc(i)-1+left(i); % add offset

end

% there is no selective wave
R_loc=R_loc(find(R_loc~=0));
% Q_loc=Q_loc(find(Q_loc~=0));
% S_loc=S_loc(find(S_loc~=0));

% UNCOMMENT TO SEE RESULTS OF THE QRS DETECTION

    %figure(11)
    %subplot(2,1,1)
    %title('ECG Signal with R points');
    %plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
    %legend('ECG','R','S','Q');
    %subplot(2,1,2)
    %plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
    %xlim([1 3]);

% VITASIGN'S CODE BELOW

% Level 1 Detection: Detects all peaks 
R_peak_vals = R_value;
R_peak_indices = R_loc;

% Level 2 Detection: Uses two channels to detect heart beats based on two threshold
% [num_rows_vals, num_cols_vals] = size(R_peak_vals);
% [num_rows_indices, num_cols_indices] = size(R_peak_indices);

% Creates a copy of the indices which store the indices where the 'R' peaks
% lie

% NEEDS OPTIMIZATION. NEED TO AVOID COPYING LARGE ARRAYS 
R_peak_indices_channel_1 = R_peak_indices(1:num_cols_indices); 
R_peak_indices_channel_2 = R_peak_indices(1:num_cols_indices);
R_peak_indices_channel_3 = R_peak_indices(1:num_cols_indices);
R_peak_indices_combined = R_peak_indices(1:num_cols_indices); % REPLACE THIS WITH A ZEROS ARRAY

% UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE CHANNEL 1 PROCESSING
    %if (shouldPlot)
    %    fprintf('Channel 1 Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0)));
    %end

[R_peak_indices_channel_1, noise_lvl_channel_1, signal_lvl_channel_1] = dualThreshold(threshold_1, R_peak_indices_channel_1, max_voltage, pos_deviance_threshold, neg_deviance_threshold);
[R_peak_indices_channel_2, noise_lvl_channel_2, signal_lvl_channel_2] = dualThreshold(threshold_2, R_peak_indices_channel_2, max_voltage, pos_deviance_threshold, neg_deviance_threshold);

% UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER CHANNEL 1 PROCESSING
    %if (shouldPlot)
    %    fprintf('Channel 1 Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0)));
    %end


% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE FIRST CHANNEL

if (shouldPlot)
    % Sets R values to zero which failed any of the previous phases 
    R_valuea = R_value;
    for i=1:length(R_valuea)
        if (R_peak_indices_channel_1(i) == 0)
            R_valuea(i) = 0;
        end
    end
    R_valuea = R_valuea(find(R_valuea ~= 0));   
    R_peak_indices_channel_1a = R_peak_indices_channel_1((R_peak_indices_channel_1 ~= 0));
    fprintf('The length of R after is: %i\n',length(R_valuea));
    %fprintf('The length of R_indices after is: %i\n',length(R_peak_indices_channel_1a));   
    t(R_peak_indices_channel_1a)
    %clf(figure(13));
    figure(13)
    subplot(2,1,1)
    plot (t, x1/max(x1), t(R_peak_indices_channel_1a), R_valuea, 'r^');
    title('ECG Signal Post Channel 1 Processing');
    xlabel('Time(s)');
    ylabel('mV');
    legend('ECG','R');
    
    subplot(2,1,2)
    plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^');
    title('ECG All Detected Peaks');
    xlabel('Time(s)');
    ylabel('mV')
    %plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
end
% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE SECOND CHANNEL

if (shouldPlot)
    % Sets R values to zero which failed any of the previous phases 
    R_valuea = R_value;
    for i=1:length(R_valuea)
        if (R_peak_indices_channel_2(i) == 0)
            R_valuea(i) = 0;
        end
    end
    R_valuea = R_valuea(find(R_valuea ~= 0));   
    R_peak_indices_channel_2a = R_peak_indices_channel_2((R_peak_indices_channel_2 ~= 0));
    fprintf('The length of R after is: %i\n',length(R_valuea));
    %fprintf('The length of R_indices after is: %i\n',length(R_peak_indices_channel_2a));   
    t(R_peak_indices_channel_2a)
    %clf(figure(13));
    figure(14)
    subplot(2,1,1)
    plot (t, x1/max(x1), t(R_peak_indices_channel_2a), R_valuea, 'r^');
    title('ECG Signal Post Channel 2 Processing');
    xlabel('Time(s)');
    ylabel('mV');
    legend('ECG','R');
    subplot(2,1,2)
    plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^');
    
    title('ECG All Detected Peaks');
    xlabel('Time(s)');
    ylabel('mV');
    legend('ECG','R');
    %plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
end

% Level 3 DETECTION: REFINES HEART BEAT DETECTION ACCURACY BY CHANNEL
% COMPARISON

% UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE LEVEL 3 PROCESSING
    %if (shouldPlot)
    %    fprintf('\nCombined Original: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0)));
    %end
% Combines both channels to refine beat detection
for i=1:length(R_peak_indices_combined)
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
    if (R_peak_indices_channel_1(i) == 0 && R_peak_indices_channel_2(i) == 0)
        R_peak_indices_combined(i) = 0;
    elseif (R_peak_indices_channel_1(i) ~= 0 && R_peak_indices_channel_2(i) == 0)
        % DELETE DEBUGGING
        %if (shouldPlot)
        %   fprintf('The peak val is: %f\n',R_peak_vals(i));
        %end
        % Uses the decision of the channel w/ the highest Detection.
        % Ensures that Ds is between 0 and 1
        % strength(Ds)
        Ds_1 = min(1, (R_peak_vals(i) - noise_lvl_channel_1) / (signal_lvl_channel_1 - noise_lvl_channel_1));
        Ds_1 = max(0, Ds_1);
        Ds_2 = min(1, (R_peak_vals(i) - noise_lvl_channel_2) / (signal_lvl_channel_2 - noise_lvl_channel_2));
        Ds_2 = max(0, Ds_2);
      
        if (Ds_1 > Ds_2)
            if(shouldPlot)
               %fprintf('Ds1: %f Ds2: %f Ds1 wins\n', Ds_1, Ds_2);
            end
            R_peak_indices_combined(i) = R_peak_indices_channel_1(i);
        else
            if(shouldPlot)
                %fprintf('Ds1: %f Ds2: %f Ds2 wins\n', Ds_1, Ds_2);
            end
            R_peak_indices_combined(i) = R_peak_indices_channel_2(i);
        end
    end
end
% UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 3 PROCESSING
    %if (shouldPlot)
        %fprintf('Combined Post: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0)));
    %end
    
% UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 4 PROCESSING
    %if (shouldPlot)
    %    fprintf('\n4th level Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0)));
    %end
% UNCOMMENT TO USE LEVEL 4 PROCESSING 
    %[R_peak_indices_channel_3, noise_lvl_channel_3, signal_lvl_channel_3] = fourth_level_process(threshold_3, R_peak_indices_channel_3);

    %if (shouldPlot)
    %    fprintf('4th level Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0)));
    %end
% Sets R values to zero which failed any of the previous phases
last_R_index = 0;
for i=1:length(R_peak_vals)
    if (R_peak_indices_channel_3(i) == 0)
        R_peak_vals(i) = 0;
    % Level 5 Detection: Refines heart beat detection by considering a heart
    % beat's refactory period 
    else
        % Filters out any R_values which happen too soon after a previous
        % beat detection
        current_R_index = R_peak_indices_channel_3(i);
        if (last_R_index ~= 0 && (t(current_R_index) - t(last_R_index)) < .200)
            %fprintf('Getting rid of a value\n');
            R_peak_vals(i) = 0;
            R_peak_indices_channel_3(i) = 0;
        % Updates the last index if the R_value is valid
        else
            % Updates the last index
            last_R_index = R_peak_indices_channel_3(i);
        end
    end
end
% Removes all zero values from both the indice and value array
R_peak_indices_channel_3 = R_peak_indices_channel_3(find(R_peak_indices_channel_3 ~= 0));
R_peak_vals = R_peak_vals(find(R_peak_vals ~= 0));   

%plots R peaks after all level processing
if (shouldPlot)
    %clf(figure(14));
    figure(15)
    subplot(2,1,1)
    plot (t, x1/max(x1), t(R_peak_indices_channel_3), R_peak_vals, 'r^');
    title('Final ECG Signal with R points');
    xlabel('Time(s)');
    ylabel('mV');
    legend('ECG','R');
    
    subplot(2,1,2)
    plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^');
    title('ECG All Detected Peaks');
    xlabel('Time(s)');
    ylabel('mV');
    legend('ECG','R');
    %plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
end


%xlim([1 3]);

%plot (t(R_peak_indices_channel_3) ,R_peak_vals, 'r^');
%plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
%xlabel('Seconds'); ylabel('Normalized Magnitude');title('R peaks');

%%plot(R_peak_vals, 'r+');

% CALCULATES HEART RATE
% NOTE: This will assume that only 1-min windows of the EKG are sent in as
% the data type
R_peak_count = 0;

% Counts how many R peak counts are found in N seconds
for i=1:length(R_peak_indices_channel_3)
    % Counts how many R wave peaks are found in a 
    R_peak_count = R_peak_count + 1;
end

heart_rate = (R_peak_count / sample_size) * 60;
%heart_rate = R_peak_count;

end

% RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE
% THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS
function [meets_deviance_req] = meets_deviance_threshold(hr_value, signal_level, pos_deviance_threshold, neg_deviance_threshold)
    %Accounts for the first signal value
    if (signal_level == 0)
        meets_deviance_req = 1;
        return;
    end
    raw_deviance = (hr_value - signal_level) / signal_level;
    deviance = abs(raw_deviance);
    % APPLIES CHECK 
    if (raw_deviance < 0)
        if (deviance < neg_deviance_threshold)
            meets_deviance_req = 1;
        else
            meets_deviance_req = 0;
        end
    else
        if (deviance < pos_deviance_threshold)
            meets_deviance_req = 1;
        else
            meets_deviance_req = 0;
        end
    end
end

%DUAL THRESHOLD PROCESSSING
% Filters out R_peaks which don't meet the threshold reqs
    function [indices, noise_lvl, signal_lvl] = dualThreshold(threshold, indices, max_voltage, pos_deviance_threshold, neg_deviance_threshold)
        noise_sum = 0; signal_sum = 0;
        noise_count = 0; signal_count = 0;
        noise_lvl = 0; signal_lvl = 0;
        for index=1:length(R_peak_vals)
               % DELETE AFTER DEBUGGING
               %if (shouldPlot && channel == 2)
               %    fprintf('The peak val is: %f\n',R_peak_vals(index));
               %end
           if (R_peak_vals(index) * max_voltage > threshold) 
               %fprintf('mv: %f. Threshold is: %f\n', R_peak_vals(index) * max_voltage, threshold);
               %R_peak_vals(index)
               % Filters out any signal value which exceeds the allowed deviance from
               % the average signal value 
               if (~meets_deviance_threshold(R_peak_vals(index), signal_lvl, pos_deviance_threshold, neg_deviance_threshold))
                  %fprintf('%f, %f Does not meet the deviance threshold\n', R_peak_vals(index), signal_lvl);
                   % Sets all the indices which R_vals don't meet the threshold to 0
                   indices(index) = 0; 
                   % Updates the average noise signal lvl
                   noise_sum = noise_sum  + R_peak_vals(index);
                   noise_count = noise_count + 1;
                   % Calculates the noise level
                   noise_lvl = noise_sum / noise_count;
                   continue;
               end
               % DELETE AFTER DEBUGGING
               %if (shouldPlot && channel == 2)
               %   fprintf('The peak val is: %f\n',R_peak_vals(index));
               %end
                % Updates the average signal lvl
               signal_sum = signal_sum + R_peak_vals(index);
               signal_count = signal_count + 1;
               % Calculates the signal level
               signal_lvl = signal_sum / signal_count;
           else
               % Sets all the indices which R_vals don't meet the threshold to 0
               indices(index) = 0; 
               % Updates the average noise signal lvl
               noise_sum = noise_sum  + R_peak_vals(index);
               noise_count = noise_count + 1;
               % Calculates the noise level
               noise_lvl = noise_sum / noise_count;
           end          
        end
    end
    
    % Level 4 Detection: Reduces FNs by comparing Ds(detection strength) against
% the threshold
%R_peak_indices_combined
% FOURTH LEVEL PROCESSING TO REDUCE FNs
    function [indices, noise_lvl, signal_lvl] = fourth_level_process(threshold, indices)
        noise_sum = 0; signal_sum = 0;
        noise_count = 0; signal_count = 0;
        noise_lvl = 0; signal_lvl = 0;
        for i=1:length(indices)
           if (R_peak_indices_combined(i) == 0)
               % Calculates the Detection strength
               Ds_3 = min(1,(R_peak_vals(i) - noise_lvl) / (signal_lvl - noise_lvl));
               % Ensures that the signal strength is between 0 and 1
               Ds_3 = max(0, Ds_3);
               
               % Changes a non-beat to a beat if channel 3's detection strength is
               % greater than its threshold
               if (Ds_3 > threshold)
                   %fprintf('Threshold %f. Ds: %f Changing %f a non-beat to a beat\n', threshold, Ds_3, R_peak_vals(i) *max_voltage);
                   % Updates the average signal lvl
                   signal_sum = signal_sum + R_peak_vals(i);
                   signal_count = signal_count + 1;
                   % Calculates the signal level
                   signal_lvl = signal_sum / signal_count;
                   % REMOVE AFTER TESTING
                   indices(i) = 0;
               else
                   % Sets all the indices which R_vals don't meet the threshold to 0
                   indices(i) = 0; 
                   %fprintf('Setting the indice to zero\n');
                   % Updates the average noise signal lvl
                   noise_sum = noise_sum  + R_peak_vals(i);
                   noise_count = noise_count + 1;
                   % Calculates the noise level
                   noise_lvl = noise_sum / noise_count;
               end
           else
                   % Updates the average signal lvl
                   signal_sum = signal_sum + R_peak_vals(i);
                   signal_count = signal_count + 1;
                   % Calculates the signal level
                   signal_lvl = signal_sum / signal_count;
           end
        end
    end    