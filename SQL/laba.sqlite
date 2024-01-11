---------------------------------------------------- Номера 1-8 --------------------------------------------------------

---------------------------------------------------- №1
CREATE TABLE IF NOT EXISTS Teachers (
    ID INTEGER PRIMARY KEY,
    FullName VARCHAR(50),
    Sex VARCHAR(1) CHECK (Sex IN ('M', 'F')),
    BirthDate DATE,
    AcademicDegree VARCHAR(50)
);

---------------------------------------------------- №2
CREATE TABLE IF NOT EXISTS Students (
    ID INTEGER PRIMARY KEY,
    FullName VARCHAR(50),
    Sex VARCHAR(1) CHECK (Sex IN ('M', 'F')),
    BirthDate DATE,
    CertificateNumber INTEGER
);

---------------------------------------------------- №3
CREATE TABLE IF NOT EXISTS Groups (
    ID INTEGER PRIMARY KEY,
    Specialization_ID INTEGER,
    GroupName VARCHAR(50),
    Сourse INTEGER,
    FOREIGN KEY (Specialization_ID) REFERENCES Specializations(ID)
);

---------------------------------------------------- №4
CREATE TABLE IF NOT EXISTS Specializations (
    ID INTEGER PRIMARY KEY,
    SpecializationName VARCHAR(50)
);

---------------------------------------------------- №5
CREATE TABLE IF NOT EXISTS Activity (
    ID INTEGER PRIMARY KEY,
    Student_ID INTEGER,
    Group_ID INTEGER,
    TimeOfAdmission DATETIME,
    TimeOfExpulsion DATETIME,
    SemesterOfExpulsion INTEGER CHECK (SemesterOfExpulsion BETWEEN 1 AND 8 AND null),
    FOREIGN KEY (Student_ID) REFERENCES Students(ID),
    FOREIGN KEY (Group_ID) REFERENCES Groups(ID)
);

---------------------------------------------------- №6
CREATE TABLE IF NOT EXISTS Disciplines (
    ID INTEGER PRIMARY KEY,
    DisciplineName VARCHAR(50)
);

---------------------------------------------------- №7
CREATE TABLE IF NOT EXISTS Subjects (
    ID INTEGER PRIMARY KEY,
    Group_ID INTEGER,
    Discipline_ID INTEGER,
    Year INTEGER,
    Semester INTEGER CHECK (Semester BETWEEN 1 AND 8),
    GradeType VARCHAR(10) CHECK (GradeType IN ('Credit', 'Exam')),
    Teacher_ID INTEGER,
    FOREIGN KEY (Group_ID) REFERENCES Groups(ID),
    FOREIGN KEY (Discipline_ID) REFERENCES Disciplines(ID),
    FOREIGN KEY (Teacher_ID) REFERENCES Teachers(ID)
);

---------------------------------------------------- №8
CREATE TABLE IF NOT EXISTS Grades (
    Student_ID INTEGER,
    Subject_ID INTEGER,
    Grade INTEGER CHECK (Grade BETWEEN 0 AND 5),
    GradeTime DATETIME NOT NULL,
    FOREIGN KEY (Subject_ID) REFERENCES Subjects(ID),
    FOREIGN KEY (Student_ID) REFERENCES Students(ID)
);


---------------------------------------------------- Номера 9-18 -------------------------------------------------------

---------------------------------------------------- №9

-- Дисциплины
INSERT INTO Disciplines (DisciplineName)
VALUES ('Прога комп игр'), ('Наш любимый проектик SUSCHTCH'),
       ('Проектирование термоядерного реактора'), ('оопе на питоне'),
       ('Поклонение джаваскрипту'), ('Компиляторы кленина'),
       ('Основы коммуникации на вымершем языке'), ('Основы прокрастинации');

DELETE FROM Disciplines
WHERE DisciplineName == 'Основы коммуникации на вымершем языке' OR DisciplineName == 'Основы прокрастинации';

-- Преподы
INSERT INTO Teachers (FullName, Sex, BirthDate, AcademicDegree)
VALUES ('зубенко михаил петрович', 'F', '1991-07-22', 'мафиозик'),
       ('сущенко андрей андреич', 'M', '0666-01-01', 'GODNESS'),
       ('Eden Lichmer', 'M', '2010-07-09', 'Интеграловед'),
       ('Артемий Поповкин', 'M', '2100-01-01', 'филосаф'),
       ('аля знаток', 'F', '1337-08-22', 'Лектор по бекенду'),
       ('сржа глущенко', 'M', '2001-01-02', 'Терверофил');

