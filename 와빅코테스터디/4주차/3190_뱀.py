import sys
from collections import deque

N = int(sys.stdin.readline())
K = int(sys.stdin.readline())

board = [[0 for _ in range(N+1)] for _ in range(N+1)]
for i in range(K):
  r, c  = map(int, sys.stdin.readline().split())
  board[r][c] = 1
L = int(sys.stdin.readline())

dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]
snakeDeq = deque()
snakeDeq.append([1, 1])
ans = 0
timeDeq = deque()
for _ in range(L):
  timeDeq.append(list(map(lambda x: [int(x[0]), x[1]], [sys.stdin.readline().split()]))[0])
print(timeDeq)
x, y = 1, 1
direction = 0

while True:
  ans += 1
  print(board)
  x = x + dx[direction]
  y = y + dy[direction]
  if x >= 1 and x <= N and y >= 1 and y <= N and board[y][x] != 2:
    if board[y][x] == 1:
      board[y][x] = 2
      snakeDeq.append([y, x])
    elif board[y][x] == 0:
      board[y][x] = 2
      snakeDeq.append([y, x])
      tail_y, tail_x = snakeDeq.popleft()
      board[tail_y][tail_x] = 0
  else: 
    break
  if timeDeq and timeDeq[0][0] == ans:
    if timeDeq[0][1] == 'L':
      direction = (direction-1)%4
    else:
      direction = (direction+1)%4
    timeDeq.popleft()
      
print(ans)
