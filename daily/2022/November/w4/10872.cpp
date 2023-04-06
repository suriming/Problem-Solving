#include<stdio.h>
//팩토리얼

int N;
int ans = 1;

// int fac(int x){
//     if (x == 0){
//         return 0;
//     }
//     ans = ans * x;
//     return fac(x-1);
// }

int fac(int x){
    if (x > 1){
        return x * fac(x-1);
    }
    else {
        return 1;
    }
}

int main(){
    scanf("%d", &N);
    printf("%d\n", fac(N));

    return 0;
}