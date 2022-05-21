insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values(1,'Alexei','Vosstaniya,72', 78944556321,'individual')

insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values((Select max(Customer_ID)+1 from Customer),'Disney','Brodway,1',78900006321,'entity')

insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values((Select max(Customer_ID)+1 from Customer),'H&M','Petergof,30',72644619396,'entity')

insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values((Select max(Customer_ID)+1 from Customer),'Mark','Okolnaya,17',78945556300,'individual')

insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values((Select max(Customer_ID)+1 from Customer),'Denis','Leninskiy prospect, 25',78945598730,'individual')

insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values((Select max(Customer_ID)+1 from Customer),'SPbSU','Universitetskiy prospect,30',79466887936,'entity')

insert into Customer (Customer_ID, Name, Address, Phone,Customer_type)
values((Select max(Customer_ID)+1 from Customer),'Ros Turizm','Vasiyeostovskaya,131',79466887744,'entity')