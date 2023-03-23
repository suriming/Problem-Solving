#include <iostream>
#include <cmath>
using namespace std;

int N;
int arr[1000001];
int B, C;

long long ans;

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) cin >> arr[i];
    cin >> B >> C;
    for (int i = 0; i < N; i++) {
        ans += 1;
        if ((arr[i]-B > 0)){
            ans += (arr[i]-B-1)/C + 1;
        }
    }
    cout << ans;
}