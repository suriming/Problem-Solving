#include <bits/stdc++.h>
//사이클 게임
int n, m;
int *parent;
int *rank;

int find(int x){
    if(x == parent[x]){
        return x;
    }
    else {
        int y = find(parent[x]);
        parent[x] = y;
        return y;
    }
}

int unionFunc(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y){
        return 1;
    }

    if (rank[x] > rank[y]) {
        parent[y] = x;
        rank[x] += rank[y];
    }
    else {
        parent[x] = y;
        rank[y] += rank[x];
    }

    return 0;
}
int main(){
    int ans = 0;
    scanf("%d %d", &n, &m);
    parent = new int[n];
    rank = new int[n];
    for (int i=0; i<n; i++){
        parent[i] = i;
    }

    for (int i=0, j, k; i<m; i++){
        scanf("%d %d", &j, &k);
        if (unionFunc(j, k)){
            ans = i+1;
            break;
        }
    }

    printf("%d", ans);
    return 0;
}