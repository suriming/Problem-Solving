#include <iostream>
using namespace std;
// 새로운 불면증 치료법

int T, N;
int arr[10];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int x = 1; x <=T; x++){
        fill(arr, arr+10, 0);
        int cnt = 0;
        cin >> N;
        int p = 0;
        while(cnt < 10){
            int xN = p*N;
            p += 1;
            while(xN >= 1){
                if (arr[xN%10] == 0){
                    arr[xN%10] += 1;
                    cnt += 1;
                }
                xN /= 10;
            }
        }
        cout << "#" << x << " " << (p-1)*N << "\n";
    }
    return 0;
}