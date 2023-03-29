% Schkrapt

% Кёнус

clear variables

a = 4; b = 6; c = 100;

x1 = -6;
x2 = 6;
xn = 1001;

y1 = -6;
y2 = 6;
yn = 1001;

%z = c * sqrt(x(i)^2 / a^2 + y(j)^2 / b^2);

x = linspace(x1, x2, xn);
y = linspace(y1, y2, yn);

%z(i,:) = c * sqrt(x(i)^2 / a^2 + y(:)^2 / b^2);

for i = 1 : length(x)
    z(i,:) = c * sqrt(x(i)^2 / a^2 + y(:).^2 / b^2);
%    for j = 1 : length(y)
        
%    end
end

figure
surfc(x, y, -z');
shading Flat
xlabel('да')
colormap('jet')
colorbar
zlim([-c,c])
hold on
surfc(x, y, z');
shading Flat