tests = int(input())

for i in range(tests):
  n, k = list(map(int, input().split()))
  nums = list(map(int, input().split()))

  maxNum = 0
  pot = 30

  while pot >= 0:
    candidates = []
    for num in nums:
      if num & (1<<pot):
        candidates.append(num)

    if len(candidates) >= k:
      nums = candidates
      maxNum = maxNum + (1<<pot)

    pot = pot - 1

  print(maxNum)

