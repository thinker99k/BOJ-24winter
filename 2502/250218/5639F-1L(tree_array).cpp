#include <iostream>
#include <vector>

#define START 1
#define DEBUG 0

using namespace std;

vector<int> v;
int tree[10001];

int getLcIdx(int pIdx) {
    return pIdx * 2;
}

int getRcIdx(int pIdx) {
    return pIdx * 2 + 1;
}

void postTraverse(int pIdx) {
    // 현재 방문한 노드에 0이 저장되어있으면(=유효한 범위가 아니면)
    if (!tree[pIdx]) {
        return;
    }
    postTraverse(getLcIdx(pIdx));
    postTraverse(getRcIdx(pIdx));
    
    cout << tree[pIdx] << '\n';
}

void pre2tree() {
    int nodenum = (int) v.size() - 1;
    
    tree[1] = v[1]; // 전위 순회 첫 노드는 무조건 루트
    
    int idx, vi;
    
    for (int i = 2; i <= nodenum; i++) {
        vi = v[i];
        idx = START;
        
        while (true) {
            if (vi < tree[idx]) {
                // 탐색 결과 왼쪽 내려감
                idx = getLcIdx(idx);
            }
            else {
                // 탐색 결과 오른쪽 내려감
                idx = getRcIdx(idx);
            }
            
            if (!tree[idx]) {
                // 저장 가능
                break;
            }
            // 저장 불가능 -> 다시 탐색
        }
        
        tree[idx] = vi;
    }
}

int main() {
    v.push_back(0);

#if DEBUG
    int testcase[9] = {
            50, 30, 24, 5, 28, 45, 98, 52, 60
    };
    
    for (int i: testcase) {
        v.push_back(i);
    }
#else
    int x;

    while (cin >> x) {
        v.push_back(x);
    }
#endif
    
    pre2tree();
    
    postTraverse(1);
}