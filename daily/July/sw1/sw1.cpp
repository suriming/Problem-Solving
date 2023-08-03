#include <iostream>
using namespace std;
//민석이의 마니또
int T, N, M;
const int INF = 0x3f3f3f3f; 
int darr[401][401];
int nxt[401][401];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for(int tc = 1; tc <= T; tc++){
        cin >> N >> M;
        for (int i = 1; i <= N; i++){
            fill(darr[i], darr[i]+N+1, INF);
        }
        while (M--){
            int X, Y, C;
            cin >> X >> Y >> C;
            darr[X][Y] = min(darr[X][Y], C);
            nxt[X][Y] = Y;
        }
        for (int k = 1; k <= N; k++){
            for (int i = 1; i <= N; i++){
                for (int j = 1; j <= N; j++){
                    if (darr[i][k] + darr[k][j] < darr[i][j]){
                        darr[i][j] = min(darr[i][j], darr[i][k]+darr[k][j]);
                        nxt[i][j] = nxt[i][k];
                    }
                }
            }
        }
        int ans = INF;
        for (int i = 1; i <= N; i++){
            if (darr[i][i] < INF){
                ans = min(ans, darr[i][i]);
            }
        }
        if (ans == INF) cout << "#" << tc << " " << -1 << '\n';
        else cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}