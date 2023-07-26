#include <iostream>
using namespace std;
//중위순회

int N;
int T = 10;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int t = 1; t <= T; t++){
        cin >> N;
        for (int i = 1; i <= N; i++){
            char c;
            int a, b;
            cin >> c;
            if (c >= '0' && c <= '9'){
                cin >> a;
                if (i*2 <= N) cin >> b;
            }
        }
    }
    return 0;
}