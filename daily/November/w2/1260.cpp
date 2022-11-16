#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <deque>

using namespace std;

int N, M, V;
int visarr[1001] = {0,}; 
vector<int> adjvec[1001]; 
deque<int> visstk; //dfs
queue<int> visque; //bfs

void dfs_recur(int x){
    if (visarr[x]){
        return;
    }
    visarr[x] = 1;
    printf("%d ", x);
    for (int i=0; i<adjvec[x].size(); i++){
        dfs_recur(adjvec[x][i]);
    }
}

void bfs(int x){
    visque.push(x);
    while(!visque.empty()){
        int cur = visque.front();
        visque.pop();

        if (visarr[cur]){
            continue;
        }

        visarr[cur] = 1;
        printf("%d ", cur);

        for (int i=0; i<adjvec[cur].size(); i++){
            visque.push(adjvec[cur][i]);
        }
    }
}

void dfs_stack(int x){
    visstk.push_back(x);
    while(!visstk.empty()){
        int cur = visstk.back();
        visstk.pop_back();

        if (visarr[cur]){
            continue;
        }

        visarr[cur] = 1;
        printf("%d ", cur);

        for (int i=adjvec[cur].size()-1; i>=0; i--){
            visstk.push_back(adjvec[cur][i]);
        }
    }
}

int main(){
    scanf("%d %d %d", &N, &M, &V);
    for (int i=0, j, k; i<M; i++){
        scanf("%d %d", &j, &k);
        
        //인접 리스트 방식
        adjvec[j].push_back(k);
        adjvec[k].push_back(j);
    }

    for (int i=0; i<N+1; i++){
        sort(adjvec[i].begin(), adjvec[i].end());
    }

    fill_n(visarr, 1001, 0);
    dfs_recur(V);
    fill_n(visarr, 1001, 0);
    printf("\n");
    bfs(V);

    return 0;
}