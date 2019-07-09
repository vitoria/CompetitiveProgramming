from collections import deque
n, q = map(int, raw_input().split())

dequee = map(int, raw_input().split())


maior = (0, 0)
for j in xrange(n):
    if dequee[j] > maior[0]:
        maior = (dequee[j], j)

pre = [0]*(maior[1]+1)
copy = deque(dequee)
for t in xrange(maior[1]):
    A = copy.popleft()
    B = copy.popleft()
    #print A, B
    pre[t] = (A, B)
    if A > B:
        copy.appendleft(A)
        copy.append(B)
        
    else:
        copy.append(A)
        copy.appendleft(B)
    
#part = dequee[:maior[1]]
#part.sort()
#newdequee = dequee[maior[1]:] + part

for i in xrange(q):
    m = int(raw_input())
    if m <= maior[1]: print pre[m-1][0], pre[m-1][1]
    else:
        m -= maior[1]
        modu = m % (n-1)
        if modu == 0: modu = n-1
        print copy[0], copy[modu]
        #print newdequee[0], newdequee[ modu ]