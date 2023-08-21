#include <bits/stdc++.h>
//친구 네트워크

using namespace std;

int n;
int parent[200001];
int rankArr[200001];
map<string, int> fmap;

int find(int x){
    if (parent[x] == x){
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
        return rankArr[x]; 
    }

    if (rankArr[x] > rankArr[y]) {
        parent[y] = x;
        rankArr[x] += rankArr[y];
        return rankArr[x];
    }
    else {
        parent[x] = y;
        rankArr[y] += rankArr[x];
        return rankArr[y];
    }

    // return;
}

int main(){
    scanf("%d", &n);

    for (int i=0, F, ans, fvar; i<n; i++){
        scanf("%d", &F);
        // parent = new int[2*F+1];
        // rankArr = new int[2*F+1];

        for (int j=0; j<200001; j++){
            parent[j] = j;
            rankArr[j] = 1;
        }
        
        fmap.clear();
        for (int j=0; j<F; j++){
        
            // char ktmp[100];
            // char ltmp[100];
            string k, l;
            // scanf("%s %s", ktmp, ltmp);
            // k = ktmp;
            // l = ltmp;
            cin >> k >> l;
            
            if (fmap.count(k) == 0){
                fmap.insert(make_pair(k, fvar++));
            }
            if (fmap.count(l) == 0){
                fmap.insert(make_pair(l, fvar++));
            }
            ans = unionFunc(fmap[k], fmap[l]);
            printf("%d\n", ans);
        }
    }
    return 0;
}