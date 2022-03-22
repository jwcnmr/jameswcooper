from multipledispatch import dispatch

@dispatch( float)
def add(aval:float )->float:
    return aval + sumval

@dispatch(str)
def add(sval: str)->float:
    return float(sval)+ sumval

sumval = 12
theSum = add(30.1)
print(theSum)

sumval=22
theSum = add("34")
print(theSum)

