%#codegen
function [ result ] = test_fixed_point_optimization(num1, num2)
%---- Tests dynamic changing of a fixed point radix --------

Fixed_Point_Properties_signed = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',true);
F_signed = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
assert(isfi(num1));
assert(isfi(num2));
assert(isequal(numerictype(num1), Fixed_Point_Properties_signed) && isequal(fimath(num1), F_signed));
assert(isequal(numerictype(num2), Fixed_Point_Properties_signed) && isequal(fimath(num2), F_signed));
num1 = fi(num1, Fixed_Point_Properties_signed, F_signed);
num2 = fi(num2, Fixed_Point_Properties_signed, F_signed);
% result2 = fi(num1 + num2, Fixed_Point_Properties_signed, F_signed); 
% Result should be 22.36241
result = num1 * num2;
% result = fi(num1 * num2, Fixed_Point_Properties_signed, F_signed);
end

