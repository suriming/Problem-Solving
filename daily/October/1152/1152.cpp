#include <iostream>
#include <sstream>
using namespace std;
// 단어의 개수

string s;
int ans = 0;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin, s);
    istringstream iss(s);
    string buff;
    while (getline(iss, buff, ' ')){
        if (ans == 0 && buff.length() == 0) continue; 
        // cout << buff.length() << '\n';
        ans ++;
    }
    cout << ans;
}