"""Illustrates a simple interior function
used as a decorator"""
#decorator that wraps a function
def mathFunc(func):
    def wrapper(x):
        print("b4 func")
        func(x)
        print("after func")
    return wrapper
# Decorator wraps sayMath
@mathFunc
def sayMath(x):
    print("math")


# create wrapped function
print("call after making decorator")

sayMath(12) #call decorated function