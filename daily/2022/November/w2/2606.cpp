#include <bits/stdc++.h>
//바이러스

using namespace std;

int N, M;
int visarr[101];
vector<int> visvec[101];
int ans = -1;

void dfs(int x){
    visarr[x] = 1;
    ans ++;

    for (int i=0; i<visvec[x].size(); i++){
        if (!visarr[visvec[x][i]]){
            dfs(visvec[x][i]);
        }
    }
}

int main(){
    scanf("%d", &N);
    scanf("%d", &M);
    for (int i=0, j, k; i<M; i++){
        scanf("%d %d", &j, &k);
        visvec[j].push_back(k);
        visvec[k].push_back(j);
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}