from dataclasses import dataclass

@dataclass
class Fibo():
    max:int

    def fibo(self):
        current, prev = 0, 1    #initialize

        while current < self.max:  # but stops at max
            secondLast, prev = prev, current
            # compute next x as sum of previous 2
            current = prev + secondLast
            yield current

fb = Fibo(100).fibo()
for f in fb:
    print(f)
