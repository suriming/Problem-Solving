#include <iostream>
using namespace std;
// 이진수 표현

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC;
    cin >> TC;
    for (int i = 1; i <= TC; ++i){
        int N, M;
        cin >> N >> M;
        bool ans = true;
        for (int j = 0; j < N; j++){
            if (!(M & (1 << j))) {
                ans = false;
                break;
            }
        }
        if (ans) cout << "#" << i << " ON\n";
        else cout << "#" << i << " OFF\n";
    }
    return 0;
}