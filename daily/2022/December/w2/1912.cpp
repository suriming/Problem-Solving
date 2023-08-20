#include<stdio.h>
#include<algorithm>
#include<math.h>
//연속합

using namespace std;

const int mINF = 0xc0c0c0c0;

int n;
int sarr[100001]; //i번째에서 끝나는 제일 큰 연속합
int ans = mINF;

int main(){
    scanf("%d", &n);
    scanf("%d", &sarr[0]);
    int ans = sarr[0];
    for (int i=1, j; i<n; i++){
        scanf("%d", &j);
        sarr[i] = max(sarr[i-1] + j, j);
        ans = max(ans, sarr[i]);
    }
    printf("%d\n", ans);
    return 0;
}