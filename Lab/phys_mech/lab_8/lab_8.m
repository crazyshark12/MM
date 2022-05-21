%% Работа с данными
data_ar = table2array(readtable("lab8_1.csv")) % Таблица со столбцами V1, I, U1, U2
alpha_R = 6.8*10^(-3) % Температур. коэф. сопротивления
T2 = 299.0 % Абс. темп. трубки
L1 = 0.18 
L2 = 0.03
r1 = 0.0001
r2 = 0.004

%1 V1
%2 I
%3 U1
%4 U2

%data_ar = table2array(data);

%5 U1-U2
data_ar(:, 5) = [data_ar(:, 3) - data_ar(:, 4)]

%6 Rн(T1)
data_ar(:, 6) = [data_ar(:, 5)./data_ar(:, 2)]

%% Получение Rн(T2) c помощью экстраполяции (продолжаем график к нулю)
p = polyfit(data_ar(:, 1),data_ar(:, 6), 3)

u = linspace(0,1);
v = polyval(p,u) 

figure
plot(data_ar(:, 1), data_ar(:, 6), 'o', u, v, 'k')
grid on
hold on
ylabel("Rн, Ом")
xlabel("I, A")


R_T2 = v(1) % Получили искомое
    
%% Продолжение работы с данными
% Rн(T1)-Rн(T2) <=> 7
% T1-T2 <=> 8
% T1 <=> 9
% (T1+T2)/2 <=> 10
% Lambda <=> 11
data_ar(:, 7) = [data_ar(:, 6)- R_T2]
data_ar(:, 8) = [data_ar(:, 7)./(R_T2*alpha_R)]
data_ar(:, 9) = [data_ar(:, 8) + T2]
data_ar(:, 10) = [(data_ar(:, 9)+ T2)./2]
data_ar(:, 11) = (data_ar(:,2).* data_ar(:, 5))./(2*pi*(L1-L2)*data_ar(:,8))*log(r2/r1)

F = 2*pi*r1*(L1-L2) % Площадь поверхности рабочего участка
epsilon_pr = 0.44 % Степень черноты 
sigma_0 = 5.67*10^(-8) % Постоянная Стефана-Больцмана
% q_изл <=> 12
% (d_Lambda)изл <=> 13
% Lambda с поправкой <=> 14

data_ar(:, 12) = F*epsilon_pr*sigma_0*(data_ar(:, 9).^4 - T2^4)
data_ar(:, 13) = data_ar(:, 12)./(data_ar(:,2).*data_ar(:, 5))
data_ar(:, 14) = (data_ar(:,2).*data_ar(:, 5)-data_ar(:, 12))./(2*pi*(L1-L2)*data_ar(:,8))*log(r2/r1)

data_tab = array2table(data_ar)



writetable(data_tab, "table_8_res.csv")
%% Завис. коэф-та теплопровод. от темп. газа
f = figure
x = [data_ar(:, 10)];
v = [data_ar(:, 11)];

plot(x,v,'o')
hold on
grid on
xlim([297 333])
xlabel("Tг, K")
ylabel("Lambda, Вт/(м*град)")












