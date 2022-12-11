#include<stdio.h>
#include<string>
//스택

using namespace std;

int N;
int stack[10001];
int scnt = 0;

void pushX(int x){
    stack[scnt] = x;
    scnt ++;
}

void top(){
    if (!scnt){
        printf("%d\n", -1);
    }
    else{
        printf("%d\n", stack[scnt-1]);
    }
}

void size(){
    printf("%d\n", scnt);
}

void empty(){
    if (!scnt){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 0);
    }
}

void pop(){
    if (!scnt){
        printf("%d\n", -1);
    }
    else{
        scnt --;
        printf("%d\n", stack[scnt]);
    }
}

int main(){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        char c[10];
        scanf("%s", &c);
        string s(c);
        // printf(" %s", c);
        // printf("%s\n", s.c_str());
        if (s == "push"){
            int pnum;
            scanf("%d", &pnum);
            pushX(pnum);
            // string tmp = s.substr(5, 6);
            // printf("%s", s.c_str());
            // printf("%s", tmp.c_str());
        }
        else if (s == "top"){
            top();
        }
        else if (s == "size"){
            size();
        }
        
        else if (s == "empty"){
            empty();
        }

        else if (s == "pop"){
            pop();
        }
    }
    return 0;
}