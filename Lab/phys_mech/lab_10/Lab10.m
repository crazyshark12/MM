%% Дифференцирующая цепь
R = 1.5*10^3
C = 320*10^(-12)
Um = 5
raschet_table_diff = readtable("table_10_1.csv");

raschet_table_diff.Ur_RC = Um*exp(-raschet_table_diff.t/(R*C));
raschet_table_diff.Ur_100RC = Um*exp(-raschet_table_diff.t/(100*R*C))

m = [raschet_table_diff{:,'t'}];
n = [raschet_table_diff{:,'Ur_100RC'}];
xi = [m(1):0.0000001:m(end)];
%% Зависимость выходного напряжения от времени
f = figure
x = [raschet_table_diff{:,'t'}];
v = [raschet_table_diff{:,'Ur_RC'}];
xi = [x(1):0.0000001:x(end)];
vid=interp1(x,v,xi,'spline');
%plot(x,v,'o')
grid on
hold on
title('Зависимость выходного напряжения от времени при tau = RC')
ylabel('Ur, B')
xlabel('t, мкс')
plot(xi,vid,'r', 'LineWidth', 2.0)
hold on

y = [3.42
0.78
0.18
0.06
0.02
0.004];
u = [3.9
3.86
3.78
3.7
3.66
3.58];
yid=interp1(x,y,xi,'spline');
plot(x,y,'b*', 'LineWidth',2.0)
legend('рассчёт','эксперимент')
hold on
%plot(xi,yid,'r', Color='blue')

%%%%%%%%%%%%%%%%%
f = figure
vid=interp1(m,n,xi,'spline');
%plot(m,n,'o')
hold on
grid on
ylabel('Ur, B')
xlabel('t, мкс')
title('Зависимость выходного напряжения от времени при tau = 100RC')
plot(xi,vid,'r', 'LineWidth', 2.0)

uid=interp1(m,u,xi,'spline');
plot(m,u,'b*','LineWidth',2.0)
legend('рассчёт','эксперимент')
hold on

%plot(xi,uid,'r', Color='blue')

%%

A_CH_H_diff = readtable("table_10_2.csv")
A_CH_H_diff.omega = 2*pi*A_CH_H_diff.f
A_CH_H_diff.A_RC = (A_CH_H_diff.omega*R*C)./((1+(A_CH_H_diff.omega*R*C).^2).^0.5)
A_CH_H_diff.A_100RC = (A_CH_H_diff.omega*100*R*C)./((1+(A_CH_H_diff.omega*R*C*100).^2).^0.5)

%% Aплитудно-частотные характеристики
f = figure
x = [A_CH_H_diff{:,'f'}];
v = [A_CH_H_diff{:,'A_RC'}];
xi = [x(1):10000:x(end)];
vid=interp1(x,v,xi,'spline');
%plot(x,v,'o')
hold on
grid on
title('Aплитудно-частотная характеристика при tau = RC')
ylabel('A')
xlabel('f, кГц')
plot(xi,vid,'r', 'LineWidth', 2.0)


y = [0
0.0054
0.014
0.028
0.056
0.140
0.264
0.568
0.7
0.712
0.740];
u = [0
0.428
0.664
0.744
0.760
0.776
0.776
0.784
0.784
0.784
0.788];
yid=interp1(x,y,xi,'spline');
plot(x,y,'b*','LineWidth',2.0)
legend('рассчёт','эксперимент')
hold on
%plot(xi,yid,'r', Color='blue')

f = figure
x = [A_CH_H_diff{:,'f'}];
v = [A_CH_H_diff{:,'A_100RC'}];
xi = [x(1):1:x(end)];
vid=interp1(x,v,xi,'linear');
legend('рассчёт','эксперимент')
%plot(x,v,'o')
hold on
grid on
title('Aплитудно-частотная характеристика при tau = 100RC')
ylabel('A')
xlabel('f, кГц')
plot(xi,vid,'r', 'LineWidth', 2.0)


uid=interp1(x,u,xi,'spline');
plot(x,u,'b*','LineWidth',2.0);
legend('рассчёт','эксперимент')
hold on
%plot(xi,uid,'r', Color='blue')

%% Интегрирующая цепь
R = 18*10^(3)
C = 510*10^(-12)

