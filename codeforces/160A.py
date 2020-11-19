n = int(input())
nums = list(map(int, input().split()))
totalSum = 0
coinsSum = 0
coinsQty = 0
index = n -1

nums.sort()

for i in range(n):
  totalSum = totalSum + nums[i]

while coinsSum <= totalSum and index > -1:
  totalSum = totalSum - nums[index]
  coinsSum = coinsSum + nums[index]
  coinsQty = coinsQty + 1
  index = index - 1

print(coinsQty)
