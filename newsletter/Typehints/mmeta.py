from multimethod import multimeta

class Add(metaclass=multimeta):
    # float, float
    def add(self, aval: float, bval: float) -> float:
        return aval + bval
    # string, float
    def add(self, sval: str, bval: float) -> float:
        return float(sval) + bval

adder = Add()
theSum = adder.add(33.2,31.2)
print(f'{theSum:5.2f}')

theSum = adder.add('44.2', 23.2)
print(f'{theSum:5.2f}')