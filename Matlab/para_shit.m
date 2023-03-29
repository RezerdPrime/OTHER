syms x(y);
syms k x b;

k = 2;
b = 5;
y(x) = k*x + b;

%t = [0,] schtsch

figure;
fplot(x,y);

t1 = 0; t2 = 10; tn = 11;
t = linspace(t1, t2, tn);

M = [11, 11];
p = [2, 2];

x = p(1) * t + M(1);
y = p(2) * t + M(2);

figure;
plot(x,y);

M = [1 2];
N = [3 1];
t1 = 0; t2 = 10; tn = 11;
t = linspace(t1, t2, tn);

x = (N(1) - M(1)) * t + M(1);
y = (N(2) - M(2)) * t + M(2);
figure;
plot(x,y);

a = 5; b = 2;

x = linspace(-a, a, 12*a + 1);
y1 = sqrt(b^2 - ((b^2)*(x.^2)) / a^2);
y2 = -y1;

figure;
plot(x, y1, 'b');
hold on;
plot(x, -y1, 'b');