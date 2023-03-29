a = randi([1, 10], 1, 2);
b = randi([1, 10], 1, 2);

aLen = (a(1)^2 + a(2)^2)^0.5;
bLen = (b(1)^2 + b(2)^2)^0.5;

cos_angle = (a(1)*b(1) + a(2)*b(2)) / ((a(1)^2 + a(2)^2)^0.5 * (b(1)^2 + b(2)^2)^0.5);
sin_angle = (1 - cos_angle^2)^0.5;

ScPr = aLen * bLen * cos_angle;
disp("Scalar prod: "); disp(ScPr);

cLen = aLen * bLen * sin_angle;

disp("Vector prod: "); disp(cLen);

hold on; grid on; xlabel('X axis'); ylabel('Y axis'); zlabel('Z axis'); 
plot([0 a(1)], [0 a(2)], 'linewidth', 3);
plot([0 b(1)], [0 b(2)], 'linewidth', 3);
plot3([0 0], [0 0], [0 cLen], 'linewidth', 3);