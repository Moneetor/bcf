INSERT INTO prt_adresy(ulica,nr_domu1,nr_domu2,lokal1,lokal2,zip,city)
SELECT DISTINCT Adres,0,'',0,'',Kod,m.id_m FROM adresy_src a
JOIN miasta AS m
ON m.miasto=a.Miasto;