%#codegen
function [heart_rate, last_hr_delta] = heart_rate_official_cport(data, fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_time, shouldOutput, prev_hr_delta)  
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

Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
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

% asserts that input parameters are of specific fixed point parameters
assert(isequal(numerictype(data), Fixed_Point_Properties_signed) && isequal(fimath(data), F_signed));
% assert(isequal(numerictype(fs),Fixed_Point_Properties) && isequal(fimath(fs), F));
assert(isequal(numerictype(threshold_1),Fixed_Point_Properties) && isequal(fimath(threshold_1), F));
assert(isequal(numerictype(threshold_2),Fixed_Point_Properties) && isequal(fimath(threshold_2), F));
assert(isequal(numerictype(threshold_3),Fixed_Point_Properties) && isequal(fimath(threshold_3), F));
assert(isequal(numerictype(pos_deviance_threshold),Fixed_Point_Properties) && isequal(fimath(pos_deviance_threshold), F));
assert(isequal(numerictype(neg_deviance_threshold),Fixed_Point_Properties) && isequal(fimath(neg_deviance_threshold), F));
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
assert (all ( size (data) == [1500 1] ));
% assert (~isscalar(data));

x1 = data;
% figure(30)
% plot(data);
N = length (x1);       % Signal length
% t = (0:N-1)/fs;        % time index
% NFFT = 2 ^(ceil(log2(N))); % Next power of 2 from length of the signal

% Assures that the number of samples sent in aren't greater than the
% specified sample size
assert(divide(Fixed_Point_Properties, fi(N, Fixed_Point_Properties, F), fi(fs, Fixed_Point_Properties, F)) >= sample_time);

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
%x1 = x1 - mean (x1 );    % cancel DC conponents
% x1 = x1/ max( abs(x1 )); % normalize to one
max_x = fi(max(abs(x1)), Fixed_Point_Properties_signed, F_signed);
% for i=1:length(x1)
%     divide(Fixed_Point_Properties_signed, x1(i), max_x) % normalize to one
% end
x1 = divide(Fixed_Point_Properties_signed, x1, max_x); % normalize to one
assert(isequal(numerictype(x1),Fixed_Point_Properties_signed) && isequal(fimath(x1), F_signed));


% UNCOMMENT TO SEE PLOT OF EKG AFTER NORMALIZATION AND REMOVAL OF DC DRIFT
    if(shouldOutput)
        %figure(3)
        %subplot(2,1,1)
        %plot(t,x1)
        %xlabel('second');ylabel('Volts');title(' ECG Signal after cancellation DC drift and normalization')
        %subplot(2,1,2)
        %plot(t(200:600),x1(200:600))
        %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
        %xlim([1 3]);
    end
 % UNCOMMENT TO SEE FFT OF ORIGINAL EKG
%     if (shouldOutput)
        %Plots the fft of the original signal
        %transform=fft(x1,NFFT)/N;% Transform from discrete values to the frequency domain
        %transform=transform;
        %windows=[windows,abs(transform)];
        %freq = fs/2*linspace(0,1,NFFT/2+1);%Frequency index
     %   fprintf('Plotting\n');
        %figure(2) 
        %plot(freq,2*abs(transform(1:NFFT/2+1)));
        %title('FFT EKG Signal');
        %xlabel('Frequency (Hz)');
        %ylabel('|X(f)|');
%     end
    
%------ MOST FILTERING NOW OCCURS IN ANALOG SEE 'front_end_filters.m' FOR EMULATED FRONT END FILTERS


%LOW PASS FILTERING

% LPF (1-z^-6)^2/(1-z^-1)^2
%b=[1 0 0 0 0 0 -2 0 0 0 0 0 1];
%a=[1 -2 1];


%h_LP=filter(b,a,[1 zeros(1,12)]); % transfer function of LPF
%if(shouldOutput)
    %figure(21)
    %freqz(b,a,1000,fs)
%end

% x2 = conv (x1 ,h_LP);
% Fc  = 16;
% low_pass_order = 2;   % FIR filter order
% low_pass_spec = fdesign.lowpass('N,Fc',low_pass_order,Fc,fs);
% low_pass = design(low_pass_spec,'window','window',@hamming);
% x2 = filter(low_pass, x1);
%x2 = x2 (6+[1: N]); %cancle delay
% x2 = x2/ max( abs(x2 )); % normalize , for convenience .

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
    %if(shouldOutput)
        % Takes the fft of the signal %
        %transform=fft(x2,NFFT)/N;% Transform from discrete values to the frequency domain

        % Plots the fft of the filtered signal
    %   transform=transform;
        %windows=[windows,abs(transform)];
        %freq = fs/2*linspace(0,1,NFFT/2+1);%Frequency index
    %    fprintf('Plotting\n');
        %figure(4)
        %plot(freq,2*abs(transform(1:NFFT/2+1)));
        %title('FFT LP Filtered EKG Signal');
        %xlabel('Frequency (Hz)');
        %ylabel('|X(f)|');
    %end

