function [theta, dif] = targetangle(vs, d, e)

kappa=0.2; 
g=9.81;
dif = d;
theta = 45;

for angle=45:-1:0 %degrees
    
    x=[0]; 
    y=[0]; 
    dt=0.01; 
    t=[0]; 
    u=[vs*cos((angle/180)*pi)]; 
    v=[vs*sin((angle/180)*pi)]; 

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
     end
     
     newdif = abs(d - x(end-1));
        
     if (newdif < dif)
         dif=newdif;
         bestx=x;
         besty=y;
         theta=angle;  
     end
end

plot(bestx,besty);

if (dif(end)>e)
    theta = NaN;
end

disp('Theta:')
disp(theta)

disp('Difference:')
disp(dif)
    
end


