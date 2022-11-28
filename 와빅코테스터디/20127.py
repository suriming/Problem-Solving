import sys

N = int(sys.stdin.readline())
numLi = list(map(int, sys.stdin.readline().split()))

k = 0
up = 0
down = 0
same = 0

for i in range (N-1):
  if numLi[i] < numLi[i+1]:
    up += 1
  elif numLi[i] > numLi[i+1]: 
    down += 1
  else: 
    same += 1
  if up!=0 and down!=0 and k==0:
    k = i + 1

# if same != 0:
#   print('-1')
if k == 0:
  print('0')
elif up>1 and down>1:
  print('-1')
elif up == 1 and numLi[-1] >= numLi[0]:
  print(k-1)
elif down == 1 and numLi[-1] <= numLi[0]:
  print(k)
else:
  print('-1')

# if up>1 and down>1:
#   print('-1')

# elif len(numLi) > 3:
#   if up == 1 and numLi[N-1] > numLi[0]:
#     print(k)
#   elif down == 1 and numLi[N-1] < numLi[0]:
#     print(k)
#   else:
#     print('-1')
    

# if len(numLi) == 3:
#   if numLi[0]

# if len(numLi) > 3:
#   if up == 1 and numLi[N-1] > numLi[0]:
#     print(k)
#   elif down == 1 and numLi[N-1] < numLi[0]:
#     print(k)
#   else:
#     print('-1')
    
      


