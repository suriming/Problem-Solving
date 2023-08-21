#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 프로세서 연결하기

#define F first
#define S second

int T, N;
int board[12][12]; //0부터시작
vector<pair<int, int> > v;

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

int ans = 0x3f3f3f3f; // 전선길이
int cores = 0; // 연결된 코어수

int connect(int r, int c, int dir){ // dir 방향으로 전선 놓아줌
    int len = 0;
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    while (nr >= 0 && nc >= 0 && nr < N && nc < N){
        board[nr][nc] = 2;
        nr += dr[dir];
        nc += dc[dir];
        len++;
    }
    return len;
}

int disconnect(int r, int c, int dir){ // dir 방향으로 전선 끊어줌 (back)
    int len = 0;
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    while (nr >= 0 && nc >= 0 && nr < N && nc < N){
        board[nr][nc] = 0;
        nr += dr[dir];
        nc += dc[dir];
        len++;
    }
    return len;
}


bool bfs_oneway(int r, int c, int dir){
    // dir 방향으로 전선 놓을 수 있는지 체크만 함. 
    // 잘못놓으면 어차피 끊으러 돌아가야 하니 놓진 않음
    int nr = r + dr[dir];
    int nc = c + dc[dir];
    while (nr >= 0 && nc >= 0 && nr < N && nc < N){
        if (board[nr][nc] == 1 || board[nr][nc] == 2) return false;
        nr += dr[dir];
        nc += dc[dir];
    }
    return true;
}

void bt(int cur, int cnt, int len){
    // cur: 확인중인 인덱스, cnt: 연결된 코어수, len: 전선길이
    if (cur == v.size()+1) {
        // cout << "end" << "\n";
        return;
    }
    // 답 업데이트
    if (cnt > cores){
        cores = cnt;
        ans = len;
    }
    else if (cnt == cores){
        ans = min(ans, len);
    }
    // 가지치기
    // 영끌해도 안되는경우
    if (cnt + (v.size()-cur) < cores) return; 

    // 백트래킹
    int r = v[cur].F;
    int c = v[cur].S;
    // 가장자리인 경우 1가지
    if (r == 0 || r == N-1 || c == 0 || c == N-1){
        bt(cur+1, cnt+1, len);
        return; 
    }
    // 가장자리가 아닌 경우 5가지
    // 4가지 
    for (int i = 0; i < 4; ++i){
        if (bfs_oneway(r, c, i)){
            int curlen = connect(r, c, i);
            bt(cur+1, cnt+1, len+curlen);
            disconnect(r, c, i);
        }
    }
    // 1가지 (노연결)
    bt(cur+1, cnt, len);
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int i = 1; i <= T; ++i){
        cin >> N;
        v.clear();
        ans = 0x3f3f3f3f;
        cores = 0;
        for (int j = 0; j < N; ++j){
            for (int k = 0; k < N; ++k){
                board[j][k] = 0;
            }
        }
        for (int j = 0; j < N; ++j){
            for (int k = 0; k < N; ++k){
                cin >> board[j][k];
                if (board[j][k] == 1) v.push_back(make_pair(j, k));
            }
        }
        bt(0, 0, 0);
        cout << "#" << i << " " << ans << "\n";
    }
    return 0;
}

// 가지치기에 길이도 포함되지만 코어수도 포함된다.
// 전선놓을 때 bfs 근데 굳이?
// 아니근데 전체구조는 백트래킹아닌가?
// 연결할수도 있고 안할수도있고
