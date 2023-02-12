#include <stdio.h>
//벌집
int N;
int ans = 1;
int sum = 1;

int f(int at, int t){
    return at + t*6;
}

int main(){
    scanf("%d", &N);

    while (sum < N){
        sum = f(sum, ans);
        ans += 1;
    }

    printf("%d\n", ans);
    return 0;
}