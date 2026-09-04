select distinct product_id,
coalesce((select new_price from 
(select * from products p3 where change_date <= '2019-08-16' and p3.product_id = p2.product_id) p1
order by change_date DESC limit 1),10) as price
from products p2;