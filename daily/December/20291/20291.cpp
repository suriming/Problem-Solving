#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
// 파일정리

int N;
unordered_map<string, int> simap;
vector<pair<string, int> > vpsi;

void sol(string s) {
    int flag = false;
    string t;
    for (int i = 0; i < s.size(); ++i) {
        if (flag) {
            t = s.substr(i, s.size()-i);
            // cout << t << '\n';
            break;
        }
        if (s[i] == '.') {
            flag = true;
        }
    }
    simap[t] ++;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    string s;
    while (N--) {
        cin >> s;
        sol(s);
    }
    for (auto e : simap) {
        vpsi.push_back(make_pair(e.first, e.second));
    }
    sort(vpsi.begin(), vpsi.end());
    for (auto e: vpsi) {
        cout << e.first << ' ' << e.second << '\n';
    }
}