#include<stdio.h>
//알고리즘 수업-피보나치 수 1

using namespace std;

int n;
int ans1;
int ans2;
int dp[40] = {0, };

int fib(int x){
    if (x ==1 or x ==2){
        ans1 += 1;
        return 1;
    }
    else {
        return fib(x-1) + fib(x-2);
    }
}

int fibonacci(int x){
    dp[1] = 1;
    dp[2] = 1;
    for (int i=3; i<x+1; i++){
        ans2 += 1;
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[x];
}

int main(){
    scanf("%d", &n);

    int tmp1 = fib(n);

    int tmp2 = fibonacci(n);
    printf("%d %d\n", ans1, ans2);
    return 0;
}