#include<stdio.h>
#include<algorithm>
using namespace std;
//ATM

int N;
int iarr[1001];
int cnt = 0;
int ans;

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &iarr[i]);
    }
    sort(iarr, iarr+N);
    for (int i=0; i<N; i++){
        cnt = cnt + iarr[i];
        ans = ans + cnt;
    }
    printf("%d\n", ans);
    return 0;
}