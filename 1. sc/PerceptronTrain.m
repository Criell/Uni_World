
function [w] = PerceptronTrain(x,y,eta,T)

    w = 0;
    imp_w = 0; 
    [n,~] = size(x);
  
  for t =1:T
    for i = 1:n
        if (y(i)*(x(i,:)'.*w) <= 0)
            imp_w = imp_w + (y(i)*x(i,:));
        end
    end
    
    w = w + eta * imp_w;
  end
   
end