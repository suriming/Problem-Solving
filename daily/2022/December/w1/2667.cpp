#include<stdio.h>
#include<vector>
#include<algorithm>
//단지번호붙이기
using namespace std;

int N;
int totalH;
int ans;
vector <int> ansvec;
int board[26][26];
int varr[26][26];
vector <int> vvec[26];
int cnt;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void dfs(int x, int y){
    if (varr[x][y]){
        return;
    }

    varr[x][y] = 1;
    cnt ++;

    for (int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx>=0 and nx<N and ny>=0 and ny<N){
            if(board[nx][ny]){
                dfs(nx, ny);
            }
        }
    }

}

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        for (int j=0, k; j<N; j++){
            scanf("%1d", &k);
            board[i][j] = k;
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if(!varr[i][j] and board[i][j]){
                cnt = 0;
                dfs(i, j);
                if (cnt){
                    ansvec.push_back(cnt);
                }
            }
        }
    }
    sort(ansvec.begin(), ansvec.end());
    int anslen = ansvec.size();
    printf("%d\n", anslen);
    for (int i=0; i<anslen; i++){
        printf("%d\n", ansvec[i]);
    }

    return 0;
}