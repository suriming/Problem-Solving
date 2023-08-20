#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
//꺾이지 않는 마음 1

int N;
int H[10002];
int D[10002];
int K[10002];
// vector<pair<int, int> > vpi;
int di = 1;
int hi = 1;

// int mh = 0;

int compare(int d, int h){
    if (d>=h){
        return 1;
    }
    else{
        return 0;
    }
}

bool desc(int x, int y){
    return x > y;
}

// bool desc(pair<int, int> &x, pair<int, int> &y){
//     return x.first > y.first;
// }

// bool desc_second(pair<int, int> &x, pair<int, int> &y){
//     return x.second > y.second;
// }

int main(){
    scanf("%d", &N);
    // vpi.push_back(make_pair(0, 0));
    for (int i=1, j, k; i<=N; i++){
        scanf("%d %d", &D[i], &H[i]);
        // scanf("%d %d", &j, &k);
        // vpi.push_back(make_pair(j, k));
        // mh =  max(H[i], mh);
    }
    sort(D+1, D+N+1, desc);
    sort(H+1, H+N+1, desc);
    // sort(vpi.begin()+1, vpi.end()+1, desc_second);
    // sort(vpi.begin()+1, vpi.end()+1, desc);
    // for (int i=1; i<=N; i++){
    //     printf("arr: %d\n", vpi[i].second);
    // }
    // for (int i=1; i<=N; i++){
    //     if (compare(vpi[di].first, vpi[hi].second)){
    //         K[i] = K[i-1] + vpi[di].first;
    //         di ++;
    //     }
    //     else{
    //         K[i] = K[i-1] + vpi[di].second;
    //         hi ++;
    //     }
    // }
    for (int i=1; i<=N; i++){
        if (compare(D[di], H[hi]) and (di < hi)){
            K[i] = K[i-1] + D[di] + D[di-1];
            int tmp = D[di-1] + D[di];
            D[di] = tmp;
            di ++;
        }
        else{
            K[i] = K[i-1] + H[hi] + D[di-1];
            int tmp = D[di-1] + D[di];
            D[di] = tmp;
            di ++;
            hi ++;
        }
    }
    for (int i=1; i<=N; i++){
        printf("%d\n", K[i]);
    }
    return 0;
}