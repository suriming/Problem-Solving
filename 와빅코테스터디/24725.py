import sys

N, M = map(int, sys.stdin.readline().split())
alphabetBoard = []
for _ in range (N):
  alphabetBoard.append(list(sys.stdin.readline()))

def checkFunc(checkLi):
  if checkLi[0] == 'E' or checkLi[0] == 'I':
    if (checkLi[1] == 'N' or checkLi[1] == 'S') and (checkLi[2] == 'F' or checkLi[2] == 'T') and (checkLi[3] == 'P' or checkLi[3] == 'J'):
      return 1
  elif checkLi[0] == 'P' or checkLi[0] == 'J':
    if (checkLi[1] == 'F' or checkLi[1] == 'T') and (checkLi[2] == 'N' or checkLi[2] == 'S') and (checkLi[3] == 'E' or checkLi[3] == 'I'):
      return 1
  else: 
    return 0
    
ans = 0 

for i in range(N):
  for j in range(M):
    if j+3 < M: 
      checkLi = []
      checkLi = alphabetBoard[i][j:j+4]
      if checkFunc(checkLi) == 1:
        ans += 1
      print(checkLi)
    if i+3 < N:
      checkLi = []
      for k in range(4):
        checkLi.append(alphabetBoard[i+k][j])
      if checkFunc(checkLi) == 1:
        ans += 1
      print(checkLi)
    if i+3 < N and j+3 < M:
      checkLi = []
      for k in range(4):
        checkLi.append(alphabetBoard[i+k][j+k])
      if checkFunc(checkLi) == 1:
        ans += 1
      print(checkLi)
    if i+3 < N and j-3 >= 0:
      checkLi = []
      for k in range(4): 
        checkLi.append(alphabetBoard[i+k][j-k])
      if checkFunc(checkLi) == 1:
        ans += 1 
      print(checkLi)    
print (ans)