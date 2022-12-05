#include<stdio.h>

using namespace std;

int dpa[20];
int dpb[20];
int dpc[20];

void w(int a, int b, int c){

}

int main(){
    while (true){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        if ((a == -1) & (b == -1) & (c == -1)){
            break;
        }
        w(a, b, c);
    }
    return 0;
}