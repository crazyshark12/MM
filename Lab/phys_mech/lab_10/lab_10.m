%Home_work
%Initial data
R = 1500;
C = 320*10^-12;
t = [0 1 2 3 4 5]*10^-6;
tau = R*C;
tau_100 = 100*tau;
u_m = 5;
tau_m = 5*10^-6;
f = [0 2 5 10 20 50 100 300 500 700 1000]*1000;
omega = 2*pi*f;
f2 = [0 2 10 20 50 100 200 400 600 800 1000]*1000;
omega2 = 2*pi*f2;

%1
u_r = zeros(1, 6);
for i = 1:6
    u_r(i) = u_m*(exp(-t(i)/tau));
end
fprintf('\nTABLE1');
fprintf('\nU_R');
fprintf('\n %f',u_r);
fprintf('\n');
fprintf('\n tau');
fprintf('\n %f',tau);
fprintf('\n');

% figure
% plot(t, u_r, 'o');
% title('U_R(t), 𝜏=RC');
% xlabel('t, с');
% ylabel('U_R, В');
% xlim([0 6*10^-6]);
% ylim([0 6]);

u_r100 = zeros(1, 6);
for i =1:6
    u_r100(i) = u_m*(exp(-t(i)/tau_100));
end
fprintf('\nU_R100');
fprintf('\n %f',u_r100);
fprintf('\n');

% figure
% plot(t, u_r100, 'o');
% title('U_R(t), 𝜏=100*RC');
% xlabel('t, с');
% ylabel('U_R, В');
% xlim([0 6*10^-6]);
% ylim([4 5.2]);

%2
A = zeros(1, 11);
for i = 1:11
    A(i) = omega(i)*tau/sqrt(1+(omega(i)*tau)^2);
end
phi = zeros(1, 11);
for i = 1:11
    phi(i) = pi/2 - atan(omega(i)*tau);
end

fprintf('\nTABLE2');
fprintf('\nA');
fprintf('\n %f',A);
fprintf('\n');
fprintf('\nphi');
fprintf('\n %f',phi);
fprintf('\n');

% figure
% plot(f, A, 'o');
% title('A(f), 𝜏=RC');
% xlabel('f, Гц');
% ylabel('A, B');

% figure
% plot(f, phi, 'o');
% title('ф(f), 𝜏=RC');
% xlabel('f, Гц');
% ylabel('ϕ, рад');
 

A_100 = zeros(1, 11);
for i = 1:11
    A_100(i) = omega(i)*tau_100/sqrt(1+(omega(i)*tau_100)^2);
end
phi_100 = zeros(1, 11);
for i = 1:11
    phi_100(i) = pi/2 - atan(omega(i)*tau_100);
end

fprintf('\nA100');
fprintf('\n %f',A_100);
fprintf('\n');
fprintf('\nphi100');
fprintf('\n %f',phi_100);
fprintf('\n');

% figure
% plot(f, A_100, 'o');
% title('A(f), 𝜏=100*RC');
% xlabel('f, Гц');
% ylabel('A, В');

% figure
% plot(f, phi_100, 'o');
% title('ф(f), 𝜏=100*RC');
% xlabel('f, Гц');
% ylabel('ф, рад');

%3
R2 = 18000;
C2 = 510*10^-12;
tau_m2 = 10^-6;
t2 = [0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1]*10^-6;
tau2 = R2*C2;
tau2_100 = tau2/100;
u_c = zeros(1, 11);
for i = 1:11
   u_c(i) = u_m*(1-exp(-t2(i)/tau2));
end
fprintf('\nTABLE3');
fprintf('\nU');
fprintf('\n %f',u_c);
fprintf('\n');

% figure
% plot(t2, u_c, 'o');
% title('U_c(t), 𝜏=RC');
% xlabel('t, с');
% ylabel('U_c, В');

u_c100 = zeros(1, 11);
for i = 1:11
   u_c100(i) = u_m*(1-exp(-t2(i)/tau2_100));
end
fprintf('\nU100');
fprintf('\n %f',u_c100);
fprintf('\n');

% figure
% plot(t2, u_c100, 'o');
% title('U_c(t), 𝜏=RC/100');
% xlabel('t, c');
% ylabel('U_c, B');

delta_u = 0.5*u_m*(tau_m2/tau2)^2;
delta = 0.5*tau_m2/tau2;


fprintf('\nАбсолютная погрешность: %f', delta_u);
fprintf('\nОтносительная погрешность: %f', delta);


%4
A2 = zeros(1, 11);
for i = 1:11
    A2(i) = 1/sqrt(1+(omega2(i)*tau2)^2);
