L = [21.87
     20.05
     10.13
     20.05
     22.06
     18.09]*10^(-3)

T = [7.3 7.0 3.24 7.5 11.9 9.4
     7.1 7.0 3.2  8.1 12.1 9.7
     7.6 7.2 3.32 7.7 12.0 9.8
     7.3 7.0 3.08 7.8 12.3 10.1 
     7.4 6.8 3.2  7.8 12.2 9.8]*10^(-6)
    
columnMeans = sum(T, 1) ./ sum(T~=0)
Z = array2table(T,...
    'VariableName', {'prod_1', 'prod_2', 'prod_3', 'sdvig_1', 'sdvig_2', 'sdvig_3'})

writetable(Z, 'lab_9.csv')

L = table(L)
writetable(L, 'lab_9_L.csv')


