CREATE TABLE prt_adresy (
id_umow INTEGER PRIMARY KEY AUTOINCREMENT,
ulica VARCHAR(35) default NULL,
nr_domu1 SMALLINT unsigned,
nr_domu2 CHAR(1),
lokal1 SMALLINT UNSIGNED,
lokal2 CHAR(1),
zip CHAR(6),
city SMALLINT NOT NULL DEFAULT 1
);