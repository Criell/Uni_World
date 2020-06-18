kappa=0.2;
g=9.81;
angle=20; %degrees
vs=12;
d=12;
e=1;
x=[0];
y=[0];
u=[vs*cos((angle/180)*pi)];
v=[vs*sin((angle/180)*pi)];
dt=0.01;
t=[0];
while (y(end)>=0)
    xnew=x(end)+u(end)*dt;
    ynew=y(end)+v(end)*dt;
    unew=u(end)-dt*kappa*u(end)*sqrt(u(end)^2+v(end)^2);
    vnew=v(end)-dt*(kappa*v(end)*sqrt(u(end)^2+v(end)^2)+g);
    x=[x xnew];
    y=[y ynew];
    u=[x unew];
    v=[x vnew];
    t=[t dt];
end;
plot(x,y);
