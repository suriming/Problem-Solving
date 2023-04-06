#include <bits/stdc++.h>

using namespace std;

int N;
int narr[1000] = {0,};

void insertion_sort(){
    int tmp;
    for (int i=0; i<N-1; i++){
        for (int j=i+1; j>0; j--){
            if (narr[j-1] > narr[j]){
                tmp = narr[j-1];
                narr[j-1] = narr[j];
                narr[j] = tmp;
            }
        }
    }
}

int main(){
    scanf("%d", &N);
    for (int i=0, j; i<N; i++){
        scanf("%d", &j);
        narr[i] = j;
    }
    insertion_sort();
    for (int i=0; i<N; i++){
        printf("%d\n", narr[i]);
    }
}