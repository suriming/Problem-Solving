#include <iostream>
#include <set>
using namespace std;
//부자의 꿈
int TC, N, M, Q;
int mr[200001]; //max value of the row
int mc[200001]; //max value of the column
set<int> pis;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> TC;
    for (int tc = 1; tc <= TC; tc++){
        cin >> N >> M >> Q;
        int ans = 0;
        fill(mr, mr+N+1, 0);
        fill(mc, mc+M+1, 0);
        pis.clear();

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
                    pis.insert(mr[n]);
                }
            }
        }
        for (int q = 0; q < Q; q++){
            int r, c, x;
            cin >> r >> c >> x;
            int prevr = mr[r];
            int prevc = mc[c];
            // if (pis.find(prevc) != pis.end()){
            //     pis.erase(prevc);
            // }
            if (prevr < x){
                mr[r] = x;
                if (pis.find(prevr) != pis.end()){
                pis.erase(prevr);
            }
            }
            if (prevc < x){
                mc[c] = x;
                if (pis.find(prevc) != pis.end()){
                    pis.erase(prevc);
                }
            }
            if (prevr < x && prevc < x){
                pis.insert(x);
            }
            // mc[c] = x;
            // pis.insert(x);
            ans += pis.size();
        }
        cout << "#" << tc << " " << ans << '\n';
    }
    return 0;
}