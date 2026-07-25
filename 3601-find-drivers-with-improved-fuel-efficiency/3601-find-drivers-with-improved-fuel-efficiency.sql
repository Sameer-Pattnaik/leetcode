# Write your MySQL query statement below
with cte as(
    select drivers.driver_name,trips.driver_id,
    avg(case when month(trips.trip_date)<=6 then trips.distance_km/trips.fuel_consumed end)as first,
    avg(case when month(trips.trip_date)>6 then trips.distance_km/trips.fuel_consumed end)as second
    from drivers 
    join trips 
    on drivers.driver_id=trips.driver_id
    group by drivers.driver_id

)
select driver_id,driver_name,round(first,2)as first_half_avg,round(second,2)as second_half_avg,round(second-first,2)as efficiency_improvement 
from cte
where first is not NULL and second is not NULL and second>first
order by efficiency_improvement desc,driver_name asc;
