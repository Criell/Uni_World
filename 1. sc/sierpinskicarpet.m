function sierpinskicarpet(x,y,w)

    if w<1
    return;
    end

% Plots the base, left-side, and right-side
% of the triangle.

hold on;

plot([x-w/4 x+w/4],[y-w/4 y-w/4],'r-');
plot([x+w/4 x+w/4],[y-w/4 y+w/4],'r-');
plot([x+w/4 x-w/4],[y+w/4 y+w/4],'r-');
plot([x-w/4 x-w/4],[y+w/4 y-w/4],'r-');

% Recursions to plot the smaller triangles
% at the top, bottom left and bottom right

sierpinskicarpet(x,y-w/3,w/3);
sierpinskicarpet(x,y+w/3,w/3);
sierpinskicarpet(x-w/3,y,w/3);
sierpinskicarpet(x-w/3,y+w/3,w/3);
sierpinskicarpet(x-w/3,y-w/3,w/3);
sierpinskicarpet(x+w/3,y,w/3);
sierpinskicarpet(x+w/3,y-w/3,w/3);
sierpinskicarpet(x+w/3,y+w/3,w/3);
