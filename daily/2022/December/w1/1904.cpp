#include<stdio.h>
//01타일
using namespace std;

int N;
int dp[1000001];

int main(){
    scanf("%d", &N);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    dp[4] = 5;
    for (int i=3; i<=N; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 15746;
    }
    printf("%d\n", dp[N]);
    return 0;
}