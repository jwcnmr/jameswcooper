"""Dictionary examples"""
#create a list of dictionaries
slist = [
    {"abbrev":"CA", "name":"California"},
    {"abbrev":"KS", "name":"Kansas"}
]

#list out the values of "abbrev" in each dict
for st in slist:
    s = st.get("abbrev", "none")
    if s != None:
        print (st.get("name"))

#one single state dictionary, used as a hash table
states =\
{"AK": "Arkansas",
 "CA": "California",
 "CT": "Connecticut",
 "MO": "Missouri",
 "KS": "Kansas"
}
print(states.get("CT")) # a single statement gets the name we want

#a dictionary with a nested dictionary or properties
fullstates =\
{"AK": {"name": "Arkansas", "capital": "Little Rock"},
 "CA": {"name":"California", "capital": "Sacramento"},
 "CT": {"name": "Connecticut", "capital": "Hartford"},
 "MO": {"name": "Missouri", "capital": "Jefferson City"},
 "KS": {"name": "Kansas", "capital": "Topeka"}
}
data = fullstates.get("CT")     #get the nested dictionary for that state
#and print out the state name and capital from it
print ("CT " + data.get("name")+" "+data.get("capital"))

morestates =\
{"DE": "Delaware",
 "GA": "Georgia",
 "CT": "Connecticut",
 "MT": "Montana",
 "ND": "North Dakota"
}

mixedstates = states | morestates
for st in  mixedstates:
    print(st, end=" ")
