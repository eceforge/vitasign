function [ filtered_output, dc_offset ] = front_end_filters( data, fs)
%-----Front end filters ------
%   Emulates the analog filters which will be implemented in hardware
%
%	Inputs:
%		data	EKG data
%		fs 		Sampling rate
%	Outputs:
%		filtered_output		data after being filtered_output
%		dc_offset			DC offset applied to data
% % % % % % % % % % % % % % % %
%
% Gbenga Badipe

%[GB] Ensures the the input args are of the correct data type
% T4 = numerictype('WordLength', 80, 'FractionLength', 40);
% Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 16, 'Signed',false);
% F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 16,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 16, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
x1 = data;
N = length (x1);       % Signal length
% t = (0:N-1)/fs;        % time index

%LOW PASS FILTERING

Fc  = 16;
low_pass_order = 2;   % FIR filter order
low_pass_spec = fdesign.lowpass('N,Fc',low_pass_order,Fc,fs);
low_pass = design(low_pass_spec,'window','window',@hamming);
x2 = filter(low_pass, x1);
% x2 = x2 (6+[1: N]); %cancle delay
x2 = x2/ max( abs(x2 )); % normalize , for convenience .

%HIGH PASS FILTERING

% HPF = Allpass-(Lowpass) = z^-16-[(1-z^-32)/(1-z^-1)]
%b = [-1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 32 -32 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1];
%a = [1 -1];

%h_HP=filter(b,a,[1 zeros(1,32)]); % impulse response iof HPF

Fc  = 5;
high_pass_order = 2;   % FIR filter order
high_pass_spec = fdesign.highpass('N,Fc',high_pass_order,Fc,fs);
high_pass = design(high_pass_spec,'window','window',@hamming);
%x3 = conv (x2 ,h_HP);
%x3 = x3 (16+[1: N]); %cancle delay
x3 = filter(high_pass, x2);
x3 = x3/ max( abs(x3 ));
figure(33)
plot(x3);

%DERIVATIVE FILTER
% 
% % Make impulse response
% h = [-1 -2 0 2 1]/8;
% % Apply filter
% x4 = conv (x3 ,h);
% x4 = x4 (2+ (1: N));
% x4 = x4/ max( abs(x4));
%   
filtered_output = x3;

%SQUARING

%x5 = x4 .^2;
%x5 = x5/ max( abs(x5 ));
% x5 = x5 * 1000; 
% x5 = x5 + abs(min(x4));
%filtered_output = x5;
% figure(10)
% plot(filtered_output);

%MOVING WINDOW INTEGRATION

% Make impulse response
% h = ones (1 ,31)/31;
% Delay = 15; % Delay in samples

% Apply filter
% x6 = conv (x5 ,h);
% x6 = x6 (15+(1: N));
% Normalizes the signal 
% x6 = x6 / max( abs(x6 ));
% figure(41)
% plot(x6);
%figure(23)
% plot(x5);
% Applies a dc offset
dc_offset = max(abs(filtered_output));
filtered_output = filtered_output + dc_offset;

% Changes it to fixed point
Fixed_Point_Properties = numerictype('WordLength', 12, 'FractionLength', 10, 'Signed', false);
filtered_output = fi(filtered_output, Fixed_Point_Properties);
end
