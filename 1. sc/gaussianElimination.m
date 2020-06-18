function [ sol ] = gaussianElimination(A)

N = size(A);
N = N(1,1);

%   ************************** Checking the solution.
Ax = A(:,1:N);
Bx = A(:,N+1);
X = linsolve(Ax,Bx);

%   ************************** Finding the solution.
    for i=1:N-1
        for j=(i+1):N
            A(j,:) = A(j,:)-(A(j,i)/A(i,i))*A(i,:);
        end
    end

    B = A(:,N+1);
    
    B(N)= B(N)/A(N,N);

    for i=(N-1):-1:1
        for j=N:-1:i+1
            B(i) = B(i)-B(j)*A(i,j);
        end
        B(i) = B(i)/A(i,i);
    end

%   ************************** Checking that the system has a solution.    
    if abs(det(Ax))<exp(-20)
       disp('Unsolvable system'); 
    else
       sol = B;
    end
    
    
    if abs(B-X)<exp(-20)
       disp('Check')
    else 
       disp('Fail the check')
    end
    

end

