%% Работа с данными
data = readtable("lab8_1.csv") % Таблица со столбцами V1, I, U1, U2
alpha_R = 6.8*10^(-3) % Температур. коэф. сопротивления
T2 = 296.15 % Абс. темп. трубки
L1 = 0.18 
L2 = 0.03
r1 = 0.0001
r2 = 0.004

data.('U1-U2') = [data{:, 3} - data{:, 4}]
data.('Rн(T1)') = [data{:, 5}./data{:, 2}]

%% Получение Rн(T2) c помощью экстраполяции (продолжаем график к нулю)
% Будем продолжать многочлен 4 степени
x = [0.1:0.1:0.8];
y = data{3:end, 6}
p = polyfit(x,y,4) % узнаем коэф-ты многочлена степени 4

u = linspace(0,1);
v = polyval(p,u) % Оцениваем многочлен p в каждой точке u

figure 
plot(x,y,'o')
grid on
hold on
plot(u,v)
hold off
ylabel("Rн, Ом")
xlabel("I, A")


R_T2 = v(1) % Получили искомое

%% Продолжение работы с данными
data.('Rн(T1)-Rн(T2)') = [data{:, 6} - R_T2]
data.("T1-T2") = [data{:, 7}./(R_T2*alpha_R)]
data.("T1") = [data{:, 8}+T2]
data.("(T1+T2)/2") = [(data{:, 9}+T2)./2]
data.("Lambda") = (data{:,2}.*data{:, 5})./(2*pi*(L1-L2)*data{:,8})*log(r2/r1)

F = 2*pi*r1*(L1-L2) % Площадь поверхности рабочего участка
epsilon_pr = 0.44 % Степень черноты 
sigma_0 = 5.67*10^(-8) % Постоянная Стефана-Больцмана
data.("q_изл") = F*epsilon_pr*sigma_0*(data{:, 9}.^4 - T2^4)
data.("(d_Lambda)изл") = data{:, 12}./(data{:,2}.*data{:, 5})
data.("Lambda с поправкой") = (data{:,2}.*data{:, 5}-data{:, 12} )./(2*pi*(L1-L2)*data{:,8})*log(r2/r1)

writetable(data, "table_8_res.csv")
%% Завис. коэф-та теплопровод. от темп. газа
f = figure
x = [data{:, 10}];
v = [data{:, 11}];
plot(x,v,'o')
hold on
grid on
xlabel("Tг, K")
ylabel("Lambda, Вт/(м*град)")












