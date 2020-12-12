# count upper and lowercase letters
def upperLower(s):   
    upper = 0
    lower = 0
    for c in s:
        if c.islower():
            lower += 1
        elif c.isupper():
            upper += 1
    return (upper,lower)   #return a tuple     

# get counts as a tuple             
up, low = upperLower("Hello")
print(up, low)