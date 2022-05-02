import sys
from collections import deque

T = int(sys.stdin.readline())

for i in range(T): 
  strP = sys.stdin.readline()
  n = int(sys.stdin.readline())
  arrayDq = deque(sys.stdin.readline().strip("[""]").split(","))
  if n == 0:
    arrayDq.clear()
  reverseCnt = 0
  isError = 0
  isReverse = 0
  for j in strP:
    if j == 'R':
      reverseCnt +=1
      isReverse = abs(isReverse-1)
    elif j == 'D':
      if arrayDq and isReverse:
        arrayDq.pop()
      elif arrayDq:
        arrayDq.popleft()
      else:
        isError = 1
        break

  if isError == 1:
    print("error")
  else: 
    if reverseCnt%2 != 0:
      arrayDq.reverse()
    print(f"[{','.join(arrayDq)}]")
  