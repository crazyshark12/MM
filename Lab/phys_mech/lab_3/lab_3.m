L = 215*10^(-6);
C = 0.022*10^(-6);
R = 40;

zatuh_koleb = readtable("table_1.csv");

T_LC_mean = mean(zatuh_koleb{1,:}); % Среднее значение периода для LC
T_LCR_mean = mean(zatuh_koleb{2,1:3}); % Среднее значение периода для LCR

T_pogresh = 0.5; % Прямая погрешность = предел допуск. погреш. прибора

omega_0 = 1/(L*C)^0.5 % Собственная частота контура
betta = R/(2*L) % Коэф. затухания
omega = (omega_0^2 - betta^2)^0.5 % Частота затухающих колебаний

log_decrement = readtable('table_2.csv')

lambda = [log_decrement{1,1:end-1}./log_decrement{1,2:end}
          log_decrement{2,1:end-1}./log_decrement{2,2:end}]
lambda = round(log(lambda),2) % Логарифмический декремент затухания

lambda_mean = round(mean(transpose(mean((lambda)))),2) % Среднее значение логарифмического декремента затухания
%ПОСМОТРЕТЬ НА ПРИБОРЕ% 
U_pogresh = 0.005
lambda_pogresh = ((1/132)^2)*U_pogresh^2 + ((-1/25.6)^2)*((2*U_pogresh)^2)^0.5*100 % Погреш. косв. измер.

betta_RLC = lambda_mean/T_LCR_mean*10^6 % Коэф. затухания
tau = 1/betta_RLC*10^(-6) % Постоянная времени затухания
Q = pi/lambda_mean% Добротность контура

betta_RLC_pogreesh = ((1/T_LCR_mean)^2*lambda_pogresh^2 + (-lambda_mean/(T_LCR_mean^2))^2*T_pogresh^2)^0.5*1000 % Погреш. коэф. затухания
tau_pogresh = ((-1/(betta_RLC_pogreesh^2))^2*betta_RLC_pogreesh^2)^0.5/100*10^(-6) % Погреш. постоянной времени затухания
Q_pogresh = ((-pi/(lambda_pogresh^2))^2*lambda_pogresh^2)^0.5/100 % ПОгреш. добротности контура

f_res_table = readtable("table_3.csv")

vinujd_koleb_LC = readtable("table_4.csv")
U_res_LC = 16.5
vinujd_koleb_LC.('U_LC/U_res_LC') = [vinujd_koleb_LC{:,2}./U_res_LC]

% Построение резонанс. кривой LC    
f = figure
v = [vinujd_koleb_LC{1,1:6}] /U_res_LC;
x = [vinujd_koleb_LC{2,1:6}];
xi = [x(1):0.001:x(end)];
vid=interp1(x,v,xi,'spline');
plot(x,v,'b*')
hold on
grid on
plot(xi,vid,'r')
h = yline(0.707 , 'r--');
ylabel('U/Ures')
xlabel('f, kHz')


k = 0.707
f_1_LC = interp1(v, x, k)
f_2_LC = interp1(v,x, k)
f_2_LC = 66
m = xline(f_1_LC, 'r--');
n = xline(f_2_LC, 'r--');

delta_f_LC = f_2_LC - f_1_LC

Q_LC = f_res_table{1,1}/delta_f_LC


vinujd_koleb_LCR = readtable("table_5.csv")
U_res_LCR = max(vinujd_koleb_LCR{:,1})
vinujd_koleb_LCR.('U_LC/U_res_LCR') = [vinujd_koleb_LCR{:,1}./U_res_LCR]

f = figure
v = [vinujd_koleb_LCR{1:14,1}] / U_res_LCR;
x = [vinujd_koleb_LCR{1:14,2}];
xi = [55:0.001:120];
vid=interp1(x,v,xi,'spline');
plot(x,v,'b*')
hold on
grid on
plot(xi,vid,'r')
h = yline(0.707, 'r--');
ylabel('U/Ures')
xlabel('f, kHz')


k = 0.707
f_1_LCR = interp1(v, x, k)
f_2_LCR = 58.7

m = xline(f_1_LCR, 'r--');
n = xline(f_2_LCR, 'r--');

delta_f_LCR = f_2_LCR - f_1_LCR

Q_LCR = f_res_table{1,2}/delta_f_LCR

omega_0/(2*betta)