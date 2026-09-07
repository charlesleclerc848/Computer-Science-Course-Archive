create table profile_info(
ID int primary key,
FirstName varchar(100),
LastName varchar(100),
AddressLine1 varchar(100),
City varchar(100),
StateProvinceCode varchar(100),
PostalCode varchar(100)
);

INSERT INTO profile_info (ID,FirstName, LastName, AddressLine1, City, StateProvinceCode, PostalCode)
VALUES
(1, 'Ben', 'Miller', '101 Candy Rd.', 'Redmond', 'WA', 98052),
(2, 'Garrett', 'Vargas', '10203 Acorn Avenue', 'Calgary', 'WA', 228),
(3, 'Gabe', 'Mares', '1061 Bushrik Avenue', 'Edmonds', 'WA', 98020),
(4, 'Reuben', 'D.sa', '1064 Slow Creek Rd.', 'Seattle', 'WA', 98104),
(5, 'Gordon', 'Hee', '108 Lakeside Court', 'Bellevue', 'WA', '98004'),
(6, 'Karan', 'Khanna', '1102 Ravenwood', 'Seattle', 'WA', '98104'),
(7, 'François', 'Ajenstat', '1144 Paradise Ct.', 'Issaquah', 'WA', '98027'),
(8, 'Sariya', 'Harnpadoungsataya', '1185 Dallas Drive', 'Everett', 'WA', '98201'),
(9, 'Kirk', 'Koenigsbauer', '1220 Bradford Way', 'Seattle', 'WA', '98104'),
(10, 'Kim', 'Ralls', '1226 Shoe St.', 'Bothell', 'WA', '98011'),
(11, 'Michael', 'Raheem', '1234 Seaside Way', 'San Francisco', 'CA', '94111'),
(12, 'Mike', 'Seamans', '1245 Clay Road', 'Index', 'WA', '98256'),
(13, 'Reed', 'Koch', '1275 West Street', 'Redmond', 'WA', '98052'),
(14, 'Fadi', 'Fakhouri', '1285 Greenbrier Street', 'Snohomish', 'WA', '98296'),
(15, 'Paul', 'Singh', '1343 Prospect St', 'Bellevue', 'WA', '98004'),
(16, 'Brenda', 'Diaz', '1349 Steven Way', 'Seattle', 'WA', '98104'),
(17, 'Jack', 'Richins', '1356 Grove Way', 'Monroe', 'WA', '98272'),
(18, 'John', 'Evans', '136 Balboa Court', 'Seattle', 'WA', '98104'),
(19, 'Ken', 'Myer', '1362 Somerset Place', 'Everett', 'WA', '98201'),
(20, 'Barbara', 'Moreland', '137 Mazatlan', 'Seattle', 'WA', '98104');

update profile_info
SET City='Lahore',StateProvinceCode='WAA',PostalCode='60700' where FirstName='Kim'and LastName='Ralls';
Delete from profile_info where city='Redmond';
