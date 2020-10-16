from math import log, floor

tests = int(input())

for i in range(tests):
  n, k = list(map(int, input().split()))
  nums = list(map(int, input().split()))

  ans = 0
  base = 30

  while base >= 0:
    candidates = []
    for num in nums:
      if num & 1<<base:
        candidates.append(num)

    if len(candidates) >= k:
      nums = candidates

    base = base - 1

  nums.sort()
  
  for num in nums:
    if ans == 0:
      ans = num
    else:
      ans = ans & num

  print(ans)