%HIGH PASS FILTERING

% HPF = Allpass-(Lowpass) = z^-16-[(1-z^-32)/(1-z^-1)]
%b = [-1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 32 -32 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1];
%a = [1 -1];

%h_HP=filter(b,a,[1 zeros(1,32)]); % impulse response iof HPF
%if(shouldOutput)
%     freqz(h_HP);
%end
% Fc  = 5;
% high_pass_order = 2;   % FIR filter order
% high_pass_spec = fdesign.highpass('N,Fc',high_pass_order,Fc,fs);
% high_pass = design(high_pass_spec,'window','window',@hamming);
%x3 = conv (x2 ,h_HP);
%x3 = x3 (16+[1: N]); %cancle delay
% x3 = filter(high_pass, x2);
% x3 = x3/ max( abs(x3 ));
    

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
%if(shouldOutput)
    % Takes the fft of the signal %
    %transform=fft(x3,NFFT)/N;% Transform from discrete values to the frequency domain

    % Plots the fft of the filtered signal
  %  transform=transform;
    %windows=[windows,abs(transform)];
    %freq = fs/2*linspace(0,1,NFFT/2+1);%Frequency index
    %fprintf('Plotting\n');
    %figure(6)
    %plot(freq,2*abs(transform(1:NFFT/2+1)));
    %title('FFT HP Filtered EKG Signal');
    %xlabel('Frequency (Hz)');
    %ylabel('|X(f)|');
%end

%DERIVATIVE FILTER

% Make impulse response
%h = [-1 -2 0 2 1]/8;
% Apply filter
%x4 = conv (x1 ,h);
%x4 = x4 (2+ (1: N));
%x4 = x4/ max( abs(x4 ));

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

x5 = fi(x1.^2, F);

% assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F));
%x5 = mpower(x1, 2);
%x5 = x5/ max( abs(x5 ));

% figure(24)
% plot(x5);

% UPDATES FIXED POINT DEFINITION TO BE UNSIGNED
% assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F));
Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);



% Changes the fixed point properties of the data to be unsigned after
% squaring
x5 = fi(x5, Fixed_Point_Properties, F);
% Normalizes the result of the squaring
x5 = divide(Fixed_Point_Properties, x5, max( abs(x5 ))); % normalize to one
assert(isequal(numerictype(x5),Fixed_Point_Properties) && isequal(fimath(x5), F));

% UNCOMMENT TO SEE PLOT OF EKG AFTER SQUARING
%     if(shouldOutput)
        %figure(8)
        %subplot(2,1,1)
        %plot([0:length(x5)-1]/fs,x5)
        %xlabel('second');ylabel('Volts');title(' ECG Signal Squaring')
        %subplot(2,1,2)
        %plot(t(200:600),x5(200:600))
        %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
        %xlim([1 3]);
%     end
%MOVING WINDOW INTEGRATION

% Make impulse response
h = divide(Fixed_Point_Properties, fi(ones (1, 7), Fixed_Point_Properties, F), 7);

% Delay = 15; % Delay in samples

% Apply filter
x6 = fi(conv (x5 ,h), Fixed_Point_Properties, F);
x6 = x6 (3+(1: N));
% plot(x6);
% return;
% Normalizes the signal 
% x6 = x6 / max( abs(x6 ));
x6 = divide(Fixed_Point_Properties, x6, max( abs(x6 ))); % normalize to one
% figure(25)
% plot(x6);
assert(isequal(numerictype(x6),Fixed_Point_Properties) && isequal(fimath(x6), F));

% UNCOMMENT TO SEE PLOT OF EKG AFTER A MWI IS APPLIED
%     if(shouldOutput)
        %figure(9)
        %subplot(2,1,1)
        %plot([0:length(x6)-1]/fs,x6)
        %xlabel('second');ylabel('Volts');title(' ECG Signal after Averaging')
        %subplot(2,1,2)
        %plot(t(200:600),x6(200:600))
        %xlabel('second');ylabel('Volts');title(' ECG Signal 1-3 second')
        %xlim([1 3]);
