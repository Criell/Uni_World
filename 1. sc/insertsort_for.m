function insertsort_for(a) 

 
 a = input ('List: ');
 L_numbers = length(a);

 
 tic
  
   for i = 2:L_numbers
        value = a(i);
        j=i-1;
        insert = true;
       
       while insert == true
              if a(j)>value
                 a(j+1)=a(j);
                 j = j-1;
                 if j<1
                    insert = false;
                 end
              else
                  insert = false;
              end
        end
    a(j+1) = value;
    
    end
disp(a)
toc
end