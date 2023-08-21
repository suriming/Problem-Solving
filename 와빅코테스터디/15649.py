import sys

N, M = map(int, sys.stdin.readline().split())

isChecked = [False] * N
numLi = []
def dfs():
  if len(numLi) == M:
    print(' '.join(map(str, numLi)))
    return
  for i in range(N):
    if isChecked[i] == False:
      numLi.append(i+1)
      isChecked[i] = True
      dfs() 
      isChecked[i] = False
      numLi.pop()

dfs()