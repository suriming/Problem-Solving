import sys
T = int(sys.stdin.readline())

for _ in range (T): 
    n, k, t, m = map(int, sys.stdin.readline().split())
    scoreLi = [0]*(n+1)
    numLi = [0]*(n+1)
    logLi = [0]*(n+1)
    probBoard = [[0 for _ in range(k+1)] for _ in range(n+1)]
    ourRank = 1

    for data in range(m):
        i, j, s = map(int, sys.stdin.readline().split())
        if probBoard[i][j] == 0 : 
            scoreLi[i] = scoreLi[i]+s
            probBoard[i][j] = s
        elif probBoard[i][j] < s: 
            scoreLi[i] = scoreLi[i]+(s-probBoard[i][j])
            probBoard[i][j] = s
        numLi[i] += 1 
        logLi[i] = data
    for i in range (1, n+1):
        if scoreLi[i] > scoreLi[t]:
            ourRank += 1
        elif scoreLi[i] == scoreLi[t]:
            if numLi[i] < numLi[t]:
                ourRank += 1
            elif numLi[i] == numLi[t] and logLi[i] < logLi[t]:
                ourRank += 1
    print(ourRank)
