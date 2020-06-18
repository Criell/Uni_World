f = inline('x^3 + x - 3');
a = 0;
b = 10;
e = 1e-3;
[sol, steps] = bisection_method(f,a,b,e);