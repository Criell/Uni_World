% Sript will calculate the square root using Newton-Raphson formula.

% This scrip will ask for a positive real number and it will store it in the Variable a
a = input('Please input a positive real number: ');

while a<0
    a = input('Please input a positive real number: ');
end

% This scrip will also ask for a positive number of interations and it will store it in the Variable N
N = input('Please input the desired number of interations: ');

while N<0
    N = input('Please input the desired number of interations: ');
end

% Now the scrip will set x as the variable of the Newton-Raphson formula
x = a/2;
% and print the result in long format.
format long;
disp(x)

%This loop will interated N times and print the result of the Newton-Raphson formula
for i=1:N
    x = (x + (a/x))/2;
    disp(x)
end

%compute and print the square root of the positive number given using the matlab formula.
disp('MATLAB"s value: ');
matlab_sqrt = sqrt(a);
disp (matlab_sqrt)

%compute the difference between the result from the Newton-Raphson formula
%and the funtion sqrt and then it will print it.
disp('The difference is: ');
difference = matlab_sqrt - x;
disp (difference)