import sys
from collections import deque 

n = int(sys.stdin.readline())
#방향한축
dh = [-1, 0, 1, 0]
dw = [0, -1, 0, 1]

h = 0
w = 0 
def fireBFS():
  for i in range(len(fireQueue)):
    j, k = fireQueue.popleft()
    for i in range(4):
      nw = k + dw[i]
      nh = j + dh[i]
      if visited[nh][nw] == False and 0<=nw and nw<w and 0<=nh and nh<h:
        if graph[nh][nw] == '.':
          fireQueue.append((nh, nw))
          graph[nh][nw] = '*'
          visited[nh][nw] = True
cnt = 0

def sanguenBFS():
  while sangeunQueue:
    for i in range (len(sangeunQueue)):
      k, l = sangeunQueue.popleft()
      for j in range(4):
        nw = l + dw[j]
        nh = k + dh[j]
        if 0<=nw and nw<w and 0<=nh and nh<h :
          if graphForTime[nh][nw] <= graphForTime[k][l] and graph[nh][nw] == '.' and graphForTime[k][l] != "*":
            sangeunQueue.append((nh, nw))
            graphForTime[nh][nw] = graphForTime[k][l] + 1
        elif nw<0 or nh<0 or nh==h or nw==w:
          #print(graphForTime)
          print(graphForTime[k][l]+1)
          return
    fireBFS()
  print("IMPOSSIBLE")

for i in range(n):
  w, h = map(int, sys.stdin.readline().split())
  graph = []
  graphForTime = [[0]*(w+1) for _ in range(h+1)]
  #print(graphForTime)
  fireQueue = deque()
  sangeunQueue = deque()
  visited = [[False for _ in range(w)] for _ in range(h)]
  for j in range(h):
    graph.append(list(sys.stdin.readline().strip()))
    for k in range(w):
      if graph[j][k] == '*':
        visited[j][k] = True
        fireQueue.append((j, k))
      if graph[j][k] == '@':
        sangeunQueue.append((j, k))
  #print(graph)
  fireBFS()
  sanguenBFS()


    

