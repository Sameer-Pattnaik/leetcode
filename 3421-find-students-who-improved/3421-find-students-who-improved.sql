# Write your MySQL query statement below
select distinct student_id,subject,first_score,latest_score from(
    select*,
    first_value(score) over w as first_score,
    last_value(score) over w as latest_score
    from Scores
    WINDOW w as(partition by student_id,subject order by exam_date rows between unbounded preceding and unbounded following)
    )T
    where first_score<latest_score order by student_id,subject;