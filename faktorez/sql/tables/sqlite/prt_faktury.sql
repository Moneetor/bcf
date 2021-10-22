CREATE TABLE prt_faktury (
id_fakt INTEGER PRIMARY KEY AUTOINCREMENT,
faktura VARCHAR(35),
platnosc VARCHAR(20) NOT NULL DEFAULT 'Przelew',
data_sprz DATETIME,
data_wyst DATETIME,
data_zapl DATETIME,
number SMALLINT,
ext VARCHAR(10),
printed BOOL,
to_print BOOL,
klient INTEGER NOT NULL DEFAULT 1,
print_copy BOOL,
print_master BOOL
);
