function [ heart_rate ] = heart_rate_emulator( data,fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size, averageHR)
%------ Heart Rate Detection Emulator ----------
%  Emulates a live EKG data stream by buffering fs * sample_time data samples.
%  Effectively feeds chunks of EKG data to Heart rate algorithm to reflect what 
%  will happen in Hardware
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
%   sample_time             length in time(s) over which HR is estimated
%   
%   averageHR               the expected average HR over the sample_time. Used for plotting
%
% Outputs:
%   heart_rate  Estimated heart rate in beats per minute
%
% % % % % % % % % % % % % % % %
%
% Gbenga Badipe




% RESETS MATLAB OUTPUT
% clc
% close all
tic
%data - EKG data
%fs - sampling rate
%threshold_1 - threshold for filtering out peaks for channel 1
%threshold_2 - threshold for filtering out peaks for channel 2
%threshold_3 - threshold for filtering out peaks for channel 3
%pos_deviance_threshold - the amount a peak can deviate in the positive
%direction
%neg_deviance_threshold - the amount a peak can deviate in the negative
%direction
%sample_size - length in time(s) over which HR is estimated

% Applies bandstop to remove 50-60Hz hum
preprocessingFilterSpec = fdesign.bandstop('Fp1,Fst1,Fst2,Fp2,Ap1,Ast,Ap2',43,50,60,68,.5,60,1,fs); 
preprocessingFilter = design(preprocessingFilterSpec,'equiripple');
% Plots the frequency of 
% freqz(preprocessingFilter);
data = filter(preprocessingFilter, data);

Fc  = 16;
low_pass_order = 2;   % FIR filter order
low_pass_spec = fdesign.lowpass('N,Fc',low_pass_order,Fc,fs);
low_pass = design(low_pass_spec,'window','window',@hamming);
data = filter(low_pass, data);
% Decimates the signal to 200Hz
% data = resample(data, 3, 2);
 datar = iddata(data,[],1/fs);
 data = idresamp(datar, fs/300);
 data = data.y;
 fs = 300; % Updates fs to the new value
%[GB] Ensures the the input args are of the correct data type
Fixed_Point_Properties_signed = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed', true);
F_signed = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
% Applies front end filters
[filtered_full_signal, dc_offset] = front_end_filters(data, fs);

% Offsets DC offset
filtered_full_signal = double(filtered_full_signal) - dc_offset;
indata = fi(filtered_full_signal, Fixed_Point_Properties_signed, F_signed);

% Normalizes the signal 
% indata = divide(Fixed_Point_Properties_signed, indata, max(abs(indata)));

% indatadouble = double(indata);
% a = fi(4, Fixed_Point_Properties_signed, F_signed);
% b = fi(3, Fixed_Point_Properties_signed, F_signed);
% c = fi(1, Fixed_Point_Properties_signed, F_signed);
% part1 = divide(Fixed_Point_Properties_signed, a, b);
% part2 = abs(b * (part1 - c) - c);

% figure(34)
% fprintf('Min, Median, and Mean of original signal\n');
% min(filtered_full_signal)
% median(filtered_full_signal)
% mean(filtered_full_signal)
% plot(filtered_full_signal);

% fprintf('Min, Median, and Mean of fixed point signal\n');
% min(indatadouble)
% median(indatadouble)
% mean(indatadouble)

% figure(36)
% plot(indatadouble);

% Holds the length of the signal
N = length(data);
window_size =  sample_size * fs;
step_size = fs;%[GB]Step size should be one second
num_windows = floor((N - window_size)/step_size) + 1;
heart_rates = [];
t = [];
%t = [0:N-1]/fs;        % time index

for step=0:(num_windows - 1)
    begin_index = 1 + step_size*step;%[GB]N1 represents the beginning index of the window 
    begin_index = min(N, begin_index);
    end_index = begin_index + window_size-1;%[GB]N2 demarcates where the window ends
    end_index = min(N, end_index);
    t = [t (step_size + step * step_size)/fs];
    %begin_index = (index - 1) * window_size + 1;
    %end_index = begin_index + (window_size - 1);
    sample_size_t = length(indata(begin_index:end_index)) / fs;
%     fprintf('Min, Median, and Mean of original signal segment\n');
    
%     filtered_signal = filtered_full_signal(begin_index:end_index);
%     figure(37)
%     plot(filtered_signal)
    
%     min(filtered_signal)
%     median(filtered_signal)
%     mean(filtered_signal)
    
%      fprintf('Min, Median, and Mean of fixed point signal segment\n');
%     figure(38)
%     plot(indatadouble(begin_index:end_index)); 
%     min(indatadouble(begin_index:end_index))
%     median(indatadouble(begin_index:end_index))   
%     mean(indatadouble(begin_index:end_index))

    
    if (step == 0)
%         heart_rate = heart_rate_official_cport(data(begin_index:end_index), fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size_t, 1);
        heart_rate = heart_rate_official_cport(indata(begin_index:end_index), uint32(fs), fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), uint32(sample_size_t), uint32(1));

        heart_rates = [heart_rates heart_rate];
    else
%         heart_rate = heart_rate_official_cport(data(begin_index:end_index), fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size_t, 0);
        heart_rate = heart_rate_official_cport(indata(begin_index:end_index), uint32(fs), fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), uint32(sample_size_t), uint32(0));
        heart_rates = [heart_rates heart_rate];
    end
%     break;
end
toc
    
%clf(figure(2));
figure(20)
% Offsets each time value by the sample size
t = t + sample_size;
scatter(t, heart_rates);

% Offsets the x-axis and extends the y-axis
axis([sample_size, t(length(t)), 30, 250])
% grid on
hold on
% Plots the average HR on top of the graph
x = [0, max(t)];
y = [averageHR, averageHR];
plot(x, y, 'r', 'LineWidth', 1);
% Plots the Error bars of HR on top of the graph
x = [0, max(t)];
% +/- 5 error bars
y = [averageHR + 5, averageHR + 5];
plot(x, y, '-.m', 'LineWidth', 1);
y = [averageHR - 5, averageHR - 5];
plot(x, y, '-.m', 'LineWidth', 1);

% +/- 15 error bars
y = [averageHR + 15, averageHR + 15];
plot(x, y, '-.g', 'LineWidth', 1);
y = [averageHR - 15, averageHR - 15];
plot(x, y, '-.g', 'LineWidth', 1);

% +/- 30 error bars
% y = [averageHR + 30, averageHR + 30];
% plot(x, y, '-.k', 'LineWidth', 1);
% y = [averageHR - 30, averageHR - 30];
% plot(x, y, '-.k', 'LineWidth', 1);

title('Average Heart Rates');
xlabel('Time(s)');
ylabel('Heart Rate(bpm)');
% legend('Heart Rate(bpm)','Avg HR', '+5','-5', '+15', '- 15', '+30', '-30' )
% legend('Heart Rate(bpm)','Avg HR', '+5','-5', '+15', '- 15', 'Location', 'Best');

