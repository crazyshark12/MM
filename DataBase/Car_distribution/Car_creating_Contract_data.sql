insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values(1,1,3,4,'2022-02-01',1)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),3,5,5,'2022-03-04',1)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),1,3,6,'2020-03-04',1)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),1,3,10,'2020-12-11',1)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),3,3,11,'2020-12-11',1)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),2,4,13,'2021-07-11',0)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),2,4,13,'2022-06-12',1)

insert into Contract(Contract_ID, Employee_ID,Customer_ID, Car_ID, Contract_date, Is_done)
values((Select max(Contract_ID)+1 from Contract),4,2,14,'2021-06-12',0)
