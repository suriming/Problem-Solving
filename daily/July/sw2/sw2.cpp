#include <iostream>
#include <set>
using namespace std;
//부자의 꿈
int TC, N, M, Q;
int mr[200001]; //max value of the row
int mc[200001]; //max value of the column
set<pair<int, int> > piis;
set<int> pis;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++){
        cin >> N >> M >> Q;
        int ans = 0;
        fill(mr, mr+N+1, 0);
        fill(mc, mc+M+1, 0);
        piis.clear();

        for (int n = 1; n <= N; n++){
            for (int m = 1; m <= M; m++){
                int s;
                cin >> s;
                mr[n] = max(mr[n], s);
                mc[m] = max(mc[m], s);
            }
        }
        for (int n = 1; n <= N; n++){
            for (int m = 1; m <= M; m++){
                if (mr[n] == mc[m]){
                    piis.insert(make_pair(n, m));
                }
            }
        }
        // q update 
        for (int q = 0; q < Q; q++){
            int r, c, x;
            cin >> r >> c >> x;
            int prevr = mr[r]; 
            int prevc = mc[c];
            for (int m = 1; m <= M; m++){
                if (mr[r] == mc[m]){
                    piis.erase(make_pair(r, m));
                }
            }
            for (int n = 1; n <= N; n++){
                if (mr[n] == mc[c]){
                    piis.erase(make_pair(n, c));
                }
            }
            mr[r] = x;
            mc[c] = x;
            for (int n = 1; n <= N; n++){
                for (int m = 1; m <= M; m++){
                    if (mr[n] == mc[m]){
                        piis.insert(make_pair(n, m));
                    }
                }
            }
            ans += piis.size();
        }
        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}