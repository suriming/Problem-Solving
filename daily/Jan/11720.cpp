#include<iostream>
using namespace std;
//숫자의 합

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    char s[101];
    int ans = 0;

    cin >> N;
    cin >> s;

    for (int i=0; i<N; i++){
        // int si = s[i];
        ans += s[i] - '0';
        // ans += si;
    }
    cout << ans << endl;
    return 0;
}