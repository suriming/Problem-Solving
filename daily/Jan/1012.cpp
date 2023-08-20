#include<stdio.h>
#include<string.h>
using namespace std;
//유기농 배추

int T, M, N, K;
int darr[50][50] = {0, };
int vdarr[50][50] = {0, };
int dc[4] = {1, 0, -1, 0};
int dr[4] = {0, -1, 0, 1};
int ans;

void dfs(int r, int c){
    // printf("%d %d\n", r, c);
    if (vdarr[r][c]){
        return;
    }
    vdarr[r][c] = 1;
    for (int l=0; l<4; l++){
        int nr = r + dr[l];
        int nc = c + dc[l];
        if (nr>=0 and nr<N and nc>=0 and nc<M){
            if (darr[nr][nc]){
                dfs(nr, nc);
            }
        }
    }
}

int main(){
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        ans = 0;
        memset(vdarr, 0, sizeof(vdarr));
        memset(darr, 0, sizeof(darr));
        scanf("%d %d %d", &M, &N, &K);
        for (int j=0, k, l; j<K; j++){
            scanf("%d %d", &k, &l);
            darr[l][k] = 1;
        }
        for (int j=0; j<N; j++){
            for (int k=0; k<M; k++){
                // printf("%d %d\n", vdarr[3][2], darr[3][2]);
                // printf("%d %d\n", vdarr[4][0], darr[4][0]);
                if ((!vdarr[j][k]) and (darr[j][k])){
                    ans += 1;
                    dfs(j, k);
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}