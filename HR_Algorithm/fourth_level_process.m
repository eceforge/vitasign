% Level 4 Detection: Reduces FNs by comparing Ds(detection strength) against
% the threshold
%R_peak_indices_combined
% FOURTH LEVEL PROCESSING TO REDUCE FNs
    function [indices, noise_lvl, signal_lvl] = fourth_level_process(threshold, indices)
        noise_sum = 0; signal_sum = 0;
        noise_count = 0; signal_count = 0;
        noise_lvl = 0; signal_lvl = 0;
        for i=1:length(indices)
           if (R_peak_indices_combined(i) == 0)
               % Calculates the Detection strength
               Ds_3 = min(1,(R_peak_vals(i) - noise_lvl) / (signal_lvl - noise_lvl));
               % Ensures that the signal strength is between 0 and 1
               Ds_3 = max(0, Ds_3);
               
               % Changes a non-beat to a beat if channel 3's detection strength is
               % greater than its threshold
               if (Ds_3 > threshold)
                   %fprintf('Threshold %f. Ds: %f Changing %f a non-beat to a beat\n', threshold, Ds_3, R_peak_vals(i) *max_voltage);
                   % Updates the average signal lvl
                   signal_sum = signal_sum + R_peak_vals(i);
                   signal_count = signal_count + 1;
                   % Calculates the signal level
                   signal_lvl = signal_sum / signal_count;
                   % REMOVE AFTER TESTING
                   indices(i) = 0;
               else
                   % Sets all the indices which R_vals don't meet the threshold to 0
                   indices(i) = 0; 
                   %fprintf('Setting the indice to zero\n');
                   % Updates the average noise signal lvl
                   noise_sum = noise_sum  + R_peak_vals(i);
                   noise_count = noise_count + 1;
                   % Calculates the noise level
                   noise_lvl = noise_sum / noise_count;
               end
           else
                   % Updates the average signal lvl
                   signal_sum = signal_sum + R_peak_vals(i);
                   signal_count = signal_count + 1;
                   % Calculates the signal level
                   signal_lvl = signal_sum / signal_count;
           end
        end
    end  

