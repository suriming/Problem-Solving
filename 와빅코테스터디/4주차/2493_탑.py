import sys
from collections import deque

N = int(sys.stdin.readline())
topLi = list(map(int, sys.stdin.readline().split()))

ans = [0]*N
topDq = deque()

for i in range(N-1, -1, -1):
  while topDq and topLi[i] > topLi[topDq[-1]]:
    ans[topDq.pop()] = i+1
  topDq.append(i)

print(' '.join(map(str, ans)))

