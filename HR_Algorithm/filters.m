function [ filtered_output ] = front_end_filters( data, fs)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
%[GB] Ensures the the input args are of the correct data type
% T4 = numerictype('WordLength', 80, 'FractionLength', 40);
% Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 16, 'Signed',false);
% F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 16,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 16, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
x1 = data;
N = length (x1);       % Signal length
% t = (0:N-1)/fs;        % time index

%LOW PASS FILTERING

%CANCELLATION DC DRIFT AND NORMALIZATION
x1 = x1 - mean (x1 );    % cancel DC conponents
x1 = x1/ max( abs(x1 )); % normalize to one

Fc  = 16;
low_pass_order = 2;   % FIR filter order
low_pass_spec = fdesign.lowpass('N,Fc',low_pass_order,Fc,fs);
low_pass = design(low_pass_spec,'window','window',@hamming);
x2 = filter(low_pass, x1);
%x2 = x2 (6+[1: N]); %cancle delay
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


%DERIVATIVE FILTER

% Make impulse response
h = [-1 -2 0 2 1]/8;
% Apply filter
x4 = conv (x3 ,h);
x4 = x4 (2+ (1: N));
x4 = x4/ max( abs(x4));
filtered_output = x4;
min(x4)
min(filtered_output)
figure(22)
plot(x4);
figure(23)
plot(filtered_output);

end
