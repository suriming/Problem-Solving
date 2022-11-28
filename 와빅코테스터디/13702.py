import sys

N, K = map(int, sys.stdin.readline().split())
numLi = []
for _ in range(N):
  numLi.append(int(sys.stdin.readline()))

numLi.sort()

start = 0
end = numLi[-1]
result = 0

while (start <= end):
  mid = (start + end) //2
  value = 0
  total = 0
  for i in numLi:
    value = i // mid
    total += value
  if total < K:
    end = mid - 1
  else:
    start = mid + 1
    result = mid

print(result)