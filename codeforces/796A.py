inputs = list(map(int, input().split()))
n = inputs[0]
m = inputs[1]
k = inputs[2]
houses = list(map(int, input().split()))

ans = n - 1

for i in range(0, n):
    if i != (m - 1) and houses[i] != 0 and houses[i] <= k:
        curr = abs(m - i - 1)
        ans = min(curr, ans)

ans *= 10

print(ans)