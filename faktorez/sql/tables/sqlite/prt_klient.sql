CREATE TABLE prt_klient (
  id_k INTEGER unsigned NOT NULL default 1,
  symbol varchar(20) default NULL,
  nazwisko TEXT,
  adres INTEGER NOT NULL DEFAULT 1,
  NIP VARCHAR(13) DEFAULT NULL,
  REGON VARCHAR(9) DEFAULT NULL,
  PRIMARY KEY  (id_k)
);
