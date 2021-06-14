import csv
from csv import reader

nm =[]
nm.append(['Fred', 'Farkel', '1245 Bridge St','Bridgeport', 'CT'])
nm.append(['Sam', "O'Kelley", '42 Secret Lane', 'Mystic', 'CT'])
nm.append(["Sarah", 'Smythe', '205 Frazzle Rd, Apt B', 'Fairfield', 'CT'])

# create the csv file
with open ('namelist.csv', 'w', newline='') as csvfile:
    addWriter = csv.writer(csvfile)
    for row in nm:
        addWriter.writerow(row)

# now read it back in
with open ('namelist.csv', newline='') as csvfile:
    addReader = csv.reader(csvfile)
    for row in addReader:
        print(row)
