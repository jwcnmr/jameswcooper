"""Simple example of function decorator"""
def deco(func):
    #adds a value to a new function property
    func.label = "decorated"
    return func

# Complete empty function,
# that is decorated by the "deco" decorator
@deco
def f():
    pass

print(f.label)