end

phi2 = zeros(1, 11);
for i = 1:11
    phi2(i) = -atan(omega2(i)*tau2);
end

fprintf('\nTABLE4');
fprintf('\nA');
fprintf('\n %f',A2);
fprintf('\n');
fprintf('\nphi');
fprintf('\n %f',phi2);
fprintf('\n');

% figure
% plot(f, A2, 'o');
% title('A(f), 𝜏=RC');
% xlabel('f, Гц');
% ylabel('A, В');

% figure
% plot(f, phi2, 'o');
% title('ф(f), 𝜏=RC');
% xlabel('f, Гц');
% ylabel('ф, рад');


A2_100 = zeros(1, 11);
for i = 1:11
    A2_100(i) = 1/sqrt(1+(omega2(i)*tau2_100)^2);
end

phi2_100 = zeros(1, 11);
for i = 1:11
    phi2_100(i) = -atan(omega2(i)*tau2_100);
end

fprintf('\nA');
fprintf('\n %f',A2_100);
fprintf('\n');
fprintf('\nphi');
fprintf('\n %f',phi2_100);
fprintf('\n');

% figure
% plot(f, A2_100, 'o');
% title('A(f), 𝜏=RC/100');
% xlabel('f, Гц');
% ylabel('A, В');

% figure
% plot(f, phi2_100, 'o');
% title('ф(f), 𝜏=RC/100');
% xlabel('f, Гц');
% ylabel('ф, рад');

%experiment
A1_exp = readmatrix('U1.txt');
A2_exp = readmatrix('U2.txt');
A33_exp = readmatrix('A1.txt');
A44_exp = readmatrix('A2.txt');
u1_exp = A1_exp(1:end, 1);
u1_100_exp = A1_exp(1:end, 2);
u2_exp = A2_exp(1:end, 1);
u2_100_exp = A2_exp(1:end, 2);
A1_exp = A33_exp(1:end, 1);
A1_100_exp = A33_exp(1:end, 2);
A2_exp = A44_exp(1:end, 1);
A2_100_exp = A44_exp(1:end, 2);
u_m_exp = 5;
tau_m1_exp = 5*10^-6;
tau_m2_exp = 10^-6;
R1_exp = 1500;
C1_exp = 320*10^-12;
R2_exp = 18000;
C2_exp = 510*10^-12;
tau1_exp = R1_exp*C1_exp;
tau2_exp = R2_exp*C2_exp;
t1_exp = [0 1 2 3 4 5]*10^-6;
t2_exp = [0 0.1 0.2 0.3 0.4 0.5 0.6 0.7 0.8 0.9 1]*10^-6;
f1_exp = [2 5 10 20 50 100 300 500 700 1000]*1000;
f2_exp = [2 10 20 50 100 200 400 600 800 1000]*1000;


figure
hold on
plot(t1_exp, u1_exp, 'o');
title('U_R(t), 𝜏=RC');
xlabel('t, с');
ylabel('U_R, В');
plot(t, u_r, 'o-');
hold off

figure
hold on
plot(t1_exp, u1_100_exp, 'o');
title('U_R(t), 𝜏=100*RC');
xlabel('t, с');
ylabel('U_R, В');
plot(t, u_r100, 'o-');
hold off

figure
hold on
plot(t2_exp, u2_exp, 'o');
title('U_c(t), 𝜏=RC');
xlabel('t, с');
ylabel('U_c, В');
plot(t2, u_c, 'o-');
hold off

figure
hold on
plot(t2_exp, u2_100_exp, 'o');
title('U_c(t), 𝜏=RC/100');
xlabel('t, с');
ylabel('U_c, В');
plot(t2, u_c100, 'o-');
hold off

figure
hold on
plot(f1_exp, A1_exp, 'o');
title('A(f), 𝜏=RC');
xlabel('f, Гц');
ylabel('A, B');
plot(f, A, 'o-');
hold off

figure
hold on
plot(f1_exp, A1_100_exp, 'o');
title('A(f), 𝜏=100*RC');
xlabel('f, Гц');
ylabel('A, B');
plot(f, A_100, 'o-');
hold off

figure
hold on
plot(f2_exp, A2_exp, 'o');
title('A(f), 𝜏=RC');
xlabel('f, Гц');
ylabel('A, B');
plot(f, A2, 'o-');
hold off

figure
hold on
plot(f2_exp, A2_100_exp, 'o');
title('A(f), 𝜏=RC/100');
xlabel('f, Гц');
ylabel('A, B');
plot(f, A2_100, 'o-');
hold off