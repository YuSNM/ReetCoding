# Write your MySQL query statement below


SELECT Email
from Person
group by Email
having count(*) > 1

/*
 #SELECT distinct a.Email
 FROM Person a 
 JOIN Person b on a.email = b.email
 WHERE a.id != b.id;
*/