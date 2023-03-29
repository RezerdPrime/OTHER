a = randi([1, 10], 1, 2);
b = randi([1, 10], 1, 2);

c = a - b; d = a + b;

hold on; grid on; xlabel("axis X"); ylabel("axis Y"); title("PLOT^1 (a and b)");
plot([0 a(1)], [0 a(2)]);
plot([a(1) (b(1) + a(1))], [a(2) (b(2) + a(2))]);

figure;

hold on; grid on; xlabel("axis X"); ylabel("axis Y");  title("PLOT^2 (a+b and a-b)");
plot([0 d(1)], [0 d(2)]);
plot([d(1) (c(1) + d(1))], [d(2) (c(2) + d(2))]);