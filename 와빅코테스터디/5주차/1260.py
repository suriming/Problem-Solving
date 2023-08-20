import sys
from collections import deque

N, M, V = map(int, sys.stdin.readline().split())


def DFS(graph, v, visited):
  visited[v] = True
  print(v, end=' ')
  for i in graph[v]:
    if not visited[i]:
      DFS(graph, i, visited)
      
def BFS(graph, start, visited):
  queue = deque([start])
  visited[start] = True
  while queue:
    v = queue.popleft()
    print(v, end=' ')
    for i in graph[v]:
      if not visited[i]:
        queue.append(i)
        visited[i] = True
      
visited = [False] * (N+1)

graph = [[] for _ in range(N+1)]

for i in range(M):
  tmp1, tmp2 = map(int, sys.stdin.readline().split()) 
  #list(map(int, sys.stdin.readline().split()))
  graph[tmp1].append(tmp2)
  graph[tmp2].append(tmp1)
  
for i in graph:
  i.sort()
  
DFS(graph, V, visited)
print()
for i in range(N+1):
  visited[i] = False
BFS(graph, V, visited)