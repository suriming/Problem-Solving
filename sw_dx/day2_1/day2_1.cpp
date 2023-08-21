#include <iostream>
#include <list>
using namespace std;
//암호문 3

int TC = 10;
int N, M;
list<int> il;
list<int>::iterator cursor;

void i_func(){
    int x, y, s;
    cin >> x;
    for (int i = 0; i < x; ++i) cursor++;
    cin >> y;
    for (int i = 0; i < y; ++i){
        cin >> s;
        il.insert(cursor, s);
    }
}

void d_func(){
    int x, y;
    cin >> x >> y;
    for (int i = 0; i < x; ++i) cursor++;
    for (int i = 0; i < y; ++i) cursor = il.erase(cursor);
}
 
void a_func(){
    int y, s;
    cin >> y;
    for (int i = 0; i < y; ++i){
        cin >> s;
        il.push_back(s);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (int i = 1; i <= TC; ++i){
        cin >> N;
        il.clear(); 
        for (int j = 1; j <= N; ++j) {
            int s;
            cin >> s;
            il.push_back(s);
        }
        cin >> M;
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
            if (c == 'A'){
                a_func();
            }
        }
        cout << "#" << i << " ";
        cursor = il.begin();
        for (int j = 0; j < 10; ++j){
            cout << *cursor << " ";
            cursor++;
        }
        cout << "\n";
    }
    return 0;
}