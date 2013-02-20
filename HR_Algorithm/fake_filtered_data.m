function [ adc_data ] = fake_filtered_data( data, max_sample_int, max_voltage, fs, sample_time)

% plot(data)
N = length(data);

adc_data = zeros(N, 1);
% Converts data to what an ADC would produce
for i=1:N
    adc_data(i) = int32(max_sample_int * data(i) / max_voltage);
end
adc_data = adc_data(1:sample_time * fs);
path = 'test_filtered_data.csv';
% delete(path);
dlmwrite(path, adc_data,'delimiter',',','precision',10);
% csvwrite('test_filtered_data.csv', adc_data);

end

