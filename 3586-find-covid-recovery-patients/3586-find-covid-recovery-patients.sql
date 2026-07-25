# Write your MySQL query statement below
select patients.patient_id,patients.patient_name,patients.age,datediff(min(c2.test_date),min(c1.test_date)) as recovery_time 
from covid_tests c1 
join covid_tests c2 
on c1.patient_id=c2.patient_id 
and c1.test_date<c2.test_date 
and c1.result="Positive" 
and c2.result="Negative" 
join patients 
on patients.patient_id=c1.patient_id 
group by patients.patient_id
order by recovery_time asc, patients.patient_name asc;