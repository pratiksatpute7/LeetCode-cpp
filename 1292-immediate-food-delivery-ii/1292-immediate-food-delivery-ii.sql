-- # Write your MySQL query statement below

select
    Round(sum(
        case when order_date = customer_pref_delivery_date then 1 else 0 end
    )/ count(delivery_id) * 100, 2) as immediate_percentage
from Delivery D
inner join
(select customer_id , min(order_date) as orderdate
    from Delivery 
    group by customer_id
) as A
on A.customer_id = D.customer_id
and D.order_date = A.orderdate;

