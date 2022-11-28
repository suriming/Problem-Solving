import sys

N, M = map(int, sys.stdin.readline().split())
r, c, d = map(int, sys.stdin.readline().split())
placeBoard = []
for _ in range(N):
  placeBoard.append(list(map(int, sys.stdin.readline().split())))

cleanCnt = 0

rDirection = [-1, 0, 1, 0]
cDirection = [0, 1, 0, -1]
side = 0
def turn():
  global rDirection
  global cDirection
  global side
  
  


while True:

