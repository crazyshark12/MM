

Create table Car(
Car_ID INTEGER      NOT NULL,
Brand  VARCHAR(20)  NOT NULL,
Model  VARCHAR(20)  NOT NULL,
Production_date  DATETIME      DEFAULT GETDATE()    NOT NULL,
Price INTEGER      NOT NULL,
Is_new BIT,
CONSTRAINT Car_PK PRIMARY KEY (Car_ID)
);
Create table Contract(
Contract_ID INTEGER      NOT NULL,
Employee_ID INTEGER      NOT NULL,
Customer_ID INTEGER      NOT NULL,
Car_ID INTEGER      NOT NULL,
Contract_date DATETIME      DEFAULT GETDATE()    NOT NULL,
Is_done BIT,
CONSTRAINT Contract_PK PRIMARY KEY (Contract_ID)
);
Create table Customer(
Customer_ID INTEGER      NOT NULL,
Name VARCHAR(20)  NOT NULL,
Address VARCHAR(50)  NOT NULL,
Phone varchar(15)      NOT NULL,
Customer_type VARCHAR(20)  NOT NULL,
CONSTRAINT Customer_PK PRIMARY KEY (Customer_ID)
);
Create table Employee(
Employee_ID INTEGER  IDENTITY(1,1),
Name VARCHAR(20)  NOT NULL,
Surname VARCHAR(20) NULL,
Address VARCHAR(50)  NOT NULL,
Phone varchar(15)      NOT NULL,
Salary INTEGER      NOT NULL,
CONSTRAINT Employee_PK PRIMARY KEY (Employee_ID)
);

Create table Passport(
Passport_ID INTEGER      NOT NULL,
Car_ID INTEGER ,  
Engine_volume INTEGER,
Transmission BIT, --0 механика , 1 автомат
Mileage INTEGER,
Color VARCHAR (20),

Сabin_condition INTEGER ,
Engine_condition INTEGER ,
Transmission_condition INTEGER ,
Comment VARCHAR ,
CONSTRAINT Passport_PK PRIMARY KEY (Passport_ID)
);


ALTER TABLE Contract ADD CONSTRAINT FK_Contract_Customer 
    FOREIGN KEY (Customer_ID)
    REFERENCES Customer(Customer_ID)  On delete Cascade
;
ALTER TABLE Contract ADD CONSTRAINT FK_Contract_Car 
    FOREIGN KEY (Car_ID)
    REFERENCES Car(Car_ID)  On delete Cascade
;
ALTER TABLE Contract ADD CONSTRAINT FK_Contract_Employee 
    FOREIGN KEY (Employee_ID)
    REFERENCES Employee(Employee_ID)  On delete Cascade
;

ALTER TABLE Passport ADD CONSTRAINT FK_Passport_Car 
    FOREIGN KEY (Car_ID)
    REFERENCES Car(Car_ID) On delete Cascade
;

--добавляет машине, которая указана как новая, характеристику машины с завода(0 пробег, и наивысшие оценки состояния)
--a машине, которая указана как б/у, просто создаёт пустой паспорт
Use car_distribution
Go
CREATE TRIGGER new_Car_Passport ON Car AFTER INSERT
AS 
if  1 = (SELECT Is_new FROM inserted)
	Insert Into Passport (Passport_ID,Car_ID ,Mileage,Сabin_condition , engine_condition,Transmission_condition)
	Values ((Select max(Passport_ID)+1 from Passport),(Select Car_ID from inserted),0, 10 , 10 ,10)
else
	Insert Into Passport (Passport_ID,Car_ID)
	Values ((Select max(Passport_ID)+1 from Passport),(Select Car_ID from inserted))
Go
Create view Car_Features as
Select Car.Car_ID as ID, Engine_volume,Transmission,Mileage,Color,Сabin_condition , engine_condition,Transmission_condition From Car
Join Passport On passport.Car_ID = car.Car_ID

go
CREATE INDEX idx_Car_model_price ON Car(model,price);
CREATE Unique INDEX idx_Customer_Name ON Customer(Name);

go
CREATE PROCEDURE Statistic  ----3.Данные частных/юридических лиц, которые купили хотя бы один автомобиль
@var_face as char(10)
AS
BEGIN
	Select * from Customer
	where Customer_ID IN (Select distinct Contract.Customer_ID From Contract 
    where is_Done = 1) and Customer_type = @var_face
END
-- Вызов этой процедуры:     
EXEC Statistic @var_face='individual'

/*
drop Procedure Statistic
drop trigger new_Car_Passport;
drop view Car_Features;
drop table Passport;
drop table Contract;
drop table Car;
drop table Employee;
drop table Customer;

*/