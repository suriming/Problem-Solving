#include<bits/stdc++.h>
//블랙잭

int N, M;
int cards[100];
int ans = 0;

int main(){
    scanf("%d %d", &N, &M);
    for (int i=0, j; i<N; i++){
        scanf("%d", &j);
        cards[i] = j;
    }
    for (int i=0; i<N; i++){
        for (int j=i+1; j<N; j++){
            for (int k=j+1; k<N; k++){
                int sum = cards[i] + cards[j] + cards[k];
                if (sum>ans && sum<=M){
                    ans = sum;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
