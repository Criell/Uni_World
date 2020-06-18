%Man_weeks = [1,2,1,2];
%Kilograms_A = [6,5,3,2]; 
%Boxes_B = [3,4,9,12];

lower_bound = [0;0;0;0];
upper_bound = [inf; inf; inf; inf];

A = [1,2,1,2; 6,5,3,2; 3,4,9,12];
b = [20; 100; 75];
f = [6;4;7;5];
f =-f;
[x, fval] = linprog (f,A,b,[],[],lower_bound,upper_bound);
x
-fval