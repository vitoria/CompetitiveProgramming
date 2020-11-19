import math

def printColoresPiles(piles):
  for pile in piles:
    s = str(pile[0])
    for i in range(1, len(pile), 1):
      s = s + ' ' + str(pile[i])
    print(s)

n, k = list(map(int, input().split()))
piles = list(map(int, input().split()))

max_pile = max(piles)
min_pile = min(piles)

if max_pile - min_pile > k:
  print('NO')
else:
  print('YES')


  colored_piles = []

  for pile in piles:
    colored_piles.append([])
    color = 0
    for i in range(pile):
      colored_piles[len(colored_piles) - 1].append(color + 1)
      color = (color + 1) % k

  printColoresPiles(colored_piles)
