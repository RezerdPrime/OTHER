% 1) .mat
% 2) .txt
% 3) .xls, .nc
% load('matrix.mat') - file open
% save('matrix1', 'a', 'b') - file save
% save('matrix', 'x', '-append') - adding file without data deleting
% dlmread('matrix.txt', '\t') - reading with special separator
%-Scheisse
% dlmwrite('hueta.txt', B, '\t', 'precision', '%.3f') - writing with special separator
% da = fopen('matrex.txt', 'w'/'r') - ���� ������ ����� ������
% a = fscanf(da, '%f') - ������ �� �����, ���� ������ ������ ����� ������
% fclose(da) - ������� �����
% fprintf(fid, B) - ������ � ����
% ncdisp('TOPO.nc')
% lon1 = ncread('TOPO.nc', 'lon')


%------------------------------------------------------------------------------------
% New lection with Matlab

%������� ������

% ����������� - ������� �� 4 ���������, ��� ������ ������� ����� �������
% ����� � 3�

%function[returnable_shit] = func_name(arg1, arg2..)
% some code;
%end

% varargin <- ���� �� ������� ����������

% a = varargin{1};
% nargin <- ���-�� �������� (������ ���� ��������) ���������


% ooo neeeeeet vlozhennje funkcii

% ���������� ����������
% expand - ��������� ������
% simplify - ��������� �����
% factor - ���������� �� ���������
% double(f) - ���������� ���������� � ��� ����
% subs(f, var, value) - ����������� �������� � ���������� � ���������

% >> syms x y
% >> point = solve (y == eq, y = eq2, [x y])
% ���������� ������ (���������)

% point.x - ���������� ������� (������)
% ������ ����� ��� ������ ������-��
% y1 = double(point.y)

% diff(f, var, num) - �������������� ��������� �� ���������� ������� ���

% int(f, var) - ������������� ��������
% int(f, var, a, b) - ����������� �������� � ������� � � �

