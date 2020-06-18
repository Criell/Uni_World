

function [output] = rouletteTactic(T,w)
p = 0;
c = [zeros(1,37)]; 
pvex = [0];
tvex = [0];

for t = 1:T
    [minval minind] = min(c);
    N = minind;
    R = floor(rand*37);
    
    if R == N
        p = p+35*w;
    else
        p = p-w;
    end
    
    output = p;
    c(R+1) = c(R+1)+1;
    xnew = p(end);
    tvexnew = t(end);
    pvex = [pvex xnew];
    tvex = [tvex tvexnew];
   
end
plot(tvex,pvex);
