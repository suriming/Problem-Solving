#include <bits/stdc++.h>
//여행가자
int N, M;

int *parent;
int *plan;
int *rank;

int find(int x){
    // 부모노드가 자기자신이라면, 즉 자기가 루트노드라면
    if (x == parent[x]){
        //그대로 return
        return x;
    }
    else {
        int y = find(parent[x]);
        parent[x] = y; //x의 부모를 바로 루트노드로 바꿔줌
        return y;
    }
}

//두 노드가 각 포함되어 있는 집합을 함침 , y의 집합을 x에 집합에 합치는 걸로
//즉 y의 parent가 x 
void unionFunc(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y){
        return;
    }
    
    //트리의 높이가 낮은 트리가 높은 트리 밑으로
    if (rank[x] > rank[y]) {
        parent[y] = x;
        rank[x] += rank[y];
    }
    else {
        parent[x] = y;
        rank[y] += rank[x];
    }
}

int main(){
    scanf("%d", &N);
    scanf("%d", &M);
    parent = new int[N];
    plan = new int[M];
    rank = new int[N];
    for (int i=0; i<N; i++){
        parent[i] = i;
        rank[i] = 1;
    }
    
    int isLinked;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            scanf("%d", &isLinked);
            if (isLinked ==1){
                unionFunc(i, j);
            }
        }
    }
    
    
    int planNum;
    bool ans = true;
    scanf("%d", &planNum);
    int init = find(planNum - 1);

    for (int i=1; i<M; i++){
        scanf("%d", &planNum);
        if (find(planNum - 1) != init) {
            ans = false;
            break;
        }
    }

    if (ans){
        printf("YES");
    }
    else {
        printf("NO");
    }
    
    return 0;
}