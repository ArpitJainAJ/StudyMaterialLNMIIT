/*Creating Database*/
CREATE DATABASE test;
USE test;

/*Creating Tables*/
CREATE TABLE addresses
(
	addressID VARCHAR(10),
	HouseNumber int,
	City VARCHAR(15),
	PostCode int(6)
);
DESCRIBE addresses;

CREATE TABLE people
(
	peopleID VARCHAR(10),
	FirstName VARCHAR(25),
	LastName VARCHAR(25),
	addressID VARCHAR(10)
);
DESCRIBE people;

CREATE TABLE pets
(
	petID VARCHAR(10),
	Name VARCHAR(25),
	Species VARCHAR(25),
	ownerId VARCHAR(10)
);
DESCRIBE pets;

/*Query 18*/
DESCRIBE addresses;
ALTER TABLE addresses ADD PRIMARY KEY (addressID);
DESCRIBE addresses;

/*Query 2*/
ALTER TABLE addresses DROP PRIMARY KEY;
DESCRIBE addresses;

ALTER TABLE addresses Add PRIMARY KEy(addressID);
DESCRIBE addresses;

/*Query 3*/
ALTER TABLE people ADD PRIMARY KEY (peopleID, FirstName);
DESCRIBE people;

/*Query 4*/
ALTER TABLE people ADD CONSTRAINT AddID FOREIGN KEY (addressId) REFERENCES addresses(addressID);
DESCRIBE people;

/*Query 5*/
ALTER TABLE people DROP FOREIGN KEY AddID;
ALTER TABLE people DROP KEY AddID;
DESCRIBE people;

/*Query 6*/
ALTER TABLE pets ADD CONSTRAINT PetSpecie UNIQUE (Species); 
DESCRIBE pets;

/*Query 7*/
ALTER TABLE pets DROP CONSTRAINT PetSpecie;
DESCRIBE pets;

/*Query 8*/
ALTER TABLE pets RENAME COLUMN Species TO AnimalType;
DESCRIBE pets;

/*Query 9*/
ALTER TABLE addresses MODIFY COLUMN City VARCHAR(50);
DESCRIBE addresses;

/*Query 10*/
ALTER TABLE pets ADD PRIMARY KEY (petId);
DESCRIBE pets;

/*Query 11*/
ALTER TABLE pets ADD CONSTRAINT PetOwner FOREIGN KEY (ownerId) REFERENCES people(peopleID);
DESCRIBE pets;

/*Query 12*/
ALTER TABLE people ADD COLUMN email VARCHAR(50);
DESCRIBE people;

/*Query 13*/
ALTER TABLE people ADD CONSTRAINT Uemail UNIQUE(email);
DESCRIBE people;

/*Query 14*/
ALTER TABLE pets RENAME COLUMN Name to FirstName;
DESCRIBE pets;

/*Query 15*/
ALTER TABLE addresses MODIFY COLUMN PostCode CHAR(7);
DESCRIBE addresses;

/*Removing Database*/
DROP DATABASE test ; 
/*END OF ASSIGNMENT-3*/
