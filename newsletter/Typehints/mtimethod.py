from mtimethod import multimethod

# declare the float, float version
@multimethod
def add(aval:float, bval:float)->float:
    return aval + bval

# declare the string, float version
@multimethod
def add(sval: str, bval: float)->float:
    return float(sval)+ bval

# call the float, float version
theSum = add(22.1, 33.2)
print(f'{theSum:5.2f}')

# call the string, float version
theSum =  add('32.2', 33.1)
print(f'{theSum:5.2f}')