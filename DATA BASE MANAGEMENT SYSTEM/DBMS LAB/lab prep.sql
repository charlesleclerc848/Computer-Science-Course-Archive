-----------------------------------------
-- 1. CREATE DATABASE
-----------------------------------------
CREATE DATABASE TestDB;
GO

-----------------------------------------
-- 2. SELECT DATABASE
-----------------------------------------
USE TestDB;
GO

-----------------------------------------
-- 3. CREATE TABLE with constraints
-----------------------------------------
CREATE TABLE Customer (
    Cid INT PRIMARY KEY,         -- Primary Key
    Name VARCHAR(50) NOT NULL,   -- Not Null
    City VARCHAR(50),
    Age INT
);

-----------------------------------------
-- 4. INSERT sample data (10 entries)
-----------------------------------------
INSERT INTO Customer (Cid, Name, City, Age) VALUES
(1, 'Ali', 'Lahore', 22),
(2, 'Sara', 'Karachi', 25),
(3, 'Ahmed', 'Islamabad', 30),
(4, 'Hina', 'Lahore', 28),
(5, 'Bilal', 'Multan', 19),
(6, 'Usman', 'Karachi', 35),
(7, 'Fatima', 'Islamabad', 27),
(8, 'Daniyal', 'Lahore', 24),
(9, 'Hassan', 'Multan', 31),
(10, 'Ayesha', 'Karachi', 29);

-----------------------------------------
-- 5. SELECT all records
-----------------------------------------
SELECT * FROM Customer;

-----------------------------------------
-- 6. DISTINCT example (unique cities)
-----------------------------------------
SELECT DISTINCT City FROM Customer;

-----------------------------------------
-- 7. WHERE + AND + OR examples
-----------------------------------------
SELECT * FROM Customer
WHERE City = 'Lahore' AND Age > 20;

SELECT * FROM Customer
WHERE City = 'Karachi' OR Age < 25;

-----------------------------------------
-- 8. ORDER BY (ASC/DESC)
-----------------------------------------
SELECT * FROM Customer ORDER BY Age ASC;
SELECT * FROM Customer ORDER BY Name DESC;

-----------------------------------------
-- 9. UPDATE + SET
-----------------------------------------
UPDATE Customer
SET City = 'Rawalpindi'
WHERE Cid = 5;

-----------------------------------------
-- 10. DELETE
-----------------------------------------
DELETE FROM Customer
WHERE Cid = 10;

-----------------------------------------
-- 11. ALTER TABLE: ADD column
-----------------------------------------
ALTER TABLE Customer
ADD Email VARCHAR(100);

-----------------------------------------
-- 12. ALTER TABLE: ALTER COLUMN datatype
-----------------------------------------
ALTER TABLE Customer
ALTER COLUMN Name VARCHAR(100);

-----------------------------------------
-- 13. ALTER TABLE: DROP COLUMN
-----------------------------------------
ALTER TABLE Customer
DROP COLUMN Email;

-----------------------------------------
-- 14. sp_rename (rename column)
-----------------------------------------
EXEC sp_rename 'Customer.City', 'CustomerCity';

-----------------------------------------
-- 15. Create a Stored Procedure
-----------------------------------------
/*
CREATE PROCEDURE ShowAdults
AS
BEGIN
    SELECT * FROM Customer
    WHERE Age >= 20;
END;
GO
*/
-----------------------------------------
-- 16. Execute Stored Procedure (EXEC)
-----------------------------------------
EXEC ShowAdults;
