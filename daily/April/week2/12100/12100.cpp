#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int N;
int darr[21][21];
int ans = 0;

void up(int (&arr)[21][21]){
    // 컬럼 기준 i 
    for (int i = 0; i < N; i++){
        // 로우 기준 j
        queue<int> tq;
        for (int j = 0; j < N; j++){
            if (arr[j][i]) tq.push(arr[j][i]);
        }
        for (int j = 0; j < N; j++){
            if (!tq.empty()) {
                int cur = tq.front(); tq.pop();
                if (!tq.empty() && tq.front() == cur){
                    cur *= 2;
                    tq.pop();
                }   
                arr[j][i] = cur; 
            }
            else arr[j][i] = 0;
        }
    }
}

void down(int (&arr)[21][21]){
    // 컬럼 기준 i 
    for (int i = 0; i < N; i++){
        // 로우 기준 j
        queue<int> tq;
        for (int j = N-1; j >= 0; j--){
            if (arr[j][i]) tq.push(arr[j][i]);
        }
        for (int j = N-1; j >= 0; j--){
            if (!tq.empty()) {
                int cur = tq.front(); tq.pop();
                if (!tq.empty() && tq.front() == cur){
                    cur *= 2;
                    tq.pop();
                }   
                arr[j][i] = cur; 
            }
            else arr[j][i] = 0;
        }
    }
}

void left(int (&arr)[21][21]) {
    // 로우 기준 i 
    for (int i = 0; i < N; i++) {
        queue<int> tq;
        for (int j = 0; j < N; j++) {
            if (arr[i][j]) tq.push(arr[i][j]);
        }
        for (int j = 0; j < N; j++) {
            if (!tq.empty()){
                int cur = tq.front(); tq.pop();
                if (!tq.empty() && tq.front() == cur){
                    cur *= 2;
                    tq.pop();
                }
                arr[i][j] = cur;
            }
            else arr[i][j] = 0;
        }
    }
}

void right(int (&arr)[21][21]) {
    // 로우 기준 i 
    for (int i = 0; i < N; i++) {
        queue<int> tq;
        for (int j = N-1; j >= 0; j--) {
            if (arr[i][j]) tq.push(arr[i][j]);
        }
        for (int j = N-1; j >= 0; j--) {
            if (!tq.empty()){
                int cur = tq.front(); tq.pop();
                if (!tq.empty() && tq.front() == cur){
                    cur *= 2;
                    tq.pop();
                }
                arr[i][j] = cur;
            }
            else arr[i][j] = 0;
        }
    }
}

void bt(int x, int (&darr)[21][21]){
    if (x == 6) {
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++){
                ans = max(ans, darr[i][j]);
            }
        }
        return;
    }
    for (int i = 0; i < 4; i++){
        int cdarr[21][21];
        // copy(&darr[0][0], &darr[0][0]+21*21, &cdarr[0][0]);
        memcpy(&cdarr, &darr, sizeof(darr));
        if (i == 0) up(cdarr);
        else if (i == 1) left(cdarr);
        else if (i == 2) down(cdarr);
        else if (i == 3) right(cdarr);
        bt(x+1, cdarr);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) cin >> darr[i][j];

    bt(1, darr);
    cout << ans;
    return 0;
}