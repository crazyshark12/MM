--1.—оздайте представление У—обакиФ со следующими атрибутами: кличка, порода, возраст,
--фамили€ и им€ хоз€ина. »спользу€ это представление, получите список пуделей: кличка, фамили€ хоз€ина.

Create View Dogs as
Select Nick,age, breed, First_Name, Last_Name
From Pet
Join Pet_Type on pet.pet_type_id = pet_type.pet_type_id
Join Owner on owner.Owner_ID = pet.Owner_ID
Join Person on person.Person_ID = owner.Person_ID
where pet_type.Name = ('DOG');

Select Nick, Last_Name from Dogs
Where breed = 'poodle'


--2.—оздайте представление У–ейтинг сотрудниковФ: фамили€, им€, количество выполненных
--заказов, средний балл (по оценке). »спользу€ это представление, выведите рейтинг с сортировкой по убыванию балла.

create View Employee_rating as
Select last_name,First_Name ,Count(*) as Done,AVG(convert(decimal,Mark)) as rating  From Person
Join Employee on employee.person_id = person.Person_id
Join Order1 on Employee.Employee_ID = order1.Employee_ID
where is_Done = 1
Group by Employee.Person_ID, first_name, last_name

Select last_name,First_Name ,Done, rating from Employee_rating
Order by rating DESC

--3.—оздайте представление У«аказчикиФ: фамили€, им€, телефон, адрес. 
--»спользу€ это представление, напишите оператор, после выполнени€ 
--которого у всех заказчиков без адреса в это поле добавитс€ вопросительный 
--знак (если вы работаете в —”Ѕƒ, где не редактируютс€ представлени€, 
--созданные на соединении таблиц,  вместо UPDATE напишите какой-нибудь SELECT). 

create View Customers as
Select Last_Name, First_Name, phone, address from Person
Join Owner on Owner.Person_ID = Person.Person_ID
--Group by Last_Name, First_Name, phone, address

UPDATE Customers 
SET address = '?'
Where address is NULL or address = ' ' 
