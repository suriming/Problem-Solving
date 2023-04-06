#include<stdio.h>
//신나는 함수 실행
using namespace std;

int wdp[21][21][21];
int ans;

int w(int a, int b, int c){
    // wdp[0] = 1;
    if (a <=0 or b<=0 or c<=0){
        return 1;
    }
    if (a>20 or b>20 or c>20){
        return w(20, 20, 20);
    }
    if (wdp[a][b][c]){
        return wdp[a][b][c];
    }
    else if (a<b and b<c){
        wdp[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    }
    else{
        wdp[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
    }

    return wdp[a][b][c];
}

int main(){

    while (true){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if ((a == -1) & (b == -1) & (c == -1)){
            break;
        }

        ans = w(a, b, c);

        printf("w(%d, %d, %d) = %d\n", a, b, c, ans);
    }
    return 0;
}