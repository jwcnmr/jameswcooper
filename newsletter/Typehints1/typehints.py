""" Illustration of type hints """
def adder(x:float, s:str)->float:
    sumRes: float = x + float(s)
    return sumRes

def adder(x: float, y: float) -> float:
    sumRes: float = x + y
    return sumRes

result: float = adder(2, "3")
print(result)
result = adder(1, 2)
print(result)
