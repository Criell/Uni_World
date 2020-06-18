a = [7,5,6,3,6];
flag = 0;
d = a;
for i = 1:L_numbers
   
     d = [d(i) d(d<d(i))]
     if (length(d)== 1) || (a(i) == a(i+1))
     a = [a(1) a(a<a(1))]
     flag = 1;
     d = a;
     end
if flag ~= 1
i = i - 1;
end
end