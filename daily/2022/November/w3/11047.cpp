//동전 0
#include <stdio.h>
#include <algorithm>

int N, K;
int ans = 0;
int carr[10];

using namespace std;

bool desc(int x, int y){
    return x > y;
}

void greedy(int total){
    int sum = 0;
    int left = total;
    for (int i=0; i<N; i++){
        if ((sum + carr[i]) <= total){
            sum += (carr[i] * (left / carr[i]));
            // printf("%d\n", left / carr[i]);
            ans += (left / carr[i]);
            left = total - sum;
            // printf("%d\n", left);
        }
        if (left == 0){
            return;
        }
    }
}

int main(){
    scanf("%d %d", &N, &K);
    for (int i=0, j; i<N; i++){
        scanf("%d", &j);
        carr[i] = j;
    }
    sort(carr, carr + N, desc);
    greedy(K);
    printf("%d\n", ans);
}