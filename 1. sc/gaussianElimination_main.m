disp ('***A1***')
A1 = [ 2 1 -1 8 ; -3 -1 2 -11 ; -2 1 2 -3 ]

[sol1] = gaussianElimination(A1)

disp ('***A2***')
A2 = [ 4 2 7 3 12 ; 32 6 2 7 8 ; 14 2 6 6 5 ; 9 9 10 4 13 ]
[sol2] = gaussianElimination(A2)

disp ('***A3***')
A3 = rand(10,11);
[sol3] = gaussianElimination(A3)

disp ('***A4***')
A4 = rand(1000,1001);
[sol4] = gaussianElimination(A4)

disp ('***A5***')
A5 = [ 2 1 -1 8 ; -3 1.5 3 -4.5 ; -2 1 2 -3 ]
gaussianElimination(A5)

disp ('***A6***')
A6 = [ 4 2 7 3 12 ; 32 6 2 7 8 ; 14 2 6 6 5 ; 12 6 21 9 36 ]
gaussianElimination(A6)
