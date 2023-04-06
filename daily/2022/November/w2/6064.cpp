#include<bits/stdc++.h>
//카잉 달력

int T;
int M, N, x, y;

int gcd(int a, int b){
    //유클리드 호제법
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b){
    return (a * b) / gcd(a, b);
}


int main(){
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        int ans = -1;
        scanf("%d %d %d %d", &M, &N, &x, &y);
        // while (cnt <= lcm(a, b)){
        //     for (int j=x; j<; )
        // }
        
        for (int j=x; j <= lcm(M, N); j += M){
            int ny = j % N;
            if (ny == 0){
                ny = N;
            }
            if (ny == y){
                ans = j;
                break;
            }
        }
        printf("%d\n", ans);
    }
}   