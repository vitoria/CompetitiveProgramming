n = int(input())
board = []

def solve(x, y):
  if x == 4 and y == 4:
    return True
  if x > 4 or y > 4 or x < 0 or y < 0 or board[x][y] != 0:
    return False
  board[x][y] = 1
  return solve(x-1, y) or solve(x, y-1) or solve(x+1, y) or solve(x, y+1)

for i in range(n):
  count = 0
  while count < 5:
    inputs = input().split()
    if len(inputs) < 5:
      count = count
    else:
      board.append(list(map(int, inputs)))
      count = count + 1
  if solve(0, 0):
    print('COPS')
  else:
    print('ROBBERS')

  board.clear()
