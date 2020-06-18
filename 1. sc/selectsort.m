% Sript will sort ascendently a list of numbers.

% This scrip will ask for a list of numbers and they will store in the Variable a.
a = input('Please enter a list of numbers: ');
disp (a)

%This nestedloop will interated the size of the array less 1 position (variable n-1) 
%and during this loop it will interated descendingly the size of the array less 1 position every loop  
%It will sort the list of numbers ascendent and then it will print them

n = length(a);                  %n = size(a);

for i=1:(n-1)                   %i=1:(n(2)-1)
     min_index = i;
     
    for j=i+1:n                 %j=i+1:n(2)
        
        if a(j)<a(min_index)
           min_index = j;
        end 
        
    end
    
    temp = a(i);
    a(i) = a(min_index);
    a(min_index) = temp; 
    disp(a)    

end
