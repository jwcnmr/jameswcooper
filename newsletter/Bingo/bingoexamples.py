import random

for i in range(0,5):
    num = random.randint(1, 15)
    print(num, end=" ")
print()

bset=set()
while len(bset) < 5:
    num = random.randint(1, 15)
    bset.add(num)
print(bset)

bset=set()
while len(bset) < 5:
    num = random.randint(1,15)
    bset.add(num)
bara = list(bset)
random.shuffle(bara)

print(bara)
