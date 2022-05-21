raschet_data = readtable('raschet_data.csv')


C1 = 47*10^(-6)
C2 = 47*10^(-6) %нужен варик
L_dr = 3.8
R_dr = 190
% сопротивление нагрузки:
f_c = 50
% Внутреннее сопротивление диода
r1 = 220
r2 = 25
n = 0.1
E = 31

R_tr = r2 + n^2*r1

raschet_data.('R0') = [2*raschet_data{:,'Ri'} + R_tr]
raschet_data.('R1') = [2*(raschet_data{:,'Rn'} + R_dr)]
raschet_data.('R1/R0') = [raschet_data{:,'R1'}./raschet_data{:,'R0'}]
raschet_data.('cos_tetta') = [0.86 
                              0.9 
                              0.925 
                              0.94]
raschet_data.('sin_tetta') = sqrt(1 - raschet_data{:,"cos_tetta"}.^2)
raschet_data.('U_mn1') = [(E*raschet_data{:,"sin_tetta"}.^3)./(C1*f_c*raschet_data{:,'R0'}*3*pi^2)]
raschet_data.('Uk') = E*raschet_data{:,"cos_tetta"}
raschet_data.('S') = [raschet_data{:,'U_mn1'}./raschet_data{:,'Uk'}]
raschet_data.('U_mn2') = [raschet_data{:,'U_mn1'}./((4*pi*f_c)^2*L_dr*C2)]
raschet_data.('Un') = (raschet_data{:,'Uk'}.*raschet_data{:,'Rn'})./(raschet_data{:,'Rn'} + R_dr)
raschet_data.('N') = (raschet_data{:,"sin_tetta"}.^3)./(raschet_data{:,'cos_tetta'}*3*pi^2)
raschet_data.('U_mn2/Un') = ((1 + R_dr/raschet_data{:,'Rn'})*raschet_data{:,'N'})./(16*pi^2*f_c^3*C1*C2*L_dr*raschet_data{:,'R0'})
raschet_data.('In') = raschet_data{:,'Un'}./raschet_data{:,'Rn'}
writetable(raschet_data, 'lab10.xlsx')


%%

data = table()
data.Un = [23.2
           27.2
           29.8
           31.2]
data.Un_raschet = raschet_data{:,'Un'}
data.In = data{:,'Un'}./raschet_data{:,'Rn'}
data.Umn1 = [2.36
             1.24
             0.6
             0.29]
data.Umn2 = [0.02
             0.0116
             0.006
             0.00332]
data.Uk = [28.1
           29.7
           30.9
           31.8]
data.Uk_raschet = raschet_data{:,'Uk'}
data.S = data{:,'Umn1'}./raschet_data{:,'Uk'}
data.UU = data{:,'Umn2'}./raschet_data{:,'Un'}

%%
f = figure
x = [raschet_data{:, 'In'}];
v = [raschet_data{:, 'Un'}];
y = [data{:, 'In'}];
u = [data{:, 'Un'}];
plot(x,v, 'o')
hold on
plot(y,u, '*')
hold off
xlabel('In, A')
ylabel('Un, B')
title('Un = f(In)')
grid on
