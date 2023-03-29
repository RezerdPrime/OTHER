a = randi([1 10], 1, 3);

len = (a(1)^2 + a(2)^2 + a(3)^2)^0.5;

cosX = a(1) / len;
cosY = a(2) / len;
cosZ = a(3) / len;

grid on; hold on; grid on; xlabel("axis X"); ylabel("axis Y"); zlabel("axis Z");
plot3([0 a(1)], [0 a(2)], [0 a(3)]);

disp(len); disp(cosX); disp(cosY); disp(cosZ);