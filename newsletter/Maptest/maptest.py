import dis
from datetime import datetime

def sq(x):
    return x*x

def f1():
    start = datetime.now()
    for i in range (0, 1000000):
        ara=[2,3,6,8,5,4]
        amap = map(sq, ara)
        ara1 = list(amap)
        #print (ara1)
    endt = datetime.now()
    print("time=", endt-start)
    print(ara1)
    return endt-start
   
        
def f2():
    start = datetime.now()
    for i in range (0, 1000000):
        ara=[2,3,6,8,5,4]

        amap = []
        for a in ara:
            amap.append(sq(a))
    endt = datetime.now()
    print("time=", endt-start)
    return endt-start
       
t1 = f1()
t2 = f2()
print (t1,t2, (t2-t1)/t2)
#dis.dis(f1)
