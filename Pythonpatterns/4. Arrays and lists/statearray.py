"""Read file into array"""
DATAFILE="stateNames.txt"

with open(DATAFILE, "r") as f:
    statenames=[]
    for sname in f:
        statenames.append(sname.rstrip())

print(statenames[0:3])
print(len(statenames))

f = open(DATAFILE, "r") # open the file
statenames=[]           # create the empty list

# read in the state names
for sname in f:
    statenames.append(sname.rstrip())
f.close()

print(statenames[0:4])
print(len(statenames))

f = open(DATAFILE, "r") # open the file
statenames=[]
statenames = f.readlines()
print(statenames[0:3])
print(len(statenames))