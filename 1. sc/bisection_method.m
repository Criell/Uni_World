function [ sol, steps ] = bisection_method(f,a,b,e)
        
    steps = 0;    
    fa = f(a);
    fb = f(b);
    m = (a+b)/2;
    fm = f(m);
        
    while abs(fm)>= e
        
        if fa*fm < 0
           b = m;
           fb = f(m);   
           
        else
           a = m;
           fa = f(m);

           
        end
          m = (a+b)/2;
           fm = f(m);
           
        steps = steps+1;
        disp ('step ')
        disp(steps)
        disp (', x = ')
        disp(fm)
    end
    
    sol = m;
    disp (sol)
           
end



