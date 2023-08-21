import sys
from collections import deque

N = int(sys.stdin.readline())
graph = []
 
for i in range(N):
  #graph = [list(map(int, input().split())) for _ in range N]
  graph.append(list(map(int, input().split())))
  for j in range(N):
    if graph[i][j] == 9:
      sharkR = i
      sharkC = j
      graph[i][j] = 0
dr = [1, 0, -1, 0]
dc = [0, -1, 0, 1]


def BFS(sharkR, sharkC, sharkSize):
  queue = deque()
  queue.append((sharkR, sharkC))
  visited[sharkR][sharkC] = 1
  while queue:
    #print(queue)
    r, c = queue.popleft()
    for i in range(4):
      nr = r + dr[i]
      nc = c + dc[i]
      #갈 수 있는지만체크
      if 0<=nr<N and 0<=nc<N and graph[nr][nc]<=sharkSize and visited[nr][nc]==0:
        visited[nr][nc] = visited[r][c] + 1
        queue.append((nr, nc))
  #print(visited)
  moveR = 0
  moveC = 0
  compr = N*N
  isFish = False
  for j in range(N):
    for k in range(N):
      #물고기체크
      if graph[j][k]>=1 and visited[j][k]>=1 and graph[j][k]<sharkSize:
        #tmp = abs(j-sharkR) + abs(k-sharkC)
        isFish = True
        if visited[j][k]-1 < compr:
          compr = visited[j][k]-1
          moveR = j
          moveC = k
  if compr == N*N:
    compr = 0
  #print(dist)
  #print(graph)
  return moveR, moveC, compr, isFish
  

          
sharkSize = 2
ans = 0
sharkHad = 0
while True:
  #isFish = False
  visited = [[0]*N for _ in range (N)]    
  sharkR, sharkC, dist, isFish = BFS(sharkR, sharkC, sharkSize)
  #print(sharkR)
  if not isFish:
    break
  elif dist!= 0:
    ans += dist
    sharkHad += 1
    #상어움직인곳!!!
    graph[sharkR][sharkC] = 0
    if sharkHad == sharkSize:
      sharkHad = 0
      sharkSize += 1
    #print(graph)

print(ans)



    
    


