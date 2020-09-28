DROP DATABASE coffee_store;
CREATE DATABASE coffee_store;
USE coffee_store;

CREATE TABLE products
(
	productID INT AUTO_INCREMENT,
	Name VARCHAR(30),
	Price FLOAT CHECK (Price <= 9.99),
	CoffeeOrigin VARCHAR(30),
	PRIMARY KEY (productID)
);

CREATE TABLE customers
(
	customerID INT AUTO_INCREMENT,
	First_Name VARCHAR(30),
	Last_Name VARCHAR(30),
	Gender ENUM('M','F'),
	phone_number INT(11),	/*Here the name is changed FROM CustomerNumber to phone_number only beacause attached source files (sepcifically Customers.sql here) have used that name AND we preferred NOT to change data files*/
	PRIMARY KEY (customerID)
);

CREATE TABLE orders
(
	orderID INT AUTO_INCREMENT,
	product_id INT,			/*Here the name is changed FROM productID to product_id only beacause attached source files (sepcifically Orders.sql here) have used that name AND we preferred NOT to change data files*/
	customer_id INT,		/*Here the name is changed FROM customerID to customer_id only beacause attached source files (sepcifically Orders.sql here) have used that name AND we preferred NOT to change data files*/
	order_time DATETIME,	/*Here the name is changed FROM Date-Time to order_time only beacause attached source files (sepcifically Orders.sql here) have used that name AND we preferred NOT to change data files*/
	PRIMARY KEY (orderID),
	CONSTRAINT OP FOREIGN KEY (product_id) REFERENCES products(productID),
	CONSTRAINT OC FOREIGN KEY (customer_id) REFERENCES customers(customerID)
);

/*ASsignment 4 Data Fillups*/
/*Query 1*/
INSERT INTO products VALUES
(1, 'Espresso', 2.50, 'Brazil'),
(2, 'Macchiato', 3.00, 'Brazil'),
(3, 'CappuccINo', 3.50, 'Costa Rica'),
(4, 'Latte', 3.50, 'INdonesia'),
(5, 'Americano', 3.00, 'Brazil'),
(6, 'Flat White', 3.50, 'INdonesia'),
(7, 'Filter', 3.00, 'INdia');

/*Query 2*/
UPDATE products SET CoffeeOrigin='Sri Lanka' WHERE productID=7;
UPDATE products SET Price=3.25, CoffeeOrigin='Ethiopia' WHERE Name='Americano';
UPDATE products SET CoffeeOrigin='Colombia' WHERE CoffeeOrigin='Brazil';

/*Query 3*/
DELETE FROM products WHERE Name='Flat White';
INSERT INTO products VALUES (6, 'Flat White', 3.50, 'INdonesia');
DELETE FROM products WHERE Price=3.50;
INSERT INTO products VALUES
(3, 'CappuccINo', 3.50, 'Costa Rica'),
(4, 'Latte', 3.50, 'INdonesia'),
(6, 'Flat White', 3.50, 'INdonesia');

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

/*END of ASsignment 4*/
/*Start of ASsignment 5*/
/*Query 1*/
SELECT First_Name, Last_Name FROM customers WHERE Last_Name IN('Taylor','Bluth','Armstrong');

/*Query 2*/
SELECT First_Name, Last_Name FROM customers WHERE Last_Name NOT IN('Katie','George','John');

/*Query 3*/
SELECT product_id, customer_id, order_time FROM orders WHERE order_time BETWEEN '2017-01-01' AND '2017-01-07';

/*Query 4*/
SELECT product_id, customer_id, order_time FROM orders WHERE customer_id BETWEEN 5 AND 10;

/*Query 5*/
SELECT First_Name FROM customers WHERE Last_Name REGEXP '^[A-L]';

/*Query 6*/
SELECT First_Name, Last_Name FROM customers WHERE Last_Name LIKE 'W%';

/*Query 7*/
SELECT First_Name, Last_Name FROM customers WHERE Last_Name LIKE '%o';

/*Query 8*/
SELECT First_Name, Last_Name FROM customers WHERE First_Name LIKE '%o%';

/*Query 9*/
SELECT Name FROM products WHERE Price LIKE '3%';

/*Query 10*/
SELECT Name FROM products ORDER BY Price;

/*Query 11*/
SELECT First_Name, Last_Name FROM customers ORDER BY First_Name ASC;

/*Query 12*/
SELECT orderID FROM orders WHERE customer_id=1 ORDER BY order_time DESC;

/*Query 13*/
SELECT DISTINCT CoffeeOrigin FROM products;

/*Query 14*/
SELECT DISTINCT customer_id FROM orders WHERE order_time BETWEEN '2017-02-01' AND '2017-02-28';

/*Query 15*/
SELECT First_Name, Last_Name FROM customers WHERE customerID LIKE '6%' LIMIT 5;

/*Querty 16*/
SELECT First_Name, Last_Name FROM customers ORDER BY Last_Name LIMIT 10;

/*Query 17*/
SELECT Name AS 'Product Name', Price, CoffeeOrigin AS Country FROM products;

/*Query 18*/
SELECT products.Name, orders.order_time FROM orders RIGHT JOIN products on orders.product_id=products.productID;


/*Query 19*/
SELECT products.Name, products.price, orders.order_time FROM products RIGHT JOIN orders on products.Name='Americano' ORDER BY order_time DESC;

/*Query 20*/
SELECT customers.First_Name, customers.phone_number FROM orders RIGHT JOIN customers ON orders.customer_id=customers.customerID RIGHT JOIN products ON orders.product_id=products.productID WHERE products.Name='Espresso';

/*Query 21*/
SELECT orders.orderID, customers.First_Name, customers.Last_Name, customers.phone_number, orders.order_time FROM orders RIGHT JOIN customers on orders.customer_id=customers.customerID ORDER BY orders.order_time DESC LIMIT 10;

/*Query 22*/
UPDATE orders set customer_id=null WHERE orderID=1;

SELECT orders.orderID, customers.First_Name, customers.Last_Name, customers.phone_number, orders.order_time FROM orders LEFT JOIN customers on orders.customer_id=customers.customerID ORDER BY orders.order_time ASC LIMIT 10;

/*Query 23*/
SELECT orders.orderID, customers.First_Name, customers.Last_Name, customers.phone_number, orders.order_time FROM customers LEFT JOIN orders on customers.customerID=orders.customer_id ORDER BY orders.order_time LIMIT 10;

/*Query 24*/
SELECT orders.orderID, customers.First_Name, customers.Last_Name, customers.phone_number, orders.order_time FROM orders RIGHT JOIN customers on customers.customerID=orders.customer_id ORDER BY orders.order_time LIMIT 10;

/*Query 25*/
SELECT orders.orderID, customers.First_Name, customers.Last_Name, customers.phone_number, orders.order_time FROM customers RIGHT JOIN orders on orders.customer_id=customers.customerID ORDER BY orders.order_time LIMIT 10;

/*Query 26*/
UPDATE orders set customer_id=1 WHERE orderID=1;

SELECT products.Name, products.Price, customers.First_Name, customers.Last_Name, orders.order_time FROM orders LEFT JOIN products on orders.product_id=products.productID LEFT JOIN customers on orders.customer_id=customers.customerID;

/*Query 27*/
SELECT products.Name, products.Price, customers.First_Name, customers.Last_Name, orders.order_time FROM orders LEFT JOIN products on orders.product_id=products.productID LEFT JOIN customers on orders.customer_id=customers.customerID WHERE customers.Last_Name='Martin' ORDER BY orders.order_time desc;

DROP DATABASE coffee_store;
/*End of Assignment 5*/
