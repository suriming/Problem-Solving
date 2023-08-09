#include <iostream>
using namespace std;
// 사칙연산 유효성 검사

int T = 10;
int N;
int lc[201], rc[201];
char carr[201];
int ans = 1;

void inorder(int cur){
    if (lc[cur] != -1) {
        if (carr[cur] != '+' && carr[cur] != '-' && carr[cur] != '*' && carr[cur] != '/') ans = 0;
        inorder(lc[cur]);
    }
    else if (lc[cur] == -1){
        if (carr[cur] == '+' || carr[cur] == '-' || carr[cur] == '*' || carr[cur] == '/') ans = 0;
    }
    if (rc[cur] != -1) inorder(rc[cur]);
    else if (rc[cur] == -1){
        if (lc[cur] != -1) ans = 0;
    }
}

int main(){
    for (int t = 1; t <= T; ++t){
        cin >> N;
        fill(lc, lc+201, -1);
        fill(rc, rc+201, -1);
        fill(carr, carr+201, 0);
        ans = 1;
        for (int i = 1; i <= N; ++i){
            int n, l, r;
            char c;
            if (i <= N/2){
                cin >> n >> c >> l >> r;
                lc[n] = l;
                rc[n] = r;
            }
            else if (i == N/2 && N%2 == 0){
                cin >> n >> c >> l;
                lc[n] = l;
            }
            else cin >> n >> c;
            carr[n] = c;
        }
        // for (int i = 1; i <= N; ++i){
        //         cout << carr[i] << ' ';
        // }
        // cout << '\n';
        inorder(1);
        cout << "#" << t << " " << ans << '\n';
    }
    return 0;
}