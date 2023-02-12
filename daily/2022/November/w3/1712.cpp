#include <bits/stdc++.h>

//손익분기점
int A, B, C;
int BEP;
int n = -1;

int main(){
    scanf("%d %d %d", &A, &B, &C);
    if (C - B > 0){
        n = floor(A / (C - B) + 1);
    }
    printf("%d\n", n);
    return 0;
}