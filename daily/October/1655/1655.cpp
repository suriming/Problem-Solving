#include <iostream>
#include <queue>
#include <vector>
using namespace std;
// 가운데를 말해요

int N;
priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int> > minh;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int t;
    cin >> t;
    maxh.push(t);
    cout << maxh.top() << '\n';
    for (int i = 2; i <= N; ++i){
        cin >> t;
        if (maxh.top() < t){
            minh.push(t);
            if (i%2 == 1){
                int s = minh.top(); minh.pop();
                maxh.push(s);
            }
        }
        else {
            maxh.push(t);
            if (i%2 == 0) {
                int s = maxh.top(); maxh.pop();
                minh.push(s);
            }   
        }
        cout << maxh.top() << '\n';
    }
}