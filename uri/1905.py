n = int(input())

def solve(b, x, y):
  if x == 4 and y == 4:
    return True
  if x > 4 or y > 4 or x < 0 or y < 0 or b[x][y] != 0:
    return False
  b[x][y] = 1
  return solve(b, x-1, y) or solve(b, x, y-1) or solve(b, x+1, y) or solve(b, x, y+1)

for i in range(n):
  board = []
  input()
  for i in range(5):
    board.append(list(map(int, input().split())))
  
  if solve(board, 0, 0):
    print('COPS')
  else:
    print('ROBBERS')
