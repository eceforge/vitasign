 % Reads the text file to    fetch a column of file names and a column of
% sampling rates
function [] = EKG_Testing(root_dir, csv_fileName, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, toss_thresh, reset_thresh, neg_peak_deviance_threshold, sample_size)

% Reads the file names and sampling rates from the file
fullfile(root_dir,csv_fileName)
fid1 = fopen(fullfile(root_dir,csv_fileName));
test_data = textscan(fid1, '%s%f%f', 'Delimiter', ',');
fclose(fid1);
test_file_names = test_data{1, 1};
test_file_names = char(test_file_names);
sampling_rates = test_data{1, 2};
avg_heart_rates = test_data{1, 3};
%size(test_file_names, 1)
% Ensures that their row counts are the same so that each data file has a
% matching sampling rate and an average heart rate
assert(size(test_file_names, 1) == size(sampling_rates, 1) && size(sampling_rates,1) == size(avg_heart_rates, 1));

% Runs each sample through the HR emulator
for i=1:size(sampling_rates,1)
    filename = fullfile(root_dir,test_file_names(i, :));
    % Converts char array to a fully qualified string 'object' to deal
    % with spaces in file names
    filename = strcat('', filename);
    fprintf('\nProcessing %s\n', filename);
    fs = sampling_rates(i,1);
    average_HR = avg_heart_rates(i,1);
    data = importdata(filename, ' ');
    % Handles data which doesn't come with a time vector
    if (size(data, 2) == 1)
        heart_rate_emulator_cport(data(:,1), fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, toss_thresh, reset_thresh, neg_peak_deviance_threshold, sample_size, average_HR);
    else
        heart_rate_emulator_cport(data(:,2), fs, threshold_1, threshold_2, threshold_3, pos_deviance_threshold, neg_deviance_threshold, toss_thresh, reset_thresh, neg_peak_deviance_threshold, sample_size, average_HR);
    end
        
    %pause(30);
    % SAVES ALL THE GRAPHS  %
    % Retrieves all the open graph handles
    figHandles = findobj('Type','figure');
    % Saves all the figures
    for j=1 : size(figHandles)
%          print('-dtiff','-r200'
        fprintf('Saving..');
        print('-dtiff','-r200',figHandles(j),strcat(root_dir, '/Results/',strcat('',test_file_names(i,:)), num2str(j), '.fig'));
    end
    % Closes all the graphs
    close all
    % Waits for all the figures to close
    for j=1 : size(figHandles)
        waitfor(figHandles(j));
    end

end




end