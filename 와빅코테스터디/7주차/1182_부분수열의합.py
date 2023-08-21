import sys

N, S = map(int, sys.stdin.readline().split())
numLi = list(map(int, sys.stdin.readline().split()))
ans = 0
def backtrack(t, sum):
  global ans
  if t == N: 
    return
  if sum+numLi[t] == S:
    ans += 1

  backtrack(t+1, sum)
  backtrack(t+1, sum+numLi[t])

backtrack(0, 0)
print(ans)
  
