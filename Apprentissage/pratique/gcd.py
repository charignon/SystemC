from fractions import *
import csv

csvfile = open("pgcd_fsm.csv", "rb")
dialect = csv.Sniffer().sniff(csvfile.read(1024))
csvfile.seek(0)
reader = csv.reader(csvfile, dialect)
count=0
for row in reader:
  pgcd=gcd(int(row[0]),int(row[1]))
  if pgcd!=int(row[2]):
    count = count +1
csvfile.close()
if count>1:
  print str(count) + " erreurs "
else:
  print str(count) + " erreur "









