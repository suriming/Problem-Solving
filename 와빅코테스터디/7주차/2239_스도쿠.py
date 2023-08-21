import sys


board = [list(map(int, sys.stdin.readline().rstrip())) for _ in range (9)]

#print(board)
zeroLi = []
for i in range(9):
  for j in range(9):
    if not board[i][j]:
      zeroLi.append([i, j])
#print(len(zeroLi))
#print(zeroLi)

def backtrack(t):
  if t == len(zeroLi):
    for i in range(9):
      for j in range(9):
        print(board[i][j], end="")
      print()
    exit()
      
  numbers = [i for i in range(1, 10)]
  k, l = zeroLi[t][0], zeroLi[t][1]
  r, c = zeroLi[t][0]//3, zeroLi[t][1]//3
  
  for i in range(9):
    if board[i][l] in numbers:
      numbers.remove(board[i][l])
    if board[k][i] in numbers:
        numbers.remove(board[k][i])

#   for i in range(9):
#     if board[r][i] in numbers:
#       numbers.remove(board[i][j])

  for i in range(r*3, (r+1)*3):
    for j in range(c*3, (c+1)*3):
      if board[i][j] in  numbers:
        numbers.remove(board[i][j])

  for i in numbers:
    board[k][l] = i
    backtrack(t+1)
    #못풀고나오면
  board[k][l] = 0

backtrack(0)
