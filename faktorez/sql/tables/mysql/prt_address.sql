CREATE TABLE prt_adresy (
id_umow int(7) UNSIGNED NOT NULL AUTO_INCREMENT,
ulica VARCHAR(35) default NULL,
nr_domu1 SMALLINT(5) unsigned,
nr_domu2 CHAR(1),
lokal1 SMALLINT(5) UNSIGNED,
lokal2 CHAR(1),
zip CHAR(6),
city SMALLINT NOT NULL DEFAULT 1,
PRIMARY KEY  (id_umow),
KEY ulica_i (city, ulica(5), nr_domu1),
KEY lokal_i (nr_domu2)
) ENGINE=InnoDB;
