import sys

N = int(sys.stdin.readline())

numLi = list(map(int, sys.stdin.readline().split()))
cnt = 0
isAllZero = False
while not isAllZero:
  isAllZero = True
  isAllEven = True
  for i in range(N):
    if numLi[i]:
      isAllZero = False
    if (numLi[i]%2):
      numLi[i] -= 1
      cnt +=1
      isAllEven = False
  if not isAllZero and isAllEven:
    cnt += 1
    for i in range(N):
      numLi[i] = numLi[i]//2
print(cnt)