%     end
    
%FIND QRS POINTS. NOTE: THE PEAK FINDING IS DIFFERENT THAN PAN-TOMPKINS ALGORITHM

%figure(7)
%subplot(2,1,1)
max_h = max(x6);
max_voltage = max_h;
assert(isequal(numerictype(max_voltage),Fixed_Point_Properties) && isequal(fimath(max_voltage), F));

thresh = mean (x6 );
% Outputs an array with each value indicating whether the value at that
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

%  Finds(the indices) all the heart beats which are preceded by a non-beat
left = find(diff([0 poss_reg])==1); % Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1

% Finds all the heart beats where  the heart beats are proceeded by a
% non-beat
right = find(diff([poss_reg 0])==-1);

%left=left-(6+16);  % cancel delay because of LP and HP
%right=right-(6+16);% cancel delay because of LP and HP
[~, left_num_cols] = size(left);
R_value = fi(zeros(1, left_num_cols), Fixed_Point_Properties, F);
R_loc = zeros(1, left_num_cols);
for i=1:length(left)  
    [R_value(i) R_loc(i)] = max( x1(left(i):right(i)) );
    R_loc(i) = R_loc(i)-1+left(i); % add offset

%     [Q_value(i) Q_loc(i)] = min( x1(left(i):R_loc(i)) );
%     Q_loc(i) = Q_loc(i)-1+left(i); % add offset

%     [S_value(i) S_loc(i)] = min( x1(left(i):right(i)) );
%     S_loc(i) = S_loc(i)-1+left(i); % add offset

end
% there is no selective wave
R_loc=R_loc(R_loc~=0);
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
[~, num_cols_indices] = size(R_peak_indices);

% Creates a copy of the indices which store the indices where the 'R' peaks
% lie

% NEEDS OPTIMIZATION. NEED TO AVOID COPYING LARGE ARRAYS 
R_peak_indices_channel_1 = R_peak_indices(1:num_cols_indices); 
R_peak_indices_channel_2 = R_peak_indices(1:num_cols_indices);
% R_peak_indices_channel_3 = R_peak_indices(1:num_cols_indices);
R_peak_indices_combined = R_peak_indices(1:num_cols_indices); % REPLACE THIS WITH A ZEROS ARRAY

% UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE CHANNEL 1 PROCESSING
%     if (shouldOutput)
%         fprintf('Channel 1 Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0)));
%     end

[R_peak_indices_channel_1, noise_lvl_channel_1, signal_lvl_channel_1] = dualThreshold(R_peak_vals, threshold_1, uint32(R_peak_indices_channel_1), max_voltage, pos_deviance_threshold, neg_deviance_threshold, shouldOutput);
[R_peak_indices_channel_2, noise_lvl_channel_2, signal_lvl_channel_2] = dualThreshold(R_peak_vals, threshold_2, uint32(R_peak_indices_channel_2), max_voltage, pos_deviance_threshold, neg_deviance_threshold, shouldOutput);

% Ensures that noise and signal levels are fixed point
assert(isfi(noise_lvl_channel_1));assert(isfi(signal_lvl_channel_1));
assert(isfi(noise_lvl_channel_2));assert(isfi(signal_lvl_channel_2));

assert(isequal(numerictype(noise_lvl_channel_1),Fixed_Point_Properties) && isequal(fimath(noise_lvl_channel_1), F));
assert(isequal(numerictype(noise_lvl_channel_2),Fixed_Point_Properties) && isequal(fimath(noise_lvl_channel_2), F));

assert(isequal(numerictype(signal_lvl_channel_1),Fixed_Point_Properties) && isequal(fimath(signal_lvl_channel_1), F));
assert(isequal(numerictype(signal_lvl_channel_2),Fixed_Point_Properties) && isequal(fimath(signal_lvl_channel_2), F));


% UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER CHANNEL 1 PROCESSING
%     if (shouldOutput)
%         fprintf('Channel 1 Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_1 ~= 0)));
%     end


% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE FIRST CHANNEL

% if (shouldOutput)
    % Sets R values to zero which failed any of the previous phases 
    %R_valuea = R_value;
    %for i=1:length(R_valuea)
    %    if (R_peak_indices_channel_1(i) == 0)
    %        R_valuea(i) = 0;
    %    end
    %end
    %R_valuea = R_valuea(R_valuea ~= 0);   
    %R_peak_indices_channel_1a = R_peak_indices_channel_1((R_peak_indices_channel_1 ~= 0));
    %fprintf('The length of R after is: %i\n',length(R_valuea));
    %fprintf('The length of R_indices after is: %i\n',length(R_peak_indices_channel_1a));   
%     t(R_peak_indices_channel_1a);
    %clf(figure(13));
    %figure(13)
    %subplot(2,1,1)
    %plot (t, x1/max(x1), t(R_peak_indices_channel_1a), R_valuea, 'r^');
    %title('ECG Signal Post Channel 1 Processing');
    %xlabel('Time(s)');
    %ylabel('mV');
    %legend('ECG','R');
    
    %subplot(2,1,2)
    %plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^');
    %title('ECG All Detected Peaks');
    %xlabel('Time(s)');
    %ylabel('mV')
    %plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
% end
% UNCOMMENT TO SEE PLOT OF EKG AFTER BEING PASSED THROUGH THE SECOND CHANNEL

% if (shouldOutput)
    % Sets R values to zero which failed any of the previous phases 
    %R_valuea = R_value;
    %for i=1:length(R_valuea)
    %    if (R_peak_indices_channel_2(i) == 0)
    %        R_valuea(i) = 0;
    %    end
    %end
    %R_valuea = R_valuea(R_valuea ~= 0);   
    %R_peak_indices_channel_2a = R_peak_indices_channel_2((R_peak_indices_channel_2 ~= 0));
    %fprintf('The length of R after is: %i\n',length(R_valuea));
    %fprintf('The length of R_indices after is: %i\n',length(R_peak_indices_channel_2a));   
%     t(R_peak_indices_channel_2a);
    %clf(figure(13));
    %figure(14)
    %subplot(2,1,1)
    %plot (t, x1/max(x1), t(R_peak_indices_channel_2a), R_valuea, 'r^');
    %title('ECG Signal Post Channel 2 Processing');
    %xlabel('Time(s)');
    %ylabel('mV');
    %legend('ECG','R');
    %subplot(2,1,2)
    %plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^');
    
    %title('ECG All Detected Peaks');
    %xlabel('Time(s)');
    %ylabel('mV');
    %legend('ECG','R');
    %plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
% end

% Level 3 DETECTION: REFINES HEART BEAT DETECTION ACCURACY BY CHANNEL
% COMPARISON

% UNCOMMENT TO SEE THE NUMBER OF PEAKS BEFORE LEVEL 3 PROCESSING
    %if (shouldOutput)
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
        %if (shouldOutput)
        %   fprintf('The peak val is: %f\n',R_peak_vals(i));
        %end
        % Uses the decision of the channel w/ the highest Detection.
        % Ensures that Ds is between 0 and 1
        % strength(Ds)
%         signal_lvl_channel_1
%         noise_lvl_channel_1
%           fprintf('In here');
%           diff1 = ((R_peak_vals(i) - noise_lvl_channel_1) * 100) / (signal_lvl_channel_1 - noise_lvl_channel_1)
%           diff2 = ((R_peak_vals(i) - noise_lvl_channel_2) * 100) / (signal_lvl_channel_2 - noise_lvl_channel_2)
%         minlog(diff1)
%         minlog(diff2)
        % If the delta between the peak value and the noise level is < 0
        % then due to unsigned fixed point rules this value is 0 which is what we
        % want anyways so this proves to be a useful overflow case.
        Ds_1 = min(1, divide(Fixed_Point_Properties, ((R_peak_vals(i) * 100 - noise_lvl_channel_1 * 100)), (signal_lvl_channel_1 * 100 - noise_lvl_channel_1 * 100)));
        Ds_1 = max(0, Ds_1);
        Ds_2 = min(1, divide(Fixed_Point_Properties, ((R_peak_vals(i) * 100 - noise_lvl_channel_2 * 100)), (signal_lvl_channel_2 * 100 - noise_lvl_channel_2 * 100)));
        Ds_2 = max(0, Ds_2);
      
        if (Ds_1 > Ds_2)
            %if(shouldOutput)
               %fprintf('Ds1: %f Ds2: %f Ds1 wins\n', Ds_1, Ds_2);
            %end
            R_peak_indices_combined(i) = R_peak_indices_channel_1(i);
        else
            %if(shouldOutput)
                %fprintf('Ds1: %f Ds2: %f Ds2 wins\n', Ds_1, Ds_2);
            %end
            R_peak_indices_combined(i) = R_peak_indices_channel_2(i);
        end
    end
end
% UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 3 PROCESSING
%     if (shouldOutput)
%         fprintf('Combined Post: There are %i non-zero values\n',length(find(R_peak_indices_combined ~= 0)));
%     end
    
% Grabs the result of both channels    
R_peak_indices_channel_3 = R_peak_indices_combined;

% UNCOMMENT TO SEE THE NUMBER OF PEAKS AFTER LEVEL 4 PROCESSING
    %if (shouldOutput)
    %    fprintf('\n4th level Original: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0)));
    %end
% UNCOMMENT TO USE LEVEL 4 PROCESSING 
    %[R_peak_indices_channel_3, noise_lvl_channel_3, signal_lvl_channel_3] = fourth_level_process(threshold_3, R_peak_indices_channel_3);

    %if (shouldOutput)
    %    fprintf('4th level Post: There are %i non-zero values\n',length(find(R_peak_indices_channel_3 ~= 0)));
    %end
    
% LEVEL 5 DETECTION: 
%Refines heart beat detection by considering a heart beat's refactory period    

% Sets R values to zero which failed any of the previous phases
last_R_index = fi(0, Fixed_Point_Properties, F);
% Sample time delta is based off the Fs passed in
time_delta = divide(Fixed_Point_Properties, 1, 300);

% Heart beat delta sum is the summation of the time between heart beats. It's used for
% HR calculation
heart_beat_current_sum = fi(0, Fixed_Point_Properties, F);
heart_beat_last_sum = fi(0, Fixed_Point_Properties, F);


% Heart beat count is the amount of heart beats detected
heart_beat_count = fi(0, Fixed_Point_Properties, F);

for i=1:length(R_peak_vals)
    if (R_peak_indices_channel_3(i) == 0)
        R_peak_vals(i) = 0;
     % Filters out any R_values which happen too soon after a previous
     % beat detection. Updates the average HR delta which will be used to
     % calculate HR
    else
        % Updates the index
        current_R_index = fi(R_peak_indices_channel_3(i), Fixed_Point_Properties, F);
        
        %Filters out any R_values which happen too soon after a previous
        % beat detection.
        if (last_R_index ~= 0 && ((current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta) < .200)
            R_peak_vals(i) = 0;
            R_peak_indices_channel_3(i) = 0;
         
        % Initializes the first delta which is when the first heart
        % beat occurs
        elseif(last_R_index == 0)
            assert(isequal(numerictype(prev_hr_delta),Fixed_Point_Properties) && isequal(fimath(prev_hr_delta), F));
            heart_beat_delta = (current_R_index - 1) * time_delta + prev_hr_delta;
            heart_beat_current_sum = heart_beat_delta + 0;
            
            % Updates the last index
            last_R_index = fi(R_peak_indices_channel_3(i), Fixed_Point_Properties, F);
            
            % Updates the heart beat count
            heart_beat_count = heart_beat_count + 1;
            
        % Updates the last index if the R_value is valid
        else   
              heart_beat_current_sum = heart_beat_current_sum + (current_R_index - 1) * time_delta;
              heart_beat_last_sum = heart_beat_last_sum + (last_R_index - 1) * time_delta;
%             heart_beat_delta = (current_R_index - 1) * time_delta - (last_R_index - 1) * time_delta;
%             heart_beat_current_sum = heart_beat_current_sum + heart_beat_delta;
            % Updates the heart beat count
            heart_beat_count = heart_beat_count + 1;
            
            % Updates the last index
            last_R_index = fi(R_peak_indices_channel_3(i), Fixed_Point_Properties, F);
            
        end
    end
end

last_hr_delta = fi(sample_time, Fixed_Point_Properties, F) - last_R_index * time_delta;
% Removes all zero values from both the indice and value array
R_peak_indices_channel_3 = R_peak_indices_channel_3(R_peak_indices_channel_3 ~= 0);
% R_peak_vals = R_peak_vals(R_peak_vals ~= 0);

%plots R peaks after all level processing
% if (shouldOutput)
    %clf(figure(14));
    %figure(15)
    %subplot(2,1,1)
    %plot (t, x1/max(x1), t(R_peak_indices_channel_3), R_peak_vals, 'r^');
    %title('Final ECG Signal with R points');
    %xlabel('Time(s)');
    %ylabel('mV');
    %legend('ECG','R');
    
    %subplot(2,1,2)
    %plot (t, x1/max(x1), t(R_peak_indices), R_value, 'r^');
    %title('ECG All Detected Peaks');
    %xlabel('Time(s)');
    %ylabel('mV');
    %legend('ECG','R');
    %plot (t, x1/max(x1) , t(R_peak_indices_channel_3) ,R_peak_vals , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
% end


%xlim([1 3]);

%plot (t(R_peak_indices_channel_3) ,R_peak_vals, 'r^');
%plot (t,x1/max(x1) , t(R_loc) ,R_value , 'r^', t(S_loc) ,S_value, '*',t(Q_loc) , Q_value, 'o');
%xlabel('Seconds'); ylabel('Normalized Magnitude');title('R peaks');

%%plot(R_peak_vals, 'r+');

% CALCULATES HEART RATE
% NOTE: This will assume that only 1-min windows of the EKG are sent in as
% the data type
R_peak_count = fi(0, Fixed_Point_Properties, F);

% Counts how many R peak counts are found in N seconds
for i=1:length(R_peak_indices_channel_3)
    % Counts how many R wave peaks are found in a 
    R_peak_count = R_peak_count + 1;
end
% R_peak_count
% heart_rate = divide(Fixed_Point_Properties, R_peak_count, sample_time) * 60;


% CALCULATES HEART RATE USING AVERAGE TIME TIME DELTAS BETWEEN BEATS
%   Provides less quantized HR values

% Produces a result which is avg heart beat delta(s)
heart_beat_delta_sum = heart_beat_current_sum - heart_beat_last_sum;
% heart_beat_delta_sum = heart_beat_current_sum;
heart_rate  = divide(Fixed_Point_Properties, heart_beat_delta_sum, heart_beat_count);
% Inverses it to produce HBPM
heart_rate = divide(Fixed_Point_Properties, 1, heart_rate);
heart_rate = heart_rate * 60;

end

% RETURNS TRUE IF THE INPUT SIGNAL VALUE MEETS THE DEVIANCE REQS. NOTE
% THE THRESHOLD VALUE CHANGES BASED ON WHETHER DEVIANCE IS NEG OR POS
function [meets_deviance_req] = meets_deviance_threshold(hr_value, signal_level, pos_deviance_threshold, neg_deviance_threshold)
        Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
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
            meets_deviance_req = 0;
        end
    else
        if (deviance < pos_deviance_threshold * 100)
            meets_deviance_req = 1;
        else
            meets_deviance_req = 0;
        end
    end
end

%DUAL THRESHOLD PROCESSSING
% Filters out R_peaks which don't meet the threshold reqs
    function [indices, noise_lvl, signal_lvl] = dualThreshold(R_peak_vals, threshold, indices, max_voltage, pos_deviance_threshold, neg_deviance_threshold, shouldOutput)
        Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
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
        
        for index=1:length(R_peak_vals)
               % DELETE AFTER DEBUGGING
               %if (shouldOutput && channel == 2)
               %    fprintf('The peak val is: %f\n',R_peak_vals(index));
               %end
           if (R_peak_vals(index) * max_voltage > threshold) 
               %fprintf('mv: %f. Threshold is: %f\n', R_peak_vals(index) * max_voltage, threshold);
               %R_peak_vals(index)
               
               % Filters out any signal value which exceeds the allowed deviance from
               % the average signal value 
               if (~meets_deviance_threshold(R_peak_vals(index), signal_lvl, pos_deviance_threshold, neg_deviance_threshold) && index > 4)
%                     if(shouldOutput)
%                           fprintf('Does not meet the deviance threshold\n');
%                           R_peak_vals(index)
%                           signal_lvl
%                     end

                   % Sets all the indices which R_vals don't meet the threshold to 0
                   indices(index) = 0; 
                   
                   % Updates the average noise signal lvl
                   noise_sum = noise_sum  + R_peak_vals(index);
                   noise_count = noise_count + 1;
                   
                   % Calculates the noise level
%                    noise_lvl = noise_sum / noise_count;
                   noise_lvl = divide(Fixed_Point_Properties, noise_sum, noise_count);
                   continue;
               end
               % DELETE AFTER DEBUGGING
               %if (shouldOutput && channel == 2)
               %   fprintf('The peak val is: %f\n',R_peak_vals(index));
               %end
               
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
%                noise_lvl = noise_sum / noise_count;
               noise_lvl = divide(Fixed_Point_Properties, noise_sum, noise_count);

           end          
        end
    end  