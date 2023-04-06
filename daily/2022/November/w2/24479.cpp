#include <bits/stdc++.h>
//알고리즘 수업 - 깊이 우선 탐색 1

using namespace std;

int N, M, R;
vector<int> vvec[100001];
int varr[100001] = {0, };
int cnt = 1;

void dfs(int x){
    varr[x] = cnt;
    cnt ++;
    for (int i=0; i<vvec[x].size(); i++){
        if (!varr[vvec[x][i]]){
            dfs(vvec[x][i]);
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &R);
    for (int i=0, j, k; i<M; i++){
        scanf("%d %d", &j, &k);
        vvec[j].push_back(k);
        vvec[k].push_back(j);
    }
    for (int i=1; i<N+1; i++){
        sort(vvec[i].begin(), vvec[i].end());
    }
    dfs(R);
    for (int i=1; i<N+1; i++){
        printf("%d\n", varr[i]);
    }
    return 0;
}