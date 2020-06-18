function sierpinski(cx,cy,b)
% Plots the Sierpinski Triangle.
% (cx,cy) are the centre coordinates of
% the starting/outermost triangle.
% b is the length of base (largest side) of
% the starting triangle.
% The base condition is b==1, i.e. the
% recursion terminates when the length
% of the triangle is less than this
% base condition.
if b<1
return;
end
% Makes sure previous lines don't get
% deleted.
hold on;
% Plots the base, left-side, and right-side
% of the triangle.
plot([cx-b/2 cx+b/2],[cy-b*sqrt(3)/2 cy-b*sqrt(3)/2],'b-');
plot([cx-b/2 cx],[cy-b*sqrt(3)/2 cy+b*sqrt(3)/2],'b-');
plot([cx+b/2 cx],[cy-b*sqrt(3)/2 cy+b*sqrt(3)/2],'b-');
% Recursions to plot the smaller triangles
% at the top, bottom left and bottom right
sierpinski(cx,cy+b*sqrt(3)/4,b/2);
sierpinski(cx-b/4,cy-b*sqrt(3)/4,b/2);
sierpinski(cx+b/4,cy-b*sqrt(3)/4,b/2);