DELETE FROM Teachers
WHERE AcademicDegree == 'GODNESS'
OR CAST(strftime('%Y', BirthDate) AS INTEGER) > 2012;

-- Студики
INSERT INTO Students (FullName, Sex, BirthDate, CertificateNumber)
VALUES ('Даниил Плешанов', 'M', '2011-09-11', 120388),
       ('НЕданиил Плешанов', 'F', '1102-03-29', 134017),
       ('Артём Громыко', 'M', '1997-11-17', 299740),
       ('Сашак', 'M', '0001-03-02', 000001),
       ('Алиса Матвеева', 'F', '2015-05-28', 777219),
       ('Динамо Лутт', 'F', '2022-08-10', 352667),
       ('SUSCHTSCH', 'M', '0000-00-00', 000000),
       ('STPN-off-MK9013', 'F', '0000-00-00', 0000000);

DELETE FROM Students
WHERE CertificateNumber == 0;

-- Специальности
INSERT INTO Specializations (SpecializationName)
VALUES ('pmi'), ('mkn'), ('pi'), ('kb');

-- Группы
INSERT INTO Groups (Specialization_ID, GroupName, Сourse)
VALUES (1, 'пымышата', 1),
       (1, 'PMI_PODVAL', 3),
       (2, 'MKN_GENEZIS', 2),
       (2, 'mknytiki', 1),
       (3, 'pipipipi', 1),
       (3, 'PROGRAMNAYA_KRINZHENERIA', 4),
       (3, 'PI_OVER_ALL', 1),
       (4, 'KYBER_BEZ', 3),
       (4, 'kbanchiki', 1),
       (1, '', 0);

DELETE FROM Groups
WHERE ID == 7 OR GroupName == '';

-- Предметы
INSERT INTO Subjects (Group_ID, Discipline_ID, Year, Semester, GradeType, Teacher_ID)
VALUES (1, 1, 1879, 2, 'Credit', 1),
       (3, 2, 2024, 4, 'Exam', 6),
       (9, 6, 2000, 8, 'Exam', 5),
       (2, 4, 2022, 3, 'Credit', 3),
       (3, 3, 2017, 3, 'Exam', 1),
       (4, 5, 2011, 6, 'Exam', 1),
       (4, 2, 2010, 2, 'Credit', 3);

DELETE FROM Subjects
WHERE Discipline_ID = 4;


---------------------------------------------------- №10

INSERT INTO Activity (Student_ID, Group_ID, TimeOfAdmission, TimeOfExpulsion, SemesterOfExpulsion)
VALUES (3, 3, '2022-09-29', null, null),
       (2, 6, '2020-01-03', '2021-07-11', 1),
       (6, 3, '2022-09-21', null, null);

-- DELETE FROM Activity
-- WHERE Student_ID == 6 OR Student_ID == 2;

INSERT INTO Activity (Student_ID, Group_ID, TimeOfAdmission, TimeOfExpulsion, SemesterOfExpulsion)
VALUES (2, 3, '2025-01-03', null, null),
       (1, 3, '2023-02-16', null, null),
       (5, 3, '2022-10-09', null, null);


---------------------------------------------------- №11

SELECT COUNT(*) FROM Teachers
WHERE CAST(strftime('%Y', BirthDate) AS INTEGER) BETWEEN 0 AND 2005
UNION ALL
SELECT COUNT(*) FROM Students
WHERE CAST(strftime('%Y', BirthDate) AS INTEGER) BETWEEN 0 AND 2012;


---------------------------------------------------- №12

WITH TotPeople AS (
    SELECT FullName FROM Teachers
    WHERE BirthDate BETWEEN DATE('0001-01-01') AND DATE('2000-01-01')
    GROUP BY BirthDate
    UNION ALL
    SELECT FullName FROM Students
    WHERE BirthDate BETWEEN DATE('0001-01-01') AND DATE('2000-01-01')
    GROUP BY BirthDate
    )
SELECT * FROM TotPeople;


---------------------------------------------------- №13

