data = readtable('lab_9.csv') % Промежутки времени между характерными точками соседних эхо-импульсов

tau_mean = [sum(data{:,:}, 1) ./ sum(data{:,:}~=0)].' % Средний временной интервал между эхо-импульсами,

% Найдем погрешность delta_tau (как среднеквадратич. погрешность) 
MSE = [];
i = 1;
for column_name = data.Properties.VariableNames
    col_MSE = (sum((nonzeros(data{:,column_name}) - tau_mean(i)).^2)/...
        (length(nonzeros(data{:,column_name}))*(length(nonzeros(data{:,column_name}))-1))).^0.5;
    MSE = cat(1,MSE,[col_MSE]);
    i = i + 1;
end

MSE % Погрешность delta_tau

len = readtable('lab_9_L.csv'); % Длина образца

len.V = 2*len.L./(tau_mean); % Скорость распределения волны

d_L = 10^(-5) % Погрешность измерительного прибора

% Погрешность скорости распределения волны ( по формуле погрешности косв.
% измер.)
len.d_V = ((2*len.L./(tau_mean.^2)).^2.*(MSE).^2 +...
    (2*(tau_mean.^(-1))).^2*(d_L).^2).^0.5


% Расчет коэффициента Пуассона и модуля Юнга для второго образца
V_l = len{1,"V"}
dV_l = len{1,"d_V"}
V_t = len{3,"V"}
dV_t = len{3,"d_V"}

ro = 2600
mu = (V_l^2-2*V_t^2)/(2*(V_l^2-V_t^2)) % Коэф. Пуассона
E = 2*ro*V_t^2*(1+mu) % Модуль Юнга

% Погрешность коэф. Пуассона (по формуле погрешности косв. измер.)
delta_mu = ((-V_l^2*V_t/(V_l^2-V_t^2)^2)^2*(dV_t)^2 +...
    (V_l*V_t^2/(V_l^2-V_t^2)^2)^2*(dV_l)^2)^0.5 

% Погрешность модуля Юнга (по формуле погрешности косв. измер.)
delta_E = ((2*ro*V_t*(3*V_l^4-8*V_l^2*V_t^2+4*V_t^4)/(V_l^2-V_t^2)^2)^2*(dV_t)^2 +...
    (2*ro*V_l*V_t^4/(V_l^2-V_t^2)^2)^2*(dV_l)^2)^0.5 












