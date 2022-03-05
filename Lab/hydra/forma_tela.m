gamma=0.8075;
rho=0.1212;
nu=0.15*1e-4;
D=0.195;
F=0.5;
a=1.12;
mu=0.992;
S=3.141592*D^2/4;
cmean=1.48;
c1=1/(gamma*mu*F*S)*1e-3;
h=[150 137 126 115 105 95 82 73 60 47 38 21];
X=[500 450 415 370 355 340 290 255 223 175 145 90];
v=sqrt((2*gamma*mu*F.*h)/rho);
cx=c1*a*(X-cmean*h)./h;
Re=D.*v/nu;
plot(Re/100000,cx);
grid on;
set(gca,'XTick',[0:0.1:5],'YTick',[0:0.01:1])
