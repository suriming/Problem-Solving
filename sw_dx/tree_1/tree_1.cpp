#include <iostream>
using namespace std;
//중위순회

int N;
int T = 10;
int lc[101], rc[101];
char carr[101];

void inorder(int cur){
    if (lc[cur] != 0) inorder(lc[cur]);
    cout << carr[cur];
    if (rc[cur] != 0) inorder(rc[cur]);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int t = 1; t <= T; t++){
        cin >> N;
        fill(lc, lc + 101, 0);
        fill(rc, rc + 101, 0);
        fill(carr, carr + 101, 0);
        for (int i = 1; i <= N; i++){
            int n, l, r;
            char c;
            if (i == N / 2 && N % 2 == 0) {
                cin >> n >> c >> l;
                lc[n] = l;
            }
            // if (i >= N / 2 + 1) pass
            else if (i <= N / 2) { 
                cin >> n >> c >> l >> r;
                lc[n] = l;
                rc[n] = r;
            }
            else cin >> n >> c;
            // else if (N % 2 == 1 && i == N / 2 + 1) cin >> l;
            // else cin >> l >> r;

            carr[n] = c;
            // cout << l << " " << r << "\n";
        }
        cout << "#" << t << " ";
        inorder(1);
        // for (int i = 1; i <= N; i++){
        //     cout << carr[i];
        // }
        cout << "\n";
    }
    return 0;
}




