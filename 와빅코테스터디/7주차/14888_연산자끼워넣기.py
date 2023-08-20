import sys

N = int(sys.stdin.readline())

seqLi = list(map(int, sys.stdin.readline().split()))
addNum, subNum, mulNum, divNum = map(int, sys.stdin.readline().split())

maxVal = -1e9
minVal = 1e9
def backtrack(t, recent):
  global addNum, subNum, mulNum, divNum, maxVal, minVal
#   if minVal == 0.1 and t==N:
#     minVal = recent
#     maxVal = recent

  if t==N:
    maxVal = max(maxVal, recent)
    minVal = min(minVal, recent)
    return

  else:
    if addNum:
      addNum -= 1
      backtrack(t+1, seqLi[t]+ recent)
      addNum += 1
    if subNum:
      subNum -= 1
      backtrack(t+1, recent - seqLi[t])
      subNum += 1
    if mulNum:
      mulNum -= 1
      backtrack(t+1, seqLi[t]*recent)
      mulNum += 1
    if divNum:
      divNum -= 1
      backtrack(t+1, int(recent/seqLi[t]))
      divNum += 1

backtrack(1, seqLi[0])
print(maxVal)
print(minVal)