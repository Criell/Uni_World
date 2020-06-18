disp('Item costs F = $1100. Currently Saving P = $1000.')
i1 = 0.06;
i2 = 0.065;
F = 1100;
P1 = 1000;
P2 = P1-5;

disp(' ')

%Calculate and print months need to save $1.100 with option a.

disp('Option - Bank B')
disp('Interest rate 6.5%. Plus $5 additional')

n1 = (log(F)-log(P1))/log(1+i1/12);
disp(' ')
disp('Months need it to save $1.100 with option a')
Bank_A = ceil(n1)

%Calculate and print months need to save $1.100 with option b.

disp('Option - Bank B')
disp('Interest rate 6%')

n2 = (log(F)-log(P2))/log(1+i2/12);
disp(' ')
disp('Months need it to save $1.100 with option b')
Bank_B = ceil(n2)