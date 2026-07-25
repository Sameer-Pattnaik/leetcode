# Write your MySQL query statement below
select x,y,z,case when (x+y)>z AND (x+z)>y AND (y+z)>x then "Yes" else "No" end as triangle from Triangle;