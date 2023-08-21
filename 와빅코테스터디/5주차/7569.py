#토마토
import sys
from collections import deque

M, N, H = map(int, sys.stdin.readline().split())
graph = [[list(map(int, sys.stdin.readline().split())) for _ in range(N)] for _ in range(H)]

time = 0

ripeTomatoesInit = []
isAlready = True
for i in range(H):
  for j in range(N):
    for k in range(M):
      if graph[i][j][k] == 1:
        ripeTomatoesInit.append((0, i, j, k))
      if graph[i][j][k] == 0:
        isAlready = False
        

dx = [1, 0, 0, -1, 0, 0] #한가지축이동
dy = [0, 1, 0, 0, -1, 0]
dz = [0, 0, 1, 0, 0, -1] 

queue = deque(ripeTomatoesInit)
test = 0

while queue:
  time, z, y, x = queue.popleft()
  test += 1
  for i in range(6):
    nz = z + dz[i]
    ny = y + dy[i]
    nx = x + dx[i]

    if 0<=nx and nx<M and 0<=ny and ny<N and 0<=nz and nz<H:
      if graph[nz][ny][nx] == 0:
        graph[nz][ny][nx] = graph[z][y][x] + 1
        time = time+1
        queue.append((time, nz, ny, nx))

isFailed = False

test2 = 0
for i in range(H):
  for j in range(N):
    for k in range(M):
      if graph[i][j][k] == 0:
        isFailed = True
      if graph[i][j][k] > test2:
        test2 = graph[i][j][k]
      #print(graph[i][j][k])
  #print()

if isAlready:
  print(0)
elif isFailed:
  print(-1)
else:
  print(test2-1)