%#codegen
function [test ] = test_case( data )
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
assert(isfi(data));
Fixed_Point_Properties = numerictype('WordLength', 32, 'FractionLength', 10, 'Signed',false);
F = fimath('OverflowMode','saturate', 'RoundMode', 'nearest', 'ProductFractionLength', 20,'ProductMode', 'SpecifyPrecision', 'MaxProductWordLength', 32, 'SumFractionLength', 10, 'SumMode', 'SpecifyPrecision','MaxSumWordLength', 32);
assert(isequal(numerictype(data), Fixed_Point_Properties) && isequal(fimath(data), F));
test = max(data);
poss_reg =uint32((data > .7)');
left = uint32(find(diff([0 poss_reg])==1)); % Gets all the indices in the resultant diff vector for which X[n] - X[n-1] = 1

end

