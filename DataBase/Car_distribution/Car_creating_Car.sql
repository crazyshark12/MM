Insert Into Passport (Passport_ID)
Values (1);

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values (2, 'Kia', 'Rio','2019', 20000 , 1);
update Car_Features 
Set Engine_volume = 3,
	Transmission = 1,
	Color = 'white'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Opel', 'Astra','2011', 10000 , 0);
update Car_Features 
Set Engine_volume = 3,
	Transmission = 1,
	Mileage = 10000,
	Color = 'pink',
	Ñabin_condition = 9,
	engine_condition = 9,
	Transmission_condition = 6
where ID = (Select max(Car_ID) from Car)


Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Reno', 'Logan','2020', 35000 , 1);
update Car_Features 
Set Engine_volume = 5,
	Transmission = 0,
	Color = 'white'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Reno', 'Logan','2012', 8000 , 0);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 0,
	Mileage = 2500,
	Color = 'black',
	Ñabin_condition = 6,
	engine_condition = 7,
	Transmission_condition = 4
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Reno', 'Duster','2022', 25000 , 1);
update Car_Features 
Set Engine_volume = 3,
	Transmission = 1,
	Color = 'yellow'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Mercedes', 'Benz','2021', 50000 , 1);
update Car_Features 
Set Engine_volume = 3,
	Transmission = 1,
	Color = 'red'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Mercedes', 'Benz','2009', 12000 , 0);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 0,
	Mileage = 300000,
	Color = 'black',
	Ñabin_condition = 3,
	engine_condition = 2,
	Transmission_condition = 3
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Cadilac', 'Escalate','2017', 100000 , 1);
update Car_Features 
Set Engine_volume = 5,
	Transmission = 1,
	Color = 'black'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Hyndai', 'Solaris','2014', 7000 , 0);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 1,
	Mileage = 103000,
	Color = 'white',
	Ñabin_condition = 5,
	engine_condition = 5,
	Transmission_condition = 2
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Lada', 'Jiguly','1990', 200 , 0);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 0,
	Mileage = 400000,
	Color = 'black',
	Ñabin_condition = 1,
	engine_condition = 1,
	Transmission_condition = 1
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Lada', 'Jiguly','2020', 4000 , 1);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 0,
	Color = 'white'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Lada', 'Jiguly','2019', 4000 , 1);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 0,
	Color = 'black'
where ID = (Select max(Car_ID) from Car)

Insert Into Car (Car_ID, Brand, Model, Production_date, Price, Is_new)
Values ((Select max(Car_ID)+1 from Car), 'Lada', 'Jiguly','2018', 4000 , 1);
update Car_Features 
Set Engine_volume = 2,
	Transmission = 0,
	Color = 'black'
where ID = (Select max(Car_ID) from Car)
