#include<bits/stdc++.h>
//알고리즘 수업-깊이 우선 탑색 2
using namespace std;

int N, M, R; 
vector<int> advec[100001];
int varr[100001];
int cnt = 1;

bool desc(int a, int b){
    return a > b;
}

void dfs(int x){
    varr[x] = cnt;
    cnt ++;
    for (int i=0; i<advec[x].size(); i++){
        if (!varr[advec[x][i]]){
            dfs(advec[x][i]);
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &R);
    for (int i=0, j, k; i<M; i++){
        scanf("%d %d", &j, &k);
        advec[j].push_back(k);
        advec[k].push_back(j);
    }
    for (int i=1; i<N+1; i++){
        sort(advec[i].begin(), advec[i].end(), desc);
    }
    
    dfs(R);

    for (int i=1; i<N+1; i++){
        printf("%d\n", varr[i]);
    }
    
    return 0;
}