#include<stdio.h>
#include<vector>

//덩치
using namespace std;

int N;
vector< pair<int, int> > v;

int main(){
    scanf("%d", &N);
    for (int i=0, x, y; i<N; i++){
        scanf("%d %d", &x, &y);
        v.push_back(make_pair(x, y));
    }
    for (int i=0, x, y; i<N; i++){
        x = v[i].first;
        y = v[i].second;
        int cnt = 0;
        for (int j=0, z, w; j<N; j++){
            z = v[j].first;
            w = v[j].second;
            if (x < z and y < w){
                cnt ++;
            }
        }
        printf("%d ", cnt+1);
    }
}