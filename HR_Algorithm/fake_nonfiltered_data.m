function [ adc_data ] = fake_nonfiltered_data( data, max_sample_int, max_voltage, fs, sample_time)

% plot(data)
N = length(data);
% data = data + max(abs(data));
figure(25)
plot(data);
adc_data = zeros(N, 1);
% Converts data to what an ADC would produce
for i=1:N
    adc_data(i) = int32(double(data(i)) * double(max_sample_int) / double(max_voltage)) - int32(2048);
%     adc_data(i) = int32(double(max_sample_int * data(i) / max_voltage)) - int32(2048);
end
figure(26)
% plot(data(1:sample_time * fs));
plot(adc_data)
fprintf('Done\n');
% adc_data = adc_data(1:sample_time * fs);
adc_data = adc_data(2*sample_time*fs:3*sample_time * fs);
figure(27)
% plot(data(1:sample_time * fs));
plot(adc_data)
path = 'test_nonfiltered_data.csv';
% delete(path);
dlmwrite(path, adc_data,'delimiter',',','precision',10);
% csvwrite('test_filtered_data.csv', adc_data);

end