raschet_table_int = readtable("table_10_3.csv");
raschet_table_int.Uc_RC = Um*(1-exp(-raschet_table_int.t/(R*C)));
raschet_table_int.Uc_RC100 = Um*(1-exp(-raschet_table_int.t/(R*C/100)))

%% Зависимость выходного напряжения

f = figure
x = [raschet_table_int{:,'t'}];
v = [raschet_table_int{:,'Uc_RC'}];
xi = [x(1):0.000001:x(end)];
vid=interp1(x,v,xi,'spline');
%plot(x,v,'o')
hold on
grid on
title('Зависимость выходного напряжения от времени при tau = RC')
ylabel('Uc, B')
xlabel('t, мкс')
plot(xi,vid,'r', 'LineWidth', 2.0)

y = [0
0.054
0.110
0.138
0.182
0.226
0.266
0.306
0.354
0.394
0.418];
u = [0
2.5
3.76
4.32
4.64
4.8
4.96
4.96
4.96
4.96
4.96];
yid=interp1(x,y,xi,'spline');
plot(x,y,'b*','LineWidth',2.0)
legend('рассчёт','эксперимент')
hold on
%plot(xi,yid,'r', Color='blue')

f = figure
x = [raschet_table_int{:,'t'}];
v = [raschet_table_int{:,'Uc_RC100'}];
xi = [x(1):0.00000001:x(end)];
vid=interp1(x,v,xi,'spline');
legend('эксперимент','рассчёт')
%plot(x,v,'o')
hold on
grid on
title('Зависимость выходного напряжения от времени при tau = RC/100')
ylabel('Uc, B')
xlabel('t, мкс')
plot(xi,vid,'r', 'LineWidth', 2.0)

uid=interp1(x,u,xi,'spline');
plot(x,u,'b*','LineWidth',2.0)
legend('рассчёт','эксперимент')
hold on
%plot(xi,uid,'r', Color='blue')
%% Погрешность

delta_U2 = 0.5*Um*(10^(-6)/(R*C))^2 % Абсоллют. погрешность
delta = 0.5*(10^(-6)/(R*C))*100 % Относ. погрешность
%%
A_CH_H_diff.intA_RC = sqrt(1- A_CH_H_diff.A_RC.^2)
A_CH_H_diff.intA_RC100 = sqrt(1 - A_CH_H_diff.A_100RC.^2)

%A_CH_H_diff.intA_RC100 = 1./((1+(A_CH_H_diff.omega*R*C/100).^2).^0.5)

%%
%% Aплитудно-частотные характеристики
% f = figure
% x = [A_CH_H_diff{:,'f'}];
% v = [A_CH_H_diff{:,'intA_RC'}];
% xi = [x(1):1:x(end)];
% vid=interp1(x,v,xi,'linear');
% plot(x,v,'o')
% hold on
% grid on
% title('Aплитудно-частотная характеристика при tau = RC')
% ylabel('A')
% xlabel('f, кГц')
% plot(xi,vid,'r', 'LineWidth', 2.0)
% 
% u = [1
% 0.992
% 0.992 
% 0.992
% 0.992
% 0.992
% 0.992
% 0.944
% 0.88
% 0.8
% 0.74];
% y = [1
% 0.8
% 0.56
% 0.264
% 0.136
% 0.074
% 0.034
% 0.022
% 0.017
% 0.013
% 0.014];
% 
% yid=interp1(x,y,xi,'linear');
% plot(x,y,'b*','LineWidth',2.0);
% legend('рассчёт','эксперимент')
% hold on
%plot(xi,yid,'r', Color='blue')

f = figure
x = [A_CH_H_diff{:,'f'}];
v = [A_CH_H_diff{:,'intA_RC100'}];
xi = [x(1):10:x(end)];
vid=interp1(x,v,xi,'pchip');
%plot(x,v,'o')
hold on
grid on
title('Aплитудно-частотная характеристика при tau = RC/100')
ylabel('A')
xlabel('f, кГц')
plot(xi,vid,'r', 'LineWidth', 2.0)

uid=interp1(x,u,xi,'spline');
plot(x,y,'b*', 'LineWidth',2.0);
legend('рассчёт','эксперимент')
hold on
%plot(xi,uid,'r', Color='blue')