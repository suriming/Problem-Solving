#include<stdio.h>
//피보나치 수 5
int n;

int fibo(int x){
    if (x == 0){
        return 0;
    }
    if (x == 1){
        return 1;
    }
    return fibo(x - 2) + fibo(x - 1);
}

int main(){
    scanf("%d", &n);
    printf("%d\n", fibo(n));
}