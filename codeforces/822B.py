inputs = list(map(int, input().split()))
n = inputs[0]
m = inputs[1]
s = str(input())
t = str(input())

low = 1e9
v = []
curr = []
ans = ''

for i in range(0, m - n + 1):
    for j in range (0, n):
        if s[j] != t[i+j]:
            curr.append(j + 1)
    if low > len(curr):
        low = len(curr)
        v = curr
    curr = []

for i in range(0, len(v)):
    ans += str(v[i]) + ' '

print(len(v))
print(ans)