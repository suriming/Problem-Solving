import sys

N = int(sys.stdin.readline())

classBoard = [[0 for _ in range(N)] for _ in range(N)]
test = [[0 for _ in range(4)] for _ in range(N*N+1)]
for i in range(N*N):
  inputLi = list(map(int, sys.stdin.readline().split()))
  student = inputLi[0]
  favLi = inputLi[1:]
  test[student] = favLi
  emptyNum = 0
  favNum = 0
  rSaved = -1
  cSaved = -1 
  for r in range(N):
    for c in range(N):
      if classBoard[r][c] == 0:
        emptyTmp = 0
        favTmp = 0
        if r-1 >= 0 : 
          if classBoard[r-1][c] == 0 or classBoard[r-1][c] == student:
            emptyTmp += 1
          elif classBoard[r-1][c] in favLi:
            favTmp += 1
        if r+1 <= N-1 : 
          if classBoard[r+1][c] == 0 or classBoard[r+1][c] == student:
            emptyTmp += 1
          elif classBoard[r+1][c] in favLi: 
            favTmp += 1
        if c-1 >= 0 :
          if classBoard[r][c-1] == 0 or classBoard[r][c-1] == student:
            emptyTmp += 1
          elif classBoard[r][c-1] in favLi: 
            favTmp += 1
        if c+1 <= N-1:
          if classBoard[r][c+1] == 0 or classBoard[r][c+1] == student:
            emptyTmp += 1
          elif classBoard[r][c+1] in favLi:
            favTmp += 1

        if favTmp > favNum:
          favNum = favTmp
          emptyNum = emptyTmp
          classBoard[r][c] = student
          if rSaved == -1:
            rSaved = r
            cSaved = c
          else:
            classBoard[rSaved][cSaved] = 0
            rSaved = r
            cSaved = c
        elif favTmp == favNum and emptyTmp > emptyNum:
          favNum = favTmp
          emptyNum = emptyTmp
          classBoard[r][c] = student
          if rSaved == -1:
            rSaved = r
            cSaved = c
          else:
            classBoard[rSaved][cSaved] = 0
            rSaved = r
            cSaved = c
        
        if rSaved == -1:
          rSaved = r
          cSaved = c
          classBoard[r][c] = student
          favNum = favTmp
          emptyNum = emptyTmp
favNum = 0
favTotal = 0
for r in range(N):
    for c in range(N):
      favNum = 0
      student = classBoard[r][c]
      if r-1 >= 0 and classBoard[r-1][c] in test[student]:
        favNum +=1
      if r+1 <= N-1 and classBoard[r+1][c] in test[student]: 
        favNum +=1
      if c-1 >= 0 and classBoard[r][c-1] in test[student]: 
        favNum +=1
      if c+1 <= N-1 and classBoard[r][c+1] in test[student]:
        favNum += 1

      # print(favNum)

      if favNum == 1:
        favTotal += 1
      elif favNum == 2:
        favTotal += 10
      elif favNum == 3:
        favTotal += 100
      elif favNum == 4:
        favTotal += 1000

print(favTotal)
