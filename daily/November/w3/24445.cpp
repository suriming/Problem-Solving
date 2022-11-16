#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
//알고리즘 수업 - 너비 우선 탐색

using namespace std;

int N, M, R;
int varr[100001] = {0, };
vector<int> vvec[100001];
queue<int> vque;
int cnt = 1;

bool desc(int x, int y){
    return x > y;
}

void bfs(int x){
    varr[x] = cnt;
    vque.push(x);
    while(!vque.empty()){
        int cur = vque.front();
        vque.pop();
        for (int i=0; i<vvec[cur].size(); i++){
            int node = vvec[cur][i];
            if (!varr[node]){
                cnt += 1;
                varr[node] = cnt;
                vque.push(node);
            }
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
        sort(vvec[i].begin(), vvec[i].end(), desc);
    }
    bfs(R);
    for (int i=1; i<N+1; i++){
        printf("%d\n", varr[i]);
    }
    return 0;
}