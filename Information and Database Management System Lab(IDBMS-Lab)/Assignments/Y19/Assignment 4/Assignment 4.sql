DROP DATABASE coffee_store;
CREATE DATABASE coffee_store;
USE coffee_store;

CREATE TABLE products
(
	productID int AUTO_INCREMENT,
	Name VARCHAR(30),
	Price FLOAT CHECK (Price <= 9.99),
	CoffeeOrigin VARCHAR(30),
	PRIMARY KEY (productID)
);

CREATE TABLE customers
(
	customerID int AUTO_INCREMENT,
	First_Name VARCHAR(30),
	Last_Name VARCHAR(30),
	Gender ENUM('M','F'),
	phone_number int(11),	/*Here the name is changed from CustomerNumber to phone_number only beacause attached source files (sepcifically Customers.sql here) have used that name and we preferred not to change data files*/
	PRIMARY KEY (customerID)
);

CREATE TABLE orders
(
	orderID int AUTO_INCREMENT,
	product_id int,			/*Here the name is changed from productID to product_id only beacause attached source files (sepcifically Orders.sql here) have used that name and we preferred not to change data files*/
	customer_id int,		/*Here the name is changed from customerID to customer_id only beacause attached source files (sepcifically Orders.sql here) have used that name and we preferred not to change data files*/
	order_time DATETIME,	/*Here the name is changed from Date-Time to order_time only beacause attached source files (sepcifically Orders.sql here) have used that name and we preferred not to change data files*/
	PRIMARY KEY (orderID),
	CONSTRAINT OP FOREIGN KEY (product_id) REFERENCES products(productID),
	CONSTRAINT OC FOREIGN KEY (customer_id) REFERENCES customers(customerID)
);

/*Query 1*/
INSERT INTO products VALUES
(1, 'Espresso', 2.50, 'Brazil'),
(2, 'Macchiato', 3.00, 'Brazil'),
(3, 'Cappuccino', 3.50, 'Costa Rica'),
(4, 'Latte', 3.50, 'Indonesia'),
(5, 'Americano', 3.00, 'Brazil'),
(6, 'Flat White', 3.50, 'Indonesia'),
(7, 'Filter', 3.00, 'India');

/*Query 2*/
UPDATE products SET CoffeeOrigin='Sri Lanka' WHERE productID=7;
UPDATE products SET Price=3.25, CoffeeOrigin='Ethiopia' WHERE Name='Americano';
UPDATE products SET CoffeeOrigin='Colombia' WHERE CoffeeOrigin='Brazil';

/*Query 3*/
DELETE FROM products WHERE Name='Flat White';
INSERT INTO products VALUES (6, 'Flat White', 3.50, 'Indonesia');
DELETE FROM products WHERE Price=3.50;
INSERT INTO products VALUES
(3, 'Cappuccino', 3.50, 'Costa Rica'),
(4, 'Latte', 3.50, 'Indonesia'),
(6, 'Flat White', 3.50, 'Indonesia');

/*Query 4*/
source Customers.sql;
source Orders.sql;

/*Query 5*/
SELECT Last_Name FROM customers;

/*Query 6*/
SELECT Last_Name, phone_number FROM customers;

/*Query 7*/
SELECT * FROM products WHERE CoffeeOrigin='Colombia';

/*Query 8*/
SELECT * FROM products WHERE Price=3.00;

/*Query 9*/
SELECT * FROM products WHERE Price=3.00 AND CoffeeOrigin='Colombia';

/*Query 10*/
SELECT * FROM products WHERE Price=3.00 OR CoffeeOrigin='Colombia';

/*Query 11*/
SELECT * FROM products WHERE Price>=3.00;

/*Query 12*/
SELECT * FROM customers WHERE phone_number IS NULL;

DROP DATABASE coffee_store;
/*END of Assignment 4*/