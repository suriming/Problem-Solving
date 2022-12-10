#include<stdio.h>
//분수 찾기

using namespace std;

int X;

int main(){
    scanf("%d", &X);
    int i = 0;
    while (true){
        if ((X - i) <= 0){
            break;
        }
        X -= i;
        i += 1;
    }
    if (i % 2){
        printf("%d/%d\n", (i-X+1), X);
    }
    else{
        printf("%d/%d\n", X, (i-X+1));
    }
    return 0;
}