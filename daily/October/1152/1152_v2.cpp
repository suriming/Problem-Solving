#include <iostream>
using namespace std;
// 단어의 개수

string s;
int ans = 1;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin, s);
    for (int i = 0; i < s.length(); ++i){
        if (s[i] == ' ') ans ++;
    }
    if (s[0] == ' ') ans --;
    if (s[s.length()-1] == ' ') ans--;
    cout << ans;
}