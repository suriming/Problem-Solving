#include<stdio.h>
#include<string.h>
using namespace std;
//재귀의 귀재

int T;
int cnt;

int recursion(const char *s, int l, int r){
    cnt++;
    if (l>=r){
        return 1;
    }
    else if (s[l] != s[r]){
        return 0;
    }
    else{
        return recursion(s, l+1, r-1);
    }
}

int isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

int main(){
    scanf("%d", &T);
    for (int i=0; i<T; i++){
        char S[1001];
        cnt = 0;
        scanf("%s", &S);
        int ans = isPalindrome(S);
        printf("%d %d\n", ans, cnt);
    }
    return 0;
}