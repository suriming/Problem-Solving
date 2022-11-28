import sys

N, M, x, y, K = map(int, sys.stdin.readline().split())

diceLi = [0 for _ in range(7)]
# mapBoard = [[0 for _ in range(M)] for _ in range(N)]
mapBoard = []
for i in range(N):
  mapBoard.append(list(map(int, sys.stdin.readline().split())))

moveLi = list(map(int, sys.stdin.readline().split()))

for i in moveLi:
  if i == 1: 
    if 0 <= y+1 < M:
      y = y + 1
      d1, d2, d3, d4, d5, d6 = diceLi[1], diceLi[2], diceLi[3], diceLi[4], diceLi[5], diceLi[6]     
      diceLi[1], diceLi[4], diceLi[3], diceLi[6]  = d3, d1, d6, d4
      if mapBoard[x][y] == 0:
        mapBoard[x][y] = diceLi[1]
      else:
        diceLi[1] = mapBoard[x][y]
        mapBoard[x][y] = 0
      print(diceLi[6])

  if i == 2:
    if 0 <= y-1 < M:
      y = y - 1
      d1, d2, d3, d4, d5, d6 = diceLi[1], diceLi[2], diceLi[3], diceLi[4], diceLi[5], diceLi[6]
      diceLi[1], diceLi[6], diceLi[3], diceLi[4] = d4, d3, d1, d6 
      if mapBoard[x][y] == 0:
        mapBoard[x][y] = diceLi[1]
      else:
        diceLi[1] = mapBoard[x][y]
        mapBoard[x][y] = 0
      print(diceLi[6])

  if i == 3:
    if 0 <= x-1 < N:
      x = x-1
      d1, d2, d3, d4, d5, d6 = diceLi[1], diceLi[2], diceLi[3], diceLi[4], diceLi[5], diceLi[6]
      diceLi[1], diceLi[2], diceLi[5], diceLi[6] = d2, d6, d1, d5
      if mapBoard[x][y] == 0:
        mapBoard[x][y] = diceLi[1]
      else:
        diceLi[1] = mapBoard[x][y]
        mapBoard[x][y] = 0
      print(diceLi[6])
      
  if i == 4:
    if 0 <= x+1 < N:
      x = x+1
      d1, d2, d3, d4, d5, d6 = diceLi[1], diceLi[2], diceLi[3], diceLi[4], diceLi[5], diceLi[6]
      diceLi[1], diceLi[5], diceLi[6], diceLi[2] = d5, d6, d2, d1
      if mapBoard[x][y] == 0:
        mapBoard[x][y] = diceLi[1]
      else:
        diceLi[1] = mapBoard[x][y]
        mapBoard[x][y] = 0
      print(diceLi[6])