""" Generic illustration of generator and yield"""
def sqrit(max=0):
    n = 0
    while n < max:
        yield n*n       # return each result
        n += 1          # code resumes here

# call sqrit and iterate up to max
sq = sqrit(10)  # returns an iterator
for s in sq:
    print(s)

