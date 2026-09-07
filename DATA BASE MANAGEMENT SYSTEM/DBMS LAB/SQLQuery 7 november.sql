CREATE TABLE Course (
Cid INT PRIMARY KEY,
Cname VARCHAR(60) NOT NULL,
Crhr INT
);

EXEC sp_rename 'Course.Crhr','CreditHours','column';

ALTER TABLE Course
ADD Prereq VARCHAR(50);

ALTER Table Course
ALTER Column Prereq VARCHAR(70);

ALTER TABLE Course
Drop column Prereq;

Insert INTO Course(Cid,Cname,CreditHours)
Values(123,'DB',4),
      (124,'DSA',4),
      (125,'SE',3),
      (126,'PP',2),
      (127,'TOA',2);
    
update Course
SET Cname='Numerical' where Cid=127;

Delete from Course where cid=127;

