x=7            # 0111
#print(bin(x))
print(f"{x:04b}")
z = 10           #1010  
print(f"{z:04b}")
res = x & z  # 7 & 10 is 0010
#print(bin(res))
print(f"{res:04b}")
res=  x | z  # 7 | 10 is 1111
print(f"{res:04b}")  
res=  x ^ z  # 7 xor 10 = 1101
print(f"{res:04b}")  

# left shift
print(f"{ x<<1 :04b}")
#right shift
print(f"{ x>>1 :04b}")

# Exclusive OR gives one if only one of the bits is set,
res = x ^ z
print(f"{res:04b}")

res= ~z
print(f"{res:04b}")
print(bin(res))