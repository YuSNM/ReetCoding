# Write your MySQL query statement below
select name as Employee
from Employee e1
where salary > (
    select salary
    from Employee e2
    where e2.id = e1.managerId
)

#select e1.name as Employee
#from Employee e1 join Employee e2
#where e1.id = e2.managerId and e1.salary > e2.salary
