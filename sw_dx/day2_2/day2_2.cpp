#include <iostream>
#include <list>
using namespace std;
// 수열 편집

list<int> il;   
int T;
int N, M, L;
list<int>::iterator cursor;

void i_func(){
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x-1; ++i) cursor++;
    il.insert(cursor, y);
}

void d_func(){
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i) cursor++;
    il.erase(cursor);
}

void c_func(){
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; ++i) cursor++;
    *cursor = y;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int i = 1; i <=T; ++i){
        cin >> N >> M >> L;
        il.clear();
        cursor = il.begin();
        for (int j = 1; j <= N; ++j){
            int s;
            cin >> s;
            il.push_back(s);
        }
        while(M--){
            cursor = il.begin();
            char c;
            cin >> c;
            if (c == 'I'){
                i_func();
            }
            if (c == 'D'){
                d_func();
            }
            if (c == 'C'){
                c_func();
            }
        }
        cursor = il.begin();
        int ans = -1;
        bool exist = true;
        for (int j = 0; j < L; ++j) {
            if (cursor == il.end()) {
                exist = false;
                break;
            }
            cursor++;
        }
        if (exist) ans = *cursor;
        cout << "#" << i << " " << ans << "\n";
    }
    return 0;
}