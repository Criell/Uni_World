
function insertsort(a) 

 
 a = input ('List: ');
 L_numbers = length(a);

 
 tic
   
 for i = 1:L_numbers
     
     j=[1:L_numbers];
     
     small = a(i)> a(j);           
     big = a(i)<= a(j);
     a=[a(logical(small)), a(logical(big))];
     
     small2 = a(i)> a(j);
     big2 = a(i)<= a(j);
     a=[a(logical(small2)), a(logical(big2))]; 
     
 end
 disp(a)

    
%   for i = 2:L_numbers
%        value = a(i);
%        j=i-1;
%        insert = true;
%       
%       while insert == true
%              if a(j)>value
%                 a(j+1)=a(j);
%                 j = j-1;
%                 if j<1
%                    insert = false;
%                 end
%              else
%                  insert = false;
%              end
%        end
%    a(j+1) = value;
    
%    end

toc
end