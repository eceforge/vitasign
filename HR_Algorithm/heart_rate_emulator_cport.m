
function [ heart_rate ] = heart_rate_emulator_cport( data,fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, toss_thresh, reset_thresh, neg_peak_deviance_threshold, sample_size, averageHR)

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
%   toss_thresh             number of peak deltas to avg before tossing out
%                           peaks
% 
%   reset_thresh            number of samples to avg before tossing out
%                           average
% 
%   neg_peak_deviance_threshold  threshold for filtering out peaks which
%                                deviate below an average peak delta% 
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

%CANCELLATION DC DRIFT AND NORMALIZATION
data = data - mean (data );    % cancel DC conponents
data = data/ max( abs(data)); % normalize to one
fs_prev = fs;
if (fs > 100)
fprintf('Downsampling to 100Hz..\n');
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
% Decimates the signal to 300Hz
% data = resample(data, 3, 2);
 datar = iddata(data,[],1/fs);
 data = idresamp(datar, fs/100);
 data = data.y;
 fs = 100; % Updates fs to the new value
end
 
%[GB] Ensures the the input args are of the correct data type
Fixed_Point_Properties_signed = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed', true);
F_signed = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
if (fs_prev > 100)
% Applies front end filters
fprintf('Applying front end filters\n');
[filtered_full_signal, dc_offset] = front_end_filters(data, fs);
% Offsets DC offset
filtered_full_signal = double(filtered_full_signal) - dc_offset;
figure(34)
plot(filtered_full_signal)
else
    fprintf('Getting dc offset\n');
    [~, dc_offset] = front_end_filters(data, fs);
    filtered_full_signal = data;
end
indata = fi(filtered_full_signal, Fixed_Point_Properties_signed, F_signed);

% Generates a CSV file that simulates the data that would be outputted by
% an ADC
% fake_nonfiltered_data(data, fi(4096, Fixed_Point_Properties, F), fi(3.3, Fixed_Point_Properties, F), 100, sample_size);
% figure(23);
% plot(filtered_full_signal);
% fake_nonfiltered_data(filtered_full_signal + 1.65, fi(4096, Fixed_Point_Properties, F), fi(3.3, Fixed_Point_Properties, F), 100, sample_size);
    
% return;
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
heart_rates_w_avg = [];
heart_rates_avg = 0;
t = [];
t_avg = [];
num_avg_samples = 4;
num_peak_deltas = fi(0, Fixed_Point_Properties, F);
hr_delta_sum = fi(0, Fixed_Point_Properties, F);
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
%      if (step >= 63 && step <= 65)
%     step
    if(step == 4)
        % Generates a CSV file that simulates the data that would be outputted by
        % an ADC
%         figure(23)
%         plot(indata(begin_index:end_index));
%         [~, heart_rate] = fake_nonfiltered_data(indata(begin_index:end_index) + 1.65, fi(4096, Fixed_Point_Properties, F), fi(3.3, Fixed_Point_Properties, F), 100, sample_size, fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), sample_size_t);
        
        % Finds the HR
        [heart_rate, hr_delta_sum, num_peak_deltas] = heart_rate_official_cport_w_debug(indata(begin_index:end_index), uint32(fs), fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), fi(0, Fixed_Point_Properties, F), hr_delta_sum, fi(toss_thresh, Fixed_Point_Properties, F), num_peak_deltas, fi(neg_peak_deviance_threshold, Fixed_Point_Properties, F), uint32(sample_size_t), uint32(1))
%         [heart_rate, ~, hr_delta_sum, num_peak_deltas, ~] = heart_rate_official_cport(indata(begin_index:end_index), uint32(fs), fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), fi(0, Fixed_Point_Properties, F), hr_delta_sum, fi(toss_thresh, Fixed_Point_Properties, F), num_peak_deltas, fi(neg_peak_deviance_threshold, Fixed_Point_Properties, F), uint32(sample_size_t), uint32(1));
        heart_rates_avg = heart_rates_avg + heart_rate;
        
        heart_rates = [heart_rates heart_rate];
        break
    else
%       [~, heart_rate] = fake_nonfiltered_data(indata(begin_index:end_index) + 1.65, fi(4096, Fixed_Point_Properties, F), fi(3.3, Fixed_Point_Properties, F), 100, sample_size, fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), sample_size_t);        
        [heart_rate, hr_delta_sum, num_peak_deltas] = heart_rate_official_cport_w_debug(indata(begin_index:end_index), uint32(fs), fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), fi(0, Fixed_Point_Properties, F), hr_delta_sum, fi(toss_thresh, Fixed_Point_Properties, F), num_peak_deltas, fi(neg_peak_deviance_threshold, Fixed_Point_Properties, F), uint32(sample_size_t), uint32(0))
%         [heart_rate, ~, hr_delta_sum, num_peak_deltas, ~] = heart_rate_official_cport(indata(begin_index:end_index), uint32(fs), fi(threshold_1, Fixed_Point_Properties, F), fi(threshold_2, Fixed_Point_Properties, F), fi(threshold_3, Fixed_Point_Properties, F), fi(pos_deviance_threshold, Fixed_Point_Properties, F), fi(neg_deviance_threshold, Fixed_Point_Properties, F), fi(0, Fixed_Point_Properties, F), hr_delta_sum, fi(toss_thresh, Fixed_Point_Properties, F), num_peak_deltas, fi(neg_peak_deviance_threshold, Fixed_Point_Properties, F), uint32(sample_size_t), uint32(0));
        heart_rates_avg = heart_rates_avg + heart_rate;
        
        heart_rates = [heart_rates heart_rate];
    end
%     hr_delta_avg = divide(Fixed_Point_Properties, hr_delta_sum, num_peak_deltas)
    % Calculates the hr_avg and resets the average
    if (mod(uint32(step + 1), uint32(num_avg_samples)) == 0)
        heart_rates_w_avg = [heart_rates_w_avg (heart_rates_avg / num_avg_samples)];
        t_avg = [t_avg (step_size +  step * step_size)/fs];
        heart_rates_avg = 0;
    end
    % Resets the hr_delta_avg and peak count
    if (mod(uint32(step + 1), uint32(reset_thresh)) == 0)
%         hr_delta_avg = divide(Fixed_Point_Properties, hr_delta_sum, num_peak_deltas);
%         num_peak_deltas
        num_peak_deltas = fi(0, Fixed_Point_Properties, F);
        hr_delta_sum = fi(0, Fixed_Point_Properties, F);
    end

end
toc
    
%clf(figure(2));
figure(20)
% Offsets each time value by the sample size
t = t + sample_size;
scatter(t, heart_rates);
max_hr = double(max(max(heart_rates), averageHR))
min_hr = double(min(min(heart_rates), averageHR))
mean_hr = mean(heart_rates)

% Offsets the x-axis and extends the y-axis
axis([sample_size, t(length(t)), max(min_hr - 30, 0), max_hr + 30])
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

% Averaged HR section

figure(21)
% Offsets each time value by the sample size
t_avg = t_avg + sample_size;
scatter(t_avg, heart_rates_w_avg);
max_hr_w_avg = double(max(max(heart_rates_w_avg), averageHR))
min_hr_w_avg = double(min(min(heart_rates_w_avg), averageHR))
mean_hr_w_avg = mean(heart_rates)
% Offsets the x-axis and extends the y-axis
axis([sample_size, t_avg(length(t_avg)), max(min_hr - 30, 0), max_hr + 30])
% grid on
hold on
% Plots the average HR on top of the graph
x = [0, max(t_avg)];
y = [averageHR, averageHR];
plot(x, y, 'r', 'LineWidth', 1);
% Plots the Error bars of HR on top of the graph
x = [0, max(t_avg)];
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

title('Average Heart Rates of 3 sample times');
xlabel('Time(s)');
ylabel('Heart Rate(bpm)');