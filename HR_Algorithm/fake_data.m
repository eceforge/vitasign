function [ adc_data, resampled_data ] = fake_data(data, max_sample_int, max_voltage, fs,fs_new, sample_time)

% Resamples the data to fs_new
datar = iddata(data,[],1/fs);
data = idresamp(datar, fs/fs_new);
data = data.y;
N = length(data);
data = data + max(abs(data));
resampled_data = data;
% plot(data)
adc_data = zeros(N, 1);
% Converts data to what an ADC would produce
for i=1:N
    adc_data(i) = int32(max_sample_int * data(i) / max_voltage);
end
adc_data = adc_data(1:sample_time * fs_new);
csvwrite('test_data.csv', adc_data);


end

