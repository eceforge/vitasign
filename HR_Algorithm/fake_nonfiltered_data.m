function [ adc_data, heart_rate_adc ] = fake_nonfiltered_data( data, max_sample_int, max_voltage, fs, sample_time, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, sample_size_t)

% plot(data)
N = length(data);
% data = data + max(abs(data));
figure(25)
plot(data);
adc_data = zeros(N, 1);
% Converts data to what an ADC would produce
for i=1:N
    adc_data(i) = int32(double(data(i)) * double(max_sample_int) / double(max_voltage)) - int32(2048);
%     adc_data(i) = int32(double(data(i)) * double(max_sample_int) / double(max_voltage));
%     adc_data(i) = int32(double(max_sample_int * data(i) / max_voltage)) - int32(2048);
end
figure(26)
% plot(data(1:sample_time * fs));
plot(adc_data)
fprintf('Done converting to adc data\n');

% sub_adc_data = adc_data(3*sample_time*fs:4*sample_time * fs);
% figure(27)
% plot(sub_adc_data)

path = 'test_nonfiltered_data.csv';
dlmwrite(path, adc_data,'delimiter',',','precision',10);

% Converts data back to fixed point
Fixed_Point_Properties_signed = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed', true);
F_signed = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

adc_data_fi = fi(adc_data, Fixed_Point_Properties_signed, F_signed);
max_voltage_fi =fi(max_voltage, Fixed_Point_Properties_signed, F_signed);
max_sample_int = fi(max_sample_int, Fixed_Point_Properties_signed, F_signed);

final_data = fi(adc_data_fi * divide(Fixed_Point_Properties_signed, max_voltage_fi, max_sample_int), Fixed_Point_Properties_signed, F_signed); %Converts data back to fixed point
assert(isequal(numerictype(final_data), Fixed_Point_Properties_signed) && isequal(fimath(final_data), F_signed));

figure(28)
plot(final_data);

heart_rate_adc = heart_rate_official_cport_w_debug(final_data, uint32(fs), fi(threshold_1, Fixed_Point_Properties_signed, F_signed), fi(threshold_2, Fixed_Point_Properties_signed, F_signed), fi(threshold_3, Fixed_Point_Properties_signed, F_signed), fi(pos_deviance_threshold, Fixed_Point_Properties_signed, F_signed), fi(neg_deviance_threshold, Fixed_Point_Properties_signed, F_signed), uint32(sample_size_t), uint32(0),  fi(0, Fixed_Point_Properties_signed, F_signed));

end

