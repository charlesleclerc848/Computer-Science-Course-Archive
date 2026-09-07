CREATE TABLE Teachers(
SAPID INT Primary key,
FirstName Varchar(50) NOT NULL,
LastName Varchar(50) NOT NULL,
ContactNumber Int NOT NULL,
Semester Int
);

ALTER Table Teachers
ADD Email Varchar(50);

ALTER Table Teachers
ALTER Column Email int

Exec sp_rename 'Teachers.Email','TEmail','column';

Alter Table Teacher	
Drop Column TEmail;