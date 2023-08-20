#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int pop[12];
int totpop = 0;
vector<int> v[12];

int darr[12];

int ans = 0x3f3f3f3f;
int vis[12] = {0, };

int bfs(int x, int wh){
    int cnt = 0;
    queue<int> q;
    q.push(x);
    vis[x] = 1;
    cnt += pop[x];
    while(!q.empty()){
        int cur = q.front(); q.pop();
        for (int dx = 0; dx < v[cur].size(); dx++){
            int nx = v[cur][dx];
            if (!vis[nx] && darr[nx] == wh){
                cnt += pop[nx];
                vis[nx] = 1;
                q.push(nx);
            }
        }
    }
    return cnt;
}

void sol(){
    for (int i = 0; i < (1 << N); ++i){
        queue<int> q0;
        queue<int> q1;
        memset(darr, 0, sizeof(darr));
        for (int j = 0; j < N; ++j){
            if (i & (1 << j)){
                darr[j+1] = 0;
                q0.push(j+1);
            }
            else {
                darr[j+1] = 1;
                q1.push(j+1);
            }         
        }
        if (q0.size() && q1.size()) {
            memset(vis, 0, sizeof(vis));
            int pop0 = bfs(q0.front(), 0);
            int pop1 = bfs(q1.front(), 1);
            if (pop0+pop1 == totpop) {
                ans = min(ans, abs(pop0-pop1));
            }
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> pop[i];
        totpop += pop[i];
    }
    for (int i = 1; i <= N; i++){
        int s;
        cin >> s;
        for (int j = 1; j <= s; j++){
            int tmp;
            cin >> tmp;
            v[i].push_back(tmp);
        }
    }
    sol();
    if (ans == 0x3f3f3f3f) ans = -1;
    cout << ans;
}