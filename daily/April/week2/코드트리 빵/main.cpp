#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; //격자 수
int m; //사람 수 
int darr[16][16];
int lock[16][16];
int t = 1;

int dist[16][16];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

vector<pair<int, int> > vp; // i번째 사람의 타겟 편의점 위치
vector<pair<int, int> > vcur; // i번째 사람의 현재 위치

void bfs(int r, int c){
    queue<pair<int, int> >q;
    q.push(make_pair(r, c));
    dist[r][c] = 1;
    while(!q.empty()){
        auto cur = q.front(); q.pop();
        for (int i = 0; i < 4; i++){
            int nr = cur.first + dr[i];
            int nc = cur.second + dc[i];
            if (nr < 1 || nc < 1 || nr > n || nc > n || darr[nr][nc] == -1) continue;
            if (dist[nr][nc] == 0){
                dist[nr][nc] = dist[cur.first][cur.second] + 1;
                q.push(make_pair(nr, nc));
            }
        }
    }
}

void sol(){
    //1단계
    for (int i = 1; i <= m; i++) {
        if (vcur[i] == make_pair(-1, -1) || vcur[i] == vp[i]) continue;
        auto cur = vcur[i];
        memset(dist, 0, sizeof(dist));
        bfs(vp[i].first, vp[i].second);
        // for (int j = 1; j <= n; j++){
        //     for (int k = 1; k <= n ; k++){
        //         cout << dist[j][k] << ' ';
        //     }
        //     cout << '\n';
        // }
        int mdist = 0x3f3f3f3f;
        int mx = 0, my = 0;
        for (int k = 0; k < 4; k++){
            int nr = cur.first + dr[k];
            int nc = cur.second + dc[k];
            if (nr < 1 || nc < 1 || nr > n || nc > n || darr[nr][nc] == -1) continue;
            if (dist[nr][nc] < mdist && dist[nr][nc] > 0){
                mdist = dist[nr][nc];
                mx = nr; my = nc;
            } 
        }
        vcur[i] = make_pair(mx, my);
        // cout << i << "다음칸" << '\n';
        // cout << mx << ' ' <<my << '\n';
    }

    // 2단계
    for (int i = 1; i <= m; i++){
        auto cur = vcur[i];
        if ((darr[cur.first][cur.second] == 0) && (cur == vp[i])) darr[cur.first][cur.second] = -1;
    }
    
    // 3단계
    if (t > m) return;
    // cout << "엥" << '\n';
    memset(dist, 0, sizeof(dist));
    // cout << vp[t].first << ' ' << vp[t].second << '\n';
    bfs(vp[t].first, vp[t].second);
    int mdist = 0x3f3f3f3f;
    int mx = 0, my = 0;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            // cout << dist[i][j] << ' ';
            if (darr[i][j] == 1 && dist[i][j] < mdist && dist[i][j] > 0){
                mx = i;
                my = j;
                mdist = dist[i][j];
            }
        }
        // cout << '\n';
    }
    vcur[t] = make_pair(mx, my);
    darr[mx][my] = -1;
    // cout << mx << ' ' << my << '\n';
}

int main() {
    // 여기에 코드를 작성해주세요.
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> darr[i][j]; // 1이 베이스캠프 아닌덴 0
    vp.push_back(make_pair(-1, -1));
    for (int i = 1; i <= m; i++){  
        int a, b;
        cin >> a >> b;  
        vp.push_back(make_pair(a, b)); //편의점
    }
    vcur.push_back(make_pair(-1, -1));
    for (int i = 1; i <= m; i++) vcur.push_back(make_pair(-1, -1));
    while (true) {
        // if (t == 6) break;
        sol();
        bool endflag = true;
        for (int i = 1; i <= m; i ++){
            if (vcur[i] != vp[i]) endflag = false;
        }
        if (endflag) break;
        t += 1;
    }
    cout << t;
    return 0;
}