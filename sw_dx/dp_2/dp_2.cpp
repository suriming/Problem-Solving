#include <iostream>
using namespace std;
// 0/1 knapsack

int T;
int dp[101][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; ++t){
        int N, K;
        cin >> N >> K;
        fill(&dp[0][0], &dp[100][1001], 0);
        for (int i = 1; i <= N; ++i){
            int Vi, Ci;
            cin >> Vi >> Ci;
            for (int j = 1; j <= K; ++j){
                if (Vi > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = max(dp[i-1][j], dp[i-1][j-Vi] + Ci);
            }
        }
        cout << "#" << t << " " << dp[N][K] << "\n";
    }
    return 0;
}