CREATE TABLE sell (
id_s INTEGER PRIMARY KEY AUTOINCREMENT,
faktura INTEGER(7) NOT NULL DEFAULT 1,
article SMALLINT NOT NULL DEFAULT 1,
qty DOUBLE(20,3) NOT NULL DEFAULT 1
);
