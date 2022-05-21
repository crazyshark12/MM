---------------------6 задание-----------------
--1. Ќапишите оператор, добавл€ющий в таблицу PERSON новое физическое лицо с сохранением
--последовательной нумерации записей (используйте вложенный select с Уmax(Е) + 1Ф).
--ƒобавьте одну новую запись (например, себ€ :)).

Insert into person Select max(Person_ID)+1 , 'Norkin','Mark', 88005553535, 'botanicheskaya' from Person

--2. Ќапишите оператор, добавл€ющий пометку У(s)Ф в начало комментари€ по каждому заказу, 
--исполнитель которого Ц студент. ¬ыполните этот оператор.

Update Order1 set Comments ='(s)' + Comments Where Employee_ID IN (Select Employee.Employee_ID from Employee where spec = 'student' )


--3. —оздайте в базе новую таблицу дл€ хранени€ данных о документах физ.лиц (вид и номер документа). 
--ѕри создании св€зи от нее к таблице PERSON укажите свойство каскадности удалени€. 

CREATE TABLE Documents(
Documents_ID integer NOT NULL,
Person_ID integer NOT NULL,
document_type VARCHAR(50),
code integer NOT NULL,
CONSTRAINT Documents_PK PRIMARY KEY (Documents_ID)
);
ALTER TABLE Documents ADD FOREIGN KEY (Person_ID) 
REFERENCES Person(Person_ID) ON DELETE CASCADE;

Insert into Documents(Documents_ID, Person_ID, document_type, code) VALUES(2, 11,'passport', 1111); 

delete from Person
where person_ID = 11