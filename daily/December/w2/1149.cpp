#include<stdio.h>
#include<algorithm>
using namespace std;
//RGB거리

int N;

int arr[1001][3];
int dp[1001][3];

int ans;

int minval(int r, int g, int b){
    if (min(r, g) == r && min(r, b) == r){
        return r;
    }
    else if (min(r, g) == g && min(g, b) == g){
        return g;
    }
    else{
        return b;
    }
}

int main(){
    scanf("%d", &N);
    for (int i=1; i<=N; i++){
        for (int j=0; j<3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    for (int i=1; i<=N; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2];
    }
    printf("%d\n", minval(dp[N][0], dp[N][1], dp[N][2]));
    return 0;
}