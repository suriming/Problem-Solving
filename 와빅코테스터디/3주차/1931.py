import sys

N = int(sys.stdin.readline())
timeLi = []

for i in range(N):
  timeLi.append(list(map(int, sys.stdin.readline().split())))

timeLi.sort(key = lambda x : x[0])
timeLi.sort(key = lambda x : x[1])

start = 0
end = 0 
cnt = 0
for i in range(N):
  if timeLi[i][0] >= start:
    cnt += 1
    start = timeLi[i][1]

print(cnt)

