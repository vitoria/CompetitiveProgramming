import random

n = random.randint(1, 10)

print n

l = [ random.randint(1, 100) for i in xrange(n) ]

l.sort()

for i in l:
    print i,

print


q = random.randint(1, 12)

print q

for i in xrange(q):
    print random.randint(1, 100), random.randint(1, 20)
