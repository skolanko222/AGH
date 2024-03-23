--zad1
USE AdventureWorks2019
GO
IF OBJECT_ID('dbo.zad1') IS NOT NULL
 DROP PROCEDURE dbo.zad1;
GO
CREATE PROCEDURE dbo.zad1
AS
BEGIN
	DECLARE @FirstName NVARCHAR(50)
	DECLARE @LastName NVARCHAR(50)
	DECLARE @Phone NVARCHAR(50)
	DECLARE @Email NVARCHAR(50)
	DECLARE @Cursor CURSOR
	DECLARE @i INT
	SET @Cursor = CURSOR FOR
		SELECT c.FirstName, c.LastName, p.PhoneNumber, e.EmailAddress
			FROM Person.Person AS c
			JOIN Person.PersonPhone AS p ON c.BusinessEntityID = p.BusinessEntityID
			JOIN Person.EmailAddress AS e ON c.BusinessEntityID = e.BusinessEntityID
	OPEN @Cursor
	SET @i = 0
	FETCH NEXT FROM @Cursor INTO @FirstName, @LastName, @Phone, @Email
		WHILE @@FETCH_STATUS = 0 AND @i < 30
		BEGIN
			PRINT 'Imie: ' + @FirstName + ', Nazwisko: ' + @LastName
			PRINT '- Telefon: ' + @Phone
			PRINT '- Email: ' + @Email
			SET @i = @i + 1
			FETCH NEXT FROM @Cursor INTO @FirstName, @LastName, @Phone, @Email
		END
	CLOSE @Cursor
	DEALLOCATE @Cursor
END

EXEC dbo.zad1

--zad2
USE AdventureWorks2019
GO
IF OBJECT_ID('dbo.zad2') IS NOT NULL
 DROP TRIGGER dbo.zad2;
GO

CREATE TRIGGER dbo.zad2
ON Person.Person
AFTER INSERT, DELETE, UPDATE
AS
BEGIN
	PRINT '[LOG]:' + CONVERT(NVARCHAR(50), GETDATE()) + ' - DML on Person.Person'
END

--zad3
USE AdventureWorks2019
GO
IF OBJECT_ID('dbo.zad3') IS NOT NULL
 DROP PROCEDURE dbo.zad3;
GO
CREATE PROCEDURE dbo.zad3
AS
BEGIN
	DECLARE @i INT
	SET @i = 0
	WHILE @i < 10
	BEGIN
		IF @i = 5
		BEGIN
			RAISERROR('Nie można wykonać operacji', 16, 1)
		END
		PRINT 'Iteracja: ' + CONVERT(NVARCHAR(50), @i)
		SET @i = @i + 1
	END
END