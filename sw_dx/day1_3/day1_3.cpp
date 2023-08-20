#include <iostream>
using namespace std;
// 동아리실 관리하기 

#define ll long long

int T;
string s;
int mod = 1000000007;
int arr[10002][17];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; t++){
        fill(arr[0], arr[10001], 0);
        cin >> s;
        int ans = 0;
        for (int i = 1; i <= s.size(); i++){
            int cur = 1 << (s[i-1]-'A'); // A:1, B:2, C:4, D:8
            // cout << cur << '\n';
            if (i == 1){
                for (int j = 1; j <= 16; ++j){
                    if((j & cur) && (j & 1)) arr[i][j] = 1;
                }
            }
            else {
                for (int j = 1; j <= 16; ++j){
                    if (j & cur){
                        for (int k = 1; k <= 16; ++k){
                            if (j & k) {
                                arr[i][j] += arr[i-1][k];
                                arr[i][j] %= mod;
                            }
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= 16; ++i){
            // cout << arr[1][i] << " ";
            // cout << s.size() << " ";
            ans += arr[s.size()][i];
            ans %= mod;
        }
        cout << "#" << t << " " << ans << "\n";
    }
    return 0;
}