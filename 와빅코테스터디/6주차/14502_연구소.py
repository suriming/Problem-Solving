import sys
from collections import deque
import copy

R, C = map(int, sys.stdin.readline().split())
graph = []
for r in range(R):
  graph.append(list(map(int, sys.stdin.readline().split())))

print(graph)
dy = [1, 0, -1, 0]
dx = [0, 1, 0, -1]
ans = 0
def BFS(): 
  #if wallNum == 3:
    global ans
    queue = deque()
    graphCopy = copy.deepcopy(graph)
    #print(graphCopy)
    for r in range(R):
      for c in range(C):
        if graphCopy[r][c] == 2:
          queue.append((r, c))
    while queue:
      #lev = len(queue)
      #for _ in range(lev):
        #print(queue)
        y, x = queue.popleft()
        for i in range(4):
          ny = y + dy[i]
          nx = x + dx[i]
          if 0<=nx<C and 0<=ny<R:
            if graphCopy[ny][nx] == 0:
              graphCopy[ny][nx] = 2
              queue.append((ny, nx))
    cnt = 0
    #print(graphCopy)
    for i in range(R):
      for j in range(C):
        if graphCopy[i][j]  == 0:
          cnt += 1

    ans = max(ans, cnt)
    return
  

wallNum = 0
def wall(wallNum):
  if wallNum == 3:
    BFS()
    return
  for r in range(R):
    for c in range(C):
      if graph[r][c] == 0:
        graph[r][c] = 1
        wall(wallNum+1)
        graph[r][c] = 0
  
# for i in range(R):
#   for k in range(C):
#     for j in range(R):
#       for l in range(C):
#         for r in range(R):
#           for c in range(C): 
#             while (wallNum <=2):
#               if graph[i][k] == 0:
#                 graph[i][k] = 3
#                 wallNum += 1
#               if graph[j][l] == 0:
#                 graph[j][l] = 3
#                 wallNum += 1
#               if graph[r][c] == 0:
#                 graph[r][c] = 3
#                 wallNum += 1
#               break
#             if wallNum == 3:
#               BFS()
#               graph[r][c] = 0
#               wallNum -= 1
#         if graph[j][l] == 3:
#           graph[j][l] = 0
#           wallNum -= 1
#     if graph[i][k] == 3:
#       graph[i][k] = 0
#       wallNum -= 1

# for r in range(R):
#   for c in range(C):
#     if graph[r][c] == 0:
#       graph[r][c] = 1
#       wallNum += 1
#       if wallNum == 3:
#         BFS()
#         graph[r][c] = 0 
#         wallNum -= 1
#     graph[r][c]
wall(0)
print(ans)
      

    