SELECT Subjects.Group_ID, Teachers.FullName
FROM Subjects
JOIN Teachers ON Subjects.Teacher_ID == Teachers.ID
WHERE Subjects.Year BETWEEN 1900 AND 2025;


---------------------------------------------------- №14

SELECT FullName FROM Activity
JOIN Students ON Student_ID == Students.ID
WHERE Group_ID == 3 AND
      TimeOfAdmission BETWEEN DATE('2022-01-01') AND DATE('2022-12-30');


---------------------------------------------------- №15

SELECT Activity.Student_ID, Groups.GroupName
FROM Activity
JOIN Groups ON Activity.Group_ID == Groups.ID
WHERE Activity.Student_ID == 6; --2


---------------------------------------------------- №16

INSERT INTO Grades (Student_ID, Subject_ID, Grade, GradeTime)
VALUES (1, 2, 2, '2025-05-02'),
       (2, 2, 4, '2021-03-23'),
       (5, 2, 3, '2022-12-04'),
       (2, 5, 3, '2018-09-29'),
       (1, 5, 5, '2020-09-29'),
       (5, 5, 1, '2000-09-29');


---------------------------------------------------- №17

SELECT Students.Fullname AS name, Disciplines.DisciplineName AS discipline, grade FROM Grades
JOIN Students ON Grades.Student_ID = Students.ID
JOIN Subjects ON Grades.Subject_ID = Subjects.ID
JOIN Disciplines ON Subjects.Discipline_ID = Disciplines.ID
ORDER BY name, discipline, grade;


---------------------------------------------------- №18

SELECT g.GroupName, d.DisciplineName, AVG(Grade) AS AverageGrade
FROM Groups g
JOIN Subjects s ON g.ID = s.Group_ID
JOIN Disciplines d ON s.Discipline_ID = d.ID
JOIN Grades gr ON s.ID = gr.Subject_ID
GROUP BY g.GroupName, d.DisciplineName;


---------------------------------------------------- Номера 19-28 ------------------------------------------------------

DROP TRIGGER IF EXISTS NO_GroupDel;
DROP TRIGGER IF EXISTS NO_SpecializationDel;
DROP TRIGGER IF EXISTS YES_SpecNoGroupsDel;
DROP TRIGGER IF EXISTS NO_DisciplineDel;
DROP TRIGGER IF EXISTS NO_DupTeachers;
DROP TRIGGER IF EXISTS NO_DupStudents;
DROP TRIGGER IF EXISTS AutoExpulsion;
DROP TRIGGER IF EXISTS NO_AddGradeOhneGroup;
DROP TRIGGER IF EXISTS DelPrevGrades;
DROP TRIGGER IF EXISTS NO_GradeFromPast;


---------------------------------------------------- №19

CREATE TRIGGER NO_GroupDel
BEFORE DELETE ON Groups
WHEN EXISTS(SELECT * FROM Activity WHERE Group_ID == OLD.ID)
BEGIN
    SELECT RAISE(ABORT, 'Не удалять группы со студентами');
END;

DELETE FROM Groups
WHERE Groups.ID == 3;


---------------------------------------------------- №20

CREATE TRIGGER NO_SpecializationDel
BEFORE DELETE ON Specializations
WHEN EXISTS (SELECT Activity.timeofadmission
             FROM Groups JOIN Activity ON Activity.group_id = Groups.id
             WHERE Specialization_ID = OLD.ID and Activity.timeofadmission IS NOT NULL)
BEGIN
    SELECT RAISE(ABORT, 'Не удалять специальности с челами');
END;

DELETE FROM Specializations
WHERE Specializations.ID == 2;


---------------------------------------------------- №21

CREATE TRIGGER YES_SpecNoGroupsDel
AFTER DELETE ON Groups
WHEN NOT EXISTS (SELECT * FROM Groups WHERE Specialization_ID = OLD.Specialization_ID)
BEGIN
    DELETE FROM Specializations WHERE ID = OLD.Specialization_ID;
END;

INSERT INTO Specializations (SpecializationName) VALUES ('smertniki');
INSERT INTO Groups (Specialization_ID, GroupName, Сourse)
VALUES (5, 'DEATH', 1),
       (5, 'TOD', 2),
       (5, 'MUERTE', 3);

