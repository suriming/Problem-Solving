import sys

R, C, T = map(int, sys.stdin.readline().split())
houseBoard = []
upperAirR = 0
lowerAirR = 0
for i in range (R):
  tmp = list(map(int, sys.stdin.readline().split()))
  if tmp[0] == -1:
    lowerAirR = i
  houseBoard.append(tmp)
upperAirR = lowerAirR - 1
  

def diffuse():
  global houseBoard
  newHouseBoard = [item[:] for item in houseBoard]
  for r in range(R):
    for c in range(C):
      if houseBoard[r][c] >= 5:
        oneDiffused = houseBoard[r][c]//5
        if r-1 >=0 and houseBoard[r-1][c] != -1:
          newHouseBoard[r-1][c] += oneDiffused
          newHouseBoard[r][c] -= oneDiffused
        if r+1 < R and houseBoard[r+1][c] != -1:
          newHouseBoard[r+1][c] += oneDiffused
          newHouseBoard[r][c] -= oneDiffused 
        if c-1 >= 0 and houseBoard[r][c-1] != -1:
          newHouseBoard[r][c-1] += oneDiffused
          newHouseBoard[r][c] -= oneDiffused 
        if c+1 < C and houseBoard[r][c+1] != -1:
          newHouseBoard[r][c+1] += oneDiffused
          newHouseBoard[r][c] -= oneDiffused  
  houseBoard = [item[:] for item in newHouseBoard]

upperAirC= 0
lowerAirC = 0

def upClean():
  global houseBoard
  rDirection = [0, -1, 0, 1]
  cDirection = [1, 0, -1, 0]
  where = 0
  tmp = 0
  rSaved, cSaved = upperAirR, 1
  while (rSaved != upperAirR or cSaved != 0):
    pushedX = rSaved + rDirection[where]
    pushedY = cSaved + cDirection[where]
    if pushedX < 0 or pushedX >= R or pushedY < 0 or pushedY >= C:
      where += 1
      continue
    houseBoard[rSaved][cSaved], tmp = tmp, houseBoard[rSaved][cSaved]
    rSaved = pushedX
    cSaved = pushedY

def downClean():
  global houseBoard
  rDirection = [0, 1, 0, -1]
  cDirection = [1, 0, -1, 0]
  where = 0
  tmp = 0
  rSaved, cSaved = lowerAirR, 1
  while (rSaved != lowerAirR or cSaved != 0):
    pushedX = rSaved + rDirection[where]
    pushedY = cSaved + cDirection[where]
    if pushedX < 0 or pushedX >= R or pushedY < 0 or pushedY >= C:
      where += 1
      continue
    houseBoard[rSaved][cSaved], tmp = tmp, houseBoard[rSaved][cSaved]
    rSaved = pushedX
    cSaved = pushedY

for _ in range(T):
  diffuse()
  upClean()
  downClean()

ans = 0
for i in range(R):
  for j in range(C):
    if houseBoard[i][j] > 0:
      ans += houseBoard[i][j]
print(ans)