function [ heart_rate ] = heart_rate_emulator( data,fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size, averageHR)

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
% Holds the length of the signal
N = length(data);
window_size =  sample_size * fs
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
    sample_size_t = length(data(begin_index:end_index)) / fs;
    if (step == 10)
        heart_rate = heart_rate_official_cport(data(begin_index:end_index), fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size_t, 1);
        heart_rates = [heart_rates heart_rate];
    else
        heart_rate = heart_rate_official_cport(data(begin_index:end_index), fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size_t, 0);
        heart_rates = [heart_rates heart_rate];
    end

end
toc
    
%clf(figure(2));
figure(20)
% Offsets each time value by the sample size
t = t + sample_size;
scatter(t, heart_rates);

% Offsets the x-axis and extends the y-axis
axis([sample_size, t(length(t)), 60, 250])
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

