%function [ output_args ] = untitled( input_args )
function [heartRate] = heart_rate(fileName,winSize, heartData, fs)
%Heart Rate Summary of this function goes here
%   Detailed explanation goes here

%heartData=load(fileName);%[GB] Gets data from the file
%out=heartData;%[GB]Output variable

%[GB] Window size for the fft
windowSize=winSize;
filterOrder=10; %[GB] Order of the filter
[numRows, numCols]=size(heartData); %[GB]Gets the size of the HR data. This will be used to figure out how many windows are necessary
stepSize=windowSize/2;%[GB]Step size
numWindows=floor(numRows/stepSize)-1; %[GB]Caclulates the number of windows necessary by dividing the number of data samples by the step size. This assumes 50% overlap
windows=[];
fprintf('# Windows:  %i\n', numWindows);
filtSignal = [];

%Retrieves windowed signal
windowedSignal=heartData;
windowSize=numRows;%[GB] Window size for the fft
filtSignal=windowedSignal;

% Applies the filters %
lowFilter=lpass;%[GB]Gets lowpass filter
filtSignal=filter(lowFilter,windowedSignal);%[GB]Applies the butter filter to the signal
highPassFilter=hpass;%[GB]Gets the high pass butterworth filter%
filtSignal=filter(highPassFilter,filtSignal);%[GB]Applies the butter filter to the LPF signal

%Applies the moving window filter

% Applies the derivative filter to the signal to get rid of extremely
% low frequencies
filtSignal = diff(filtSignal);
%derivativeFilter=derivative;%[GB]Gets the derivative filter%
%filtSignal=filter(derivativeFilter,filtSignal);%[GB]Applies the derivative to the bandpassed signal

% Squares the signal %
filtSignal = filtSignal .^ 2;
% Takes the fft of the signal %
%NFFT = 1048576; %[GB] Next power of 2 from length of y
NFFT = 131072;
transform=fft(filtSignal,NFFT)/windowSize;%[GB] Transform from discrete values to the frequency domain
%transform=fft(windowedSignal,NFFT)/windowSize;%[GB] Transform from discrete values to the frequency domain

% Plots the fft of the filtered signal
transform=transform;
windows=[windows,abs(transform)];
freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index
fprintf('Plotting\n');
figure(1);
plot(freq,2*abs(transform(1:NFFT/2+1)));
title('FFT Filtered EKG Signal');
xlabel('Frequency (Hz)');
ylabel('|X(f)|');

%Plots the fft of the original signal
transform=fft(heartData,NFFT)/windowSize;%[GB] Transform from discrete values to the frequency domain
%transform=transform;
windows=[windows,abs(transform)];
freq = fs/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index
fprintf('Plotting\n');
figure(2);
plot(freq,2*abs(transform(1:NFFT/2+1)));
title('FFT EKG Signal');
xlabel('Frequency (Hz)');
ylabel('|X(f)|');

% Plots the original signal for comparison
fprintf('Plotting\n');
figure(3);
plot(heartData);
title('EKG Signal');
xlabel('Time(t)');
ylabel('');

% Plots the filtered signal in the time domain
fprintf('Plotting\n');
figure(4);
plot(filtSignal);
title('Filtered EKG Signal');
xlabel('Time(t)');
ylabel('');
% This should be set to the actual HR once computed %
heartRate = 0;
end