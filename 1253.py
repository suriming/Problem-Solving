import sys

N = int(sys.stdin.readline())
numLi = list(map(int, sys.stdin.readline().split()))
numLi
cnt = 0

for i in range(N):
  testLi = numLi[0:i] + numLi[i+1:]
  start = 0 
  end = N-2
  while (start < end):
    sum = testLi[start] + testLi[end]
    if (sum == numLi[i]):
      cnt += 1
      break 
    elif sum < numLi[i]:
      start += 1
    elif sum > numLi[i]:
      end -= 1

print(cnt)