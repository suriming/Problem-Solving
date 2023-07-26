#include <iostream>
using namespace std;
// 최장 공통 부분 수열

int T;
int dp[1001][1001];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int i = 1; i <= T; i++){
        string a, b;
        cin >> a >> b;
        fill(&dp[0][0], &dp[1000][1001], 0);
        for (int j = 1; j <= a.length(); j++){
            for (int k = 1; k <= b.length(); k++){
                if (a[j-1] == b[k-1]) dp[j][k] = dp[j-1][k-1] + 1;
                else dp[j][k] = max(dp[j-1][k], dp[j][k-1]);
            }
        }
        cout << "#" << i << " " << dp[a.length()][b.length()] << "\n";
    }
    return 0;
}