DELETE FROM Groups
WHERE Specialization_ID == 5;


---------------------------------------------------- №22

CREATE TRIGGER NO_DisciplineDel
BEFORE DELETE ON Disciplines
WHEN EXISTS (SELECT * FROM Subjects WHERE Discipline_ID = OLD.ID)
BEGIN
    SELECT RAISE(ABORT, 'Не удалять дисциплины с предметами');
END;

DELETE FROM Disciplines
WHERE Disciplines.ID == 2;


---------------------------------------------------- №23

CREATE TRIGGER NO_DupTeachers
BEFORE INSERT ON Subjects
WHEN EXISTS (
    SELECT *
    FROM Subjects
    WHERE NEW.Group_id = Group_id
    AND NEW.Year = Year
    AND NEW.Semester = Semester
    AND NEW.Discipline_id = Discipline_id
    AND NEW.Teacher_id != Teacher_id
)
BEGIN
    SELECT RAISE(ABORT, 'Не дублировать разных преподов на одну и ту же диспу');
END;

-- Группа id3 мкн генезис
-- Предмет id2 с диспой id2
-- ведет препод id6 сережа глущенко

-- попвтаюь поставить себя на эту же диспу

INSERT INTO Subjects (Group_ID, Discipline_ID, Year, Semester, GradeType, Teacher_ID)
VALUES (3, 2, 2024, 4, 'Exam', 3);


---------------------------------------------------- №24

CREATE TRIGGER NO_DupStudents
BEFORE INSERT ON Activity
WHEN EXISTS (
    SELECT *
    FROM Activity
    WHERE NEW.Student_ID = Student_ID
    AND NEW.timeofexpulsion IS NULL
    AND timeofexpulsion IS NULL
)
BEGIN
    SELECT RAISE(ABORT, 'Не дублировать студиков в разные группы');
END;

INSERT INTO Activity (Student_ID, Group_ID, TimeOfAdmission, TimeOfExpulsion, SemesterOfExpulsion)
VALUES (6, 2, '2024-02-24', null, null);


---------------------------------------------------- №25

CREATE TRIGGER AutoExpulsion
BEFORE INSERT ON Activity
BEGIN
    UPDATE Activity
    SET TimeOfExpulsion = DATETIME('now')
    WHERE Student_ID = NEW.Student_ID AND TimeOfExpulsion IS NULL AND ID != NEW.ID;
END;

INSERT INTO Activity (Student_ID, Group_ID, TimeOfAdmission, TimeOfExpulsion, SemesterOfExpulsion)
VALUES (6, 2, '2024-02-24', null, null);


---------------------------------------------------- №26

CREATE TRIGGER NO_AddGradeOhneGroup
BEFORE INSERT ON Grades
WHEN NOT EXISTS (
    SELECT *
    FROM Activity
    JOIN Subjects ON Activity.Group_ID = Subjects.Group_ID
    WHERE Activity.Student_ID = NEW.Student_ID
    AND Subjects.ID = NEW.Subject_ID
    AND Activity.TimeOfExpulsion IS NULL
)
BEGIN
    SELECT RAISE(ABORT, 'Не ставить оценку челу которого нет в конкретной группе');
END;

INSERT INTO Grades (Student_ID, Subject_ID, Grade, GradeTime)
VALUES (1, 1, 5, '2023-08-01');


---------------------------------------------------- №27

CREATE TRIGGER DelPrevGrades
AFTER INSERT ON Grades
BEGIN
    DELETE FROM Grades
    WHERE Student_ID = NEW.Student_ID
    AND Subject_ID = NEW.Subject_ID
    AND (ROWID != NEW.ROWID OR ROWID IS NULL);
END;

INSERT INTO Grades (Student_ID, Subject_ID, Grade, GradeTime)
VALUES (1, 2, 5, '2023-08-01');


---------------------------------------------------- №28

CREATE TRIGGER NO_GradeFromPast
BEFORE INSERT ON Grades
BEGIN SELECT
    CASE
        WHEN NEW.GradeTime > DATETIME('now') THEN
            RAISE (ABORT, 'Чел, тебе не дано управлять временем')
    END;
END;

INSERT INTO Grades (Student_ID, Subject_ID, Grade, GradeTime)
VALUES (1, 5, 5, '2077-08-01');
