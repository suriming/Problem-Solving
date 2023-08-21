#include<bits/stdc++.h>
//베르트랑 공준

using namespace std;

int n;
int* parr;
int ans = 0;

void eratos(int x){
    if (x <= 1) {
        ans = 1;
        return;
    }
    fill_n(parr, 2*x+1, 1);
    // for (int i=2, j; i<2*x+1; i++){
    //     if (parr[i]){
    //         j = i;
    //         while(i*j < 2*x+1){
    //             parr[i*j] = 0;
    //             j ++;
    //         }
    //     }
    // }
    for (int i=2; i*i < 2*x+1; i++){
        if (parr[i]){
            for (int j=i*i; j < 2*x+1; j+=i){
                parr[j] = 0;
            }
        }
    }
}

int main(){
    while (true){
        ans = 0;
        scanf("%d", &n);
        if (n == 0){
            break;
        }
        parr = new int[2*n+1];
        eratos(n);
        for (int i=n+1; i<2*n+1; i++){
            if (parr[i]){
                ans ++;
            }
        }
        printf("%d\n", ans);

    }
    return 0;
}


