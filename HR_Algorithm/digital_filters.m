function [ data_unsigned ] = digital_filters( data )


% Defines Signed and Unsigned Fixed point objects
Fixed_Point_Properties_signed = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
F_signed = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

assert(isfi(data));
% asserts that input parameters are of specific fixed point parameters
assert(isequal(numerictype(data), Fixed_Point_Properties_signed) && isequal(fimath(data), F_signed));

% x1 = data;
N = uint32(length(data));       % Signal length

%------ MOST FILTERING NOW OCCURS IN ANALOG SEE 'front_end_filters.m' FOR EMULATED FRONT END FILTERS



%DERIVATIVE FILTER

% Make impulse response
h = divide(Fixed_Point_Properties_signed, fi([-1 -2 0 2 1], Fixed_Point_Properties_signed, F_signed), fi(8, Fixed_Point_Properties_signed, F_signed));
% Apply filter
data = conv (data ,h);
data = data (2+ (1: N));
data = divide(Fixed_Point_Properties_signed,  data, max( abs(data)));
% UPDATES FIXED POINT DEFINITION TO BE UNSIGNED
Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);

  
 
%SQUARING

data_unsigned = fi(data.^2, Fixed_Point_Properties, F);

% Changes the fixed point properties of the data to be unsigned after
% squaring
% data_unsigned = fi(data, Fixed_Point_Properties, F);

% Normalizes the result of the squaring
% data_unsigned = divide(Fixed_Point_Properties, data_unsigned, max( data_unsigned )); % normalize to one
% assert(isequal(numerictype(data_unsigned),Fixed_Point_Properties) && isequal(fimath(data_unsigned), F));

%MOVING WINDOW INTEGRATION

% Make impulse response
h = divide(Fixed_Point_Properties, fi(ones (1, 7), Fixed_Point_Properties, F), 7);

% Delay = 15; % Delay in samples

% Apply filter
data_unsigned = fi(conv (data_unsigned ,h), Fixed_Point_Properties, F);
data_unsigned = data_unsigned (3+(1: N));

end

