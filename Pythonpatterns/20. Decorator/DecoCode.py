"""Illustrates an interior function that can be
wrapped as a decorator"""
#decorator that wraps a function
def mathFunc(func):
    def wrapper(x):
        print("b4 func")
        func(x)
        print("after func")
    return wrapper

# print out a name or phrase
def sayMath(x):
    print("math")

# create wrapped function
sayMath = mathFunc(sayMath)
print("call after making decorator")

sayMath(12)
