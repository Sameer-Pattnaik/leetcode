# Write your MySQL query statement below
select employee_id,case when employee_id%2=0 OR name Like "M%" then 0 else salary end as bonus from Employees order by employee_id asc;