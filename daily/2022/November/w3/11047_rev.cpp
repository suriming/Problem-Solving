#include <iostream>
#include <algorithm>
using namespace std;
//동전 0

int N, K;
int ans = 0;
int arr[10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin.tie(0);
    cin >> N >> K;
    for (int i=0; i<N; i++) cin >> arr[i];
    for (int i=N-1; i>=0; i--){
        // 생각하지 못했던 포인트
        // 어차피 안되는 건 여기서 0처리므로 따로 신경 쓸 필요 없다.
        ans += K / arr[i]; 
        K %= arr[i]; // 나머지를 변수에 대입.
        //위 두 line의 조합에 주목
    }
    cout << ans;
}