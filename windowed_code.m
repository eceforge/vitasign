function [ output_args ] = untitled( input_args )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here

if 0
% Windows and fft's the signal%
for step=0:numWindows-1
    N1=1+stepSize*step;%[GB]N1 represents the beginning index of the window 
    N2=N1+windowSize-1;%[GB]N2 demarcates where the window end
    %Retrieves windowed signal
    windowedSignal=heartData(N1:N2);
    %bandFilter=bpass;%[GB]Gets band pass filter previously designed
    lowFilter=lpass;%[GB]Gets lowpass filter
    filtSignal=filter(lowFilter,windowedSignal.*hamming(windowSize));%[GB]Applies the butter filter to the signal
    highPassButter=hpass;%[GB]Gets the high pass butterworth filter%
    filtSignal=filter(highPassButter,filtSignal);%[GB]Applies the butter filter to the LPF signal
    % Applies the derivative filter to the signal to get rid of extremely
    % low frequencies
    %derivativeFilter=derivative;%[GB]Gets the derivative filter%
    %filtSignal=filter(derivativeFilter,filtSignal);%[GB]Applies the derivative to the bandpassed signal
    
    NFFT = 2048; %[GB] Next power of 2 from length of y
    transform=fft(filtSignal,NFFT)/1024;%[GB] Transform from discrete values to the frequency domain
    transform=transform;

    windows=[windows,abs(transform)];
    freq = 1000/2*linspace(0,1,NFFT/2+1);%[GB]Frequency index
     
    %filtTransform=filter(bandFilter,transform);%[GB]Uses the bandpass filter to filter signal
    
    %filtTransform=filter(lowFilter,transform);%[GB]Uses the lowpass filter to filter out any high frequency components of the signal   

    if(step==100)
        out=windowedSignal.*hamming(windowSize);
        % Plots Frequency Response
        %plot(freq,2*abs((1:transform(NFFT/2+1))))
        plot(freq,2*abs(transform(1:NFFT/2+1)))
        hold on;        
        fprintf('Plotting\n');
        title('EKG Signal');
        xlabel('Frequency (Hz)')
        ylabel('|X(f)|')
        %plot(abs(filtTransform));
        %xlabel('Frequency(kHz)')
        %ylabel('Response')
    end
end
end
end

