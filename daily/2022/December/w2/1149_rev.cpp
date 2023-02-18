#include <iostream>
#include<algorithm>
using namespace std;
//RGB거리

int r[1001], g[1001], b[1001];
int dp[1001][3]; // i 번째 집까지 칠할 때 비용의 최솟값, 2차원은 빨강, 

int N;
int ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) cin >> r[i] >> g[i] >> b[i];
    dp[1][0] = r[1];
    dp[1][1] = g[1];
    dp[1][2] = b[1];
    for (int i = 2; i <= N; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + r[i];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + g[i];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + b[i];
    }
    // min({}) 이렇게 하거나
    cout << *min_element(dp[N], dp[N] + 3);
}