# Write your MySQL query statement below


SELECT name AS Customers 
FROM customers C
WHERE C.id NOT IN (
    SELECT customerId
    FROM orders
);