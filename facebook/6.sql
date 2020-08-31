select bc.buyer_id, bp.TOTAL_WORTH from
    (select a.buyer_id, count(a.price) as house_qty from (
        select house.buyer_id, price.price from house
        join price on house.house_id = price.house_id
    ) as a group by a.buyer_id) as bc
    inner join 
    (select b.buyer_id, sum(b.price) as TOTAL_WORTH from (
    select house.buyer_id, price.price from house
    join price on house.house_id = price.house_id
    ) as b group by b.buyer_id) as bp
    on bc.buyer_id = bp.buyer_id where bc.house_qty > 1 and bp.TOTAL_WORTH > 100;