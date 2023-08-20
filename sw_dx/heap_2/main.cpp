#include<iostream>
#include<queue>
using namespace std;
// 보급로 

#define iipip pair<pair<int, int>, int>
const int INF = 0x3f3f3f3f;

int T;
int N;
int board[101][101];
int dist[101][101];

int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0 ,0};

int dijkstra(){
    priority_queue<iipip, vector<iipip>, greater<iipip> > pq;
    pq.push(make_pair(make_pair(0, 0), 0));
    dist[0][0] = 0;
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int x = cur.first.first;
        int y = cur.first.second;
        int cost = cur.second;
        if (x == N-1 && y == N-1) return cost;
        if (dist[x][y] < cost) continue;
        for (int i = 0; i < 4; ++i){
            int nx = x+dr[i];
            int ny = y+dc[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            int ncost = cost+board[nx][ny];
            if (dist[nx][ny] > ncost){
                dist[nx][ny] = ncost;
                pq.push(make_pair(make_pair(nx, ny), ncost));
            }
        }   
    }
    return dist[N-1][N-1];
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; ++t){
        cin >> N;
        fill(&dist[0][0], &dist[100][101], INF);
        for (int i = 0; i < N; ++i){
            string s;
            cin >> s;
            for (int j = 0; j < N; ++j){
                board[i][j] = s[j]-'0';
            }
        }
        cout << "#" << t << " " << dijkstra() << "\n";
    }
    return 0;
}