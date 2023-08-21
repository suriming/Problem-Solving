import sys

N, K = map(int, sys.stdin.readline().split())
arriveLi = []
#초갯수랑 사람이랑 차이나는 만큼 dif가 작은 순서대로 dif-1만큼 채우자
need = N-K
difLi = []
ans = N
if need <= 0:
  pass
else:
  for i in range(N):
    dif = 0
    arriveLi.append(int(sys.stdin.readline()))
    if i == 0:
      continue
    difLi.append(arriveLi[i]-arriveLi[i-1])
    difLi.sort()
ans += sum(difLi[:need])-need
print(ans)
    