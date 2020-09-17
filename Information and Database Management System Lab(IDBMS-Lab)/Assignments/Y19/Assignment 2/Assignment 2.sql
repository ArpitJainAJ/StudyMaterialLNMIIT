CREATE DATABASE coffee_store;
USE coffee_store;
CREATE TABLE Products
(
    productID int,
    productName VARCHAR(50),
    productPrice int NOT NULL,
    PRIMARY KEY (productID)
);
show tables;
CREATE TABLE Customers
(
    customerID int,
    First_name VARCHAR(25),
    Last_name VARCHAR(25),
    Gender ENUM('M','F'),
    Contact_Number int(10),
    PRIMARY KEY (customerID)
);
show tables;
CREATE TABLE Orders
(
    orderID int,
    productID int,
    customerID int,
    Date_Time DATETIME,
    PRIMARY KEY (orderID),
    CONSTRAINT OP FOREIGN KEY (productID) REFERENCES Products(productID), 
    CONSTRAINT OC FOREIGN KEY (customerID) REFERENCES Customers(customerID) 
);
show tables;
DESCRIBE Products;
ALTER TABLE Products ADD CoffeeOrigin VARCHAR(25);
DESCRIBE Products;
ALTER TABLE Products DROP CoffeeOrigin;
DESCRIBE Products;
ALTER TABLE Products ADD CoffeeOrigin VARCHAR(25);
ALTER TABLE Orders DROP FOREIGN KEY OP ; 
DROP TABLE Products;
show tables;
CREATE TABLE Products
(
    productID int,
    productName VARCHAR(50),
    productPrice int NOT NULL,
    CoffeeOrigin VARCHAR(25),
    PRIMARY KEY (productID)
);
ALTER TABLE Orders ADD CONSTRAINT OP FOREIGN KEY (productID) REFERENCES Products(productID);
show tables;
INSERT INTO Products (productID, productName, productPrice, CoffeeOrigin) VALUES (1, 'Espresso', 2.50, 'Brazil');
INSERT INTO Products (productID, productName, productPrice, CoffeeOrigin) VALUES (2, 'Cappuccino', 3.50, 'CostaRica');
SELECT * FROM Products ;
DELETE FROM Products ;
DROP DATABASE coffee_store;

