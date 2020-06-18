
function insertsortalpha(a) 
 
 a = input ('List: ');
 
 L_numbers = size(a);
 Colum = L_numbers(1,1);
 L_numbers = L_numbers(1,2);
 
 tic
   
 for i = 1:L_numbers
     j= 1:Colum;
     
     if alphacmp(a) == true
        close_a = a(i)> a(j);
        close_z = a(i)<= a(j);
        a=[a(logical(close_a),:); a(logical(close_z),:)];
     end 
          
 end
 
 disp(a)
 
toc
end