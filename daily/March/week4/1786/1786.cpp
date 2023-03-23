#include <iostream>
#include <string>
#include <vector>

using namespace std;

string T;
string P;

int cnt;
vector<int> v;

// fail 함수 계산
vector<int> failure(string& s){
    vector<int> f(s.size());
    int j = 0;
    for (int i = 1; i < s.size(); i++){
        while(j > 0 && s[i] != s[j]) j = f[j-1];
        if(s[i] == s[j]) f[i] = ++j;
    }
    return f;
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    getline(cin, T);
    getline(cin, P);

    // cout << T.length() << '\n';
    // cout << P.length() << '\n'; 
    vector<int> f = failure(P);
    int j = 0;
    for (int i = 0; i < T.length(); i++){
        while(j > 0 && T[i] != P[j]) j = f[j-1];
        if (T[i] == P[j]) j++;
        if (j == P.length()){
            cnt ++;
            v.push_back(i-P.length()+2);
        }
    }
    cout << cnt << '\n';
    for (auto& i : v) cout << i << ' ';
}