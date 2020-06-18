function [output]= roulette(T,w,N)

p = 0;  
pvex = [0];
tvex = [0];

for t=1:T
    R= floor(37*rand);
    
    if R == N
        p = p+35*w; 
    else
        p = p-w; 
    end
    
    pvex = [pvex p];
    tvex = [tvex t];

end

plot(tvex,pvex);
output = p;

