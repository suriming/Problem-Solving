#include<stdio.h>
//파도반 수열

int T;
int N;
long P[101];
int cnt = 6;

int max(int x, int y){
    if (x > y){
        return x;
    }
    else{
        return y;
    }
}

int main(){
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        scanf("%d", &N);
        P[1] = 1;
        P[2] = 1;
        P[3] = 1;
        P[4] = 2;
        P[5] = 2;
        if (P[N]){
            printf("%ld\n", P[N]);
            continue;
        }
        for (int j=cnt; j<=N; j++){
            P[j] = P[j-1] + P[j-5];
        }
        cnt = max(cnt, N);
        printf("%ld\n", P[N]);
    }
    return 0;
}