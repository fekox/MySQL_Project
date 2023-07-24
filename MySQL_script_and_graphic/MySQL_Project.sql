CREATE DATABASE MySQL_Project; #Creo la base de datos.

USE MySQL_Project; #Le aviso al sistema que base de datos voy utilizar.

CREATE TABLE WORKTOOLS #Creo la tabla herramientas de trabajo.
(
	IdWorkTool INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    workToolName VARCHAR(40)
);

CREATE TABLE SECTORS #Creo la tabla Sectores.
(
	IdSector INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    sectorName VARCHAR(40)
);

CREATE TABLE JOBS #Creo la tabla trabajos.
(
	IdJob INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    jobName VARCHAR(40),
    descriptionJob VARCHAR(50),
    IdSector INTEGER,
    IdWorkTool INTEGER,
	CONSTRAINT FK_IdSector FOREIGN KEY(IdSector) REFERENCES SECTORS(IdSector) ON DELETE CASCADE, #Clave foranea IdSector que apunta al campo IdSector de la tabla SECTORS. 
    CONSTRAINT FK_IdWorkTool FOREIGN KEY(IdWorkTool) REFERENCES WORKTOOLS(IdWorkTool) ON DELETE CASCADE #Clave foranea IdWorkTool que apunta al campo IdWorkTool de la tabla WORKTOOLS. 
);

CREATE TABLE WORKERS #Creo la tabla trabajadores.
(
	IdWorker INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    workerName VARCHAR(40),
    IdJob INTEGER,
    CONSTRAINT FK_IdJob FOREIGN KEY(IdJob) REFERENCES JOBS(IdJob) ON DELETE CASCADE #Clave foranea IdJob que apunta al campo IdJob de la tabla JOBS. 
);

CREATE TABLE USERS #Creo la tabla users.
(
	IdUser INTEGER PRIMARY KEY AUTO_INCREMENT NOT NULL,
    userName VARCHAR(40) NOT NULL,
    passwordUser VARCHAR(40) NOT NULL,
    IdWorker INTEGER NOT NULL,
    CONSTRAINT FK_IdWorker FOREIGN KEY(IdWorker) REFERENCES WORKERS(IdWorker) ON DELETE CASCADE #Clave foranea IdWorker que apunta al campo IdWorker de la tabla Workers. 
); 

INSERT INTO WORKTOOLS(IdWorkTool, workToolName) #Le agrego los datos a la tabla WORKTOOLS.
VALUES
('11', 'Sierra'),
('12', 'Jeringa'),
('13', 'Computadora'),
('14', 'Soldador'),
('15', 'Libreta');

INSERT INTO SECTORS(IdSector, sectorName) #Le agrego los datos a la tabla SECTORS.
VALUES
('1', 'Carpinteria'),
('2', 'Laboratorio'),
('3', 'Ofisina'),
('4', 'Fabrica'),
('5', 'Administracion');

INSERT INTO JOBS(IdJob, jobName, descriptionJob, IdSector, IdWorkTool) #Le agrego los datos a la tabla JOBS.
VALUES
('30','Carpintero/a','Cortar y lijar madera','1','11'),
('31','Cientifico/a','Analizar muestras','2','12'),
('32','Contador/a','Administrar y analizar gastos','3','13'),
('33','Obrero/a','Ensamblar materiales','4','14'),
('34','Administrador/a','Administrar roles de trabajo','5','15');

INSERT INTO WORKERS(IdWorker, workerName, IdJob) #Le agrego los datos a la tabla WORKERS.
VALUES
('101','Julieta Sanchez','30'),
('102','Julio Fernandez','31'),
('103','Fernanda Silva','32'),
('104','Paulo Araujo','33'),
('105','Marcela Liuvo','34');

INSERT INTO USERS(IdUser, userName, passwordUser, IdWorker) #Le agrego los datos a la tabla USERS.
VALUES
('71','JuSa_i0','Mr432','101'),
('72','JulioFer34','Fenandez345','102'),
('73','Silvi007','098787','103'),
('74','PauloAraujo21','Sinser034','104'),
('75','Liuvio','1109@','105');

#Le pido que me muestre todos los datos de todas las tablas.
SELECT*FROM USERS;
SELECT*FROM WORKERS;
SELECT*FROM JOBS;
SELECT*FROM SECTORS;
SELECT*FROM WORKTOOLS;

TRUNCATE USERS; #Elimino los datos de la tabla USERS.

ALTER TABLE USERS DROP FOREIGN KEY FK_IdWorker; #Elimino la clave foranea de IdWorker.
ALTER TABLE USERS MODIFY IdWorker INT UNSIGNED; #La modifico para que sea un int sin signo.

TRUNCATE WORKERS; #Elimino los datos de la tabla WORKERS.

ALTER TABLE WORKERS DROP FOREIGN KEY FK_IdJob; #Elimino la clave foranea de IdJob.
ALTER TABLE WORKERS MODIFY IdJob INT UNSIGNED; #La modifico para que sea un int sin signo.

TRUNCATE JOBS; #Elimino los datos de la tabla JOBS.

ALTER TABLE JOBS DROP FOREIGN KEY FK_IdSector; #Elimino la clave foranea de IdSector.
ALTER TABLE JOBS MODIFY IdJob INT UNSIGNED; #La modifico para que sea un int sin signo.

ALTER TABLE JOBS DROP FOREIGN KEY FK_IdWorkTool; #Elimino la clave foranea de IdWorkTool.
ALTER TABLE JOBS MODIFY IdWorkTool INT UNSIGNED; #La modifico para que sea un int sin signo.

TRUNCATE SECTORS; #Elimino los datos de la tabla SECTORS.

TRUNCATE WORKTOOLS; #Elimino los datos de la tabla WORKTOOLS.

#Elimino todas las tablas.
DROP TABLE USERS;
DROP TABLE WORKERS;
DROP TABLE JOBS;
DROP TABLE SECTORS;
DROP TABLE WORKTOOLS;

DROP DATABASE MySQL_Project; #Elimino la base de datos.