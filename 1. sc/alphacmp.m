function b = alphacmp(a)  

L_numbers = size(a);
L_numbers = L_numbers(1,1);

counter = 0;
b=true;

    for i = 2:L_numbers
    
        if a(1,i-1)<a(1,i)
           counter = counter +1;          
        end            
    end
           
    if counter == L_numbers-1
       b = false;
    else 
       b = true;
    end
end