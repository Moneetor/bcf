CREATE TABLE articles (
id_a INTEGER PRIMARY KEY NOT NULL AUTO_INCREMENT,
nazwa_art VARCHAR(100),
PKWIU VARCHAR(20),
rabat DOUBLE(5,1) NOT NULL DEFAULT 0,
price DOUBLE(10,2) NOT NULL DEFAULT 0,
VATP DOUBLE(5,1) NOT NULL DEFAULT 22,
jm VARCHAR(20)
) TYPE=InnoDB;
