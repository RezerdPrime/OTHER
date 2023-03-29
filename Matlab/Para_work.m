% 1) .mat
% 2) .txt
% 3) .xls, .nc
% load('matrix.mat') - file open
% save('matrix1', 'a', 'b') - file save
% save('matrix', 'x', '-append') - adding file without data deleting
% dlmread('matrix.txt', '\t') - reading with special separator
%-Scheisse
% dlmwrite('hueta.txt', B, '\t', 'precision', '%.3f') - writing with special separator
% da = fopen('matrex.txt', 'w'/'r') - даст ебучий номер потока
% a = fscanf(da, '%f') - запись из файла, имея только ебучий номер потока
% fclose(da) - закрыть нахуй
% fprintf(fid, B) - запись в файл
% ncdisp('TOPO.nc')
% lon1 = ncread('TOPO.nc', 'lon')


%------------------------------------------------------------------------------------
% New lection with Matlab

%Фюнкцыы ыгыгыы

% кватернионы - вектора из 4 элементов, при помощи которых можно описать
% хуйню в 3д

%function[returnable_shit] = func_name(arg1, arg2..)
% some code;
%end

% varargin <- если хз сколько переменных

% a = varargin{1};
% nargin <- кол-во внесённых (вообще всех внесённых) элементов


% ooo neeeeeet vlozhennje funkcii

% символьные вычисления
% expand - раскрытие скобок
% simplify - упрощение дроби
% factor - разложение на множители
% double(f) - символьная переменная в тип дабл
% subs(f, var, value) - подстановка значения в переменную в выражении

% >> syms x y
% >> point = solve (y == eq, y = eq2, [x y])
% возвращает стракт (структуру)

% point.x - возвращает решение (доступ)
% только блять это символ вообще-то
% y1 = double(point.y)

% diff(f, var, num) - дифференцирует выражение по переменной порядка нум

% int(f, var) - неопределённый интеграл
% int(f, var, a, b) - определённый интеграл в отрезке а и б

