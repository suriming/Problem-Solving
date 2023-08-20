#include<stdio.h>
//구간 합 구하기 4
int N, M;
int arr[100001];

int main(){
    scanf("%d %d", &N, &M);
    scanf("%d", &arr[1]);
    for (int i=2, j; i<=N; i++){
        scanf("%d", &j);
        arr[i] = arr[i-1] + j;
    }
    for (int k=0, i, j; k<M; k++){
        scanf("%d %d", &i, &j);
        printf("%d\n", arr[j] - arr[i-1]);
    }
    return 0;
}