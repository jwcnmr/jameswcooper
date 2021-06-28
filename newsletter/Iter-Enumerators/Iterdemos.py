"""Demonstration of iterators and enumeration"""

states = ['Alaska', 'Alabama', 'Colorado', 'Delaware','Florida', 'Ohio']

# list out states
for s in states:
    print(s, end=' ')
print()

# list states and index
for index, s in enumerate(states):
    print(index, s)

# copy array so original doesn't change
tempStates = states.copy()
# find longest name and remove it
length = 0
sindex=0
for index, s in enumerate(tempStates):
    if len(s) > length:
        length = len(s)
        sindex = index
tempStates.pop(sindex)      # remove longest name
print(states)

# capitals
capitals = ['Fairbanks', 'Montgomery', 'Denver', 'Dover', 'Tallahassee','Columbus' ]

#zip together capitals and states
for cap, state in zip(capitals, states):
    print(f'{cap}, {state}')

# dictionary af abbreviations and states
sdict = {'AK':'Alaska', 'AL':'Alabama', 'CO':'Colorado',
         'DE': 'Delaware', 'FL': 'Florida', 'OH': 'Ohio'}
# print out abbreviations and states
for init, state in sdict.items():
    print(init, state)

# print index, capital and state
for i, (init, state) in enumerate(sdict.items()) :
    print (i, init, state)

