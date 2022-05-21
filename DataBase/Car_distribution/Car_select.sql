--1. ��� ���������� � ���������� ��������� �� �������
Select Employee.Name , count(*) as success_Contracts From Employee
Join Contract on Contract.Employee_ID = Employee.Employee_ID
Where Is_done = 1
group by Employee.Employee_ID, Employee.Name

--2. ��� ���������� � ������� �� ��������� �� �������
Select Employee.Name, sum(Car.Price) as profit From Employee
Join Contract on Contract.Employee_ID = Employee.Employee_ID
Join Car on Contract.Car_ID = Car.Car_ID
Where Is_done = 1
group by Employee.Employee_ID, Employee.Name
Order by profit Desc

--3.������ ������� ���, ������� ������ ���� �� ���� ����������
Select * from Customer
where Customer_ID IN (Select distinct Contract.Customer_ID From Contract 
					  where is_Done = 1)

--4.������� ������ � ��������� �/� �����
Select avg(convert(decimal,Mileage)) from Passport
Join Car on Car.Car_ID = Passport.Car_ID
Join Contract on Car.Car_ID = Contract.Car_ID
where Is_done = 1 and Is_new = 0

--5.������� ����������� ���� ������� ���������, ������� ����� ��� �� ��� ��������� � ���� �� ����� ��������� �/� ������
Select Customer.Name , count(*) as number_of_cars ,sum(Car.Price) as total_profit, min(convert(integer,Car.Is_new)) as any_old_car  From Customer
Join Contract on Customer.Customer_ID = Contract.Customer_ID
join Car on Car.Car_ID = Contract.Car_ID
where is_done = 1 
group by Customer.Customer_Id, Customer.Name 

--6.������� � ������� ����� ���������� ������� ����� �� �������� � �� ��������
Select avg(convert(decimal, Car.Price )) from Car
Join Passport on Car.Car_ID = Passport.Car_ID
where Passport.color = 'black' and Passport.Transmission = 1
UNION
Select avg(convert(decimal, Car.Price )) from Car
Join Passport on Car.Car_ID = Passport.Car_ID
where Passport.color = 'black' and Passport.Transmission = 0

--7. ����������� �������������� ���� ����� ������������ Lada 
Select * from Car
Join Passport on Car.Car_ID = Passport.Car_ID
where Car.Brand = 'Lada'

--8. ����������� �/� ������ � ������� ������ ���������� ��������� ��������� �� ������ 5 
--	 � �������� ������� �� ���� �����������
Select Car.Car_ID ,model,avg(convert(decimal,(Engine_condition + Transmission_condition)))/2 from Car
Join Passport on Car.Car_ID = Passport.Car_ID
where Engine_condition >= 5 and Is_new = 0
group by  Car.Car_ID , model

--9. ���������� � ��������� ����� ������� ����� 1000 �������� ��������� ��� �� 2020 ���
Select Employee.Name , count(*) from Employee
Join Contract on Contract.Employee_ID = Employee.Employee_ID
Join Car on Contract.Car_ID = Car.Car_ID
where Car.Price > 100 and Year(Contract.Contract_date) = 2020 and Contract.Is_done = 1
Group by Employee.Employee_ID ,Employee.Name

--10. ����� ���� ��������� �������
Select distinct Color From Passport
Join Car on Car.Car_ID = Passport.Car_ID
Where model = 'jiguly'

