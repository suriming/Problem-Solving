import sys
from turtle import back

N, M = map(int, sys.stdin.readline().split())

isChecked = [False] * N
numLi = []
def dfs():

  if len(numLi) == M:
    for i in range(M):
      print(numLi[i], end=" ")
    print()
    return

  for i in range(N):
    if isChecked[i] == False:
      numLi.append(i+1)
      isChecked[i] = True
      dfs() 
      isChecked[i] = False
      numLi.pop()

dfs()