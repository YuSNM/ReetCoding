# Write your MySQL query statement below

select ps.firstName, ps.lastName, adr.city, adr.state
from Person ps 
left join Address adr using (personId) #on ps.PersonId = adr.PersonId