#include <iostream>
using namespace std;
// 힙

#define parent (i >> 1)
#define left (i << 1)
#define right ((i << 1) | 1)


int T;
int heap[100002];
int hsz = 0;

// insert
void op1_func(int x){
    heap[++hsz] = x;
    for (int i = hsz; parent != 0 && heap[parent] < heap[i]; i >>= 1){
        swap(heap[parent], heap[i]);
    }
}

// return max key and delete that
int op2_func(){
    if (hsz == 0) return -1;
    int ret = heap[1];
    heap[1] = heap[hsz--];
    for (size_t i = 1; left <= hsz;){
        if (left == hsz || heap[left] > heap[right]){
            if (heap[i] < heap[left]){
                swap(heap[i], heap[left]);
                i = left;
            }
            else break;
        }
        else {
            if (heap[i] < heap[right]){
                swap(heap[i], heap[right]);
                i = right;
            }
            else break;
        }
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    for (int t = 1; t <= T; ++t){
        int N;
        hsz = 0;
        cin >> N;
        cout << "#" << t << " ";
        for (int i = 0; i < N; ++i){
            int op;
            cin >> op;
            if (op == 1){
                int x;
                cin >> x;
                op1_func(x);
            }
            else if (op == 2){
                cout << op2_func() << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}