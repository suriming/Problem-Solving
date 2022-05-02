import sys

N, M = map(int, sys.stdin.readline().split())

def i_func(R, G, B):

  I = 2126*R + 7152*G + 722*B

  if 0 <= I < 510000:
    return "#"

  elif 510000 <= I < 1020000:
    return "o"

  elif 1020000 <= I < 1530000:
    return "+"

  elif 1530000 <= I <2040000:
    return "-"

  elif 2040000 <= I:
    return "."

for i in range(N):
  rgbLi = list(map(int, sys.stdin.readline().split()))
  for j in range(0, 3*M, 3):
    print(i_func(rgbLi[j], rgbLi[j+1], rgbLi[j+2]), end='')
  print()
