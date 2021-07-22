# Carries out Fibonacci in harder to read code

a, b = 0, 1        #assign a=0 and b=1
while a < 1000:
    print(a)
    a,b = b, a + b  # here we swap b for a and a+b for b
    