#include <iostream>
#include <vector>

using namespace std;

typedef struct __Node {
    int name; // 이름!!!!!
    __Node *Left;
    __Node *Right;
} Node;

/**
 * 해당 "이름"에 해당하는 노드를 가리키는 포인터들의 배열
 * nodePointer[i]가 가리키는 노드 x는 x->name이 i라는 뜻
 *
 * 당연히 처음에는 전부 0(nullptr) 저장되어있음
 */
Node *nodePointer[100001];

long long ans;

Node *last = nullptr;

Node *makeNode(int name) {
    Node *ret = new Node;
    ret->name = name;
    ret->Left = nullptr;
    ret->Right = nullptr;
    
    return ret;
}

bool pseudoInTraverse(Node *p) {
    if (!p) {
        return false;
    }
    
    ans++;
    
    if(!(p->Left) && !(p->Right) && p == last){
        return true;
    }
    
    if (p->Left) {
        if(pseudoInTraverse(p->Left)){
            return true;
        }
        
        ans++;
    }
    
    if (p->Right) {
        if(pseudoInTraverse(p->Right)){
            return true;
        }
        
        ans++;
    }
    
    return false;
}

// inTraverse
void findLastLeaf(Node *p) {
    if (!p) {
        return;
    }
    
    findLastLeaf(p->Left);
    
    // 찐막 리프노드냐?
    if (!p->Left && !p->Right) {
        last = p;
    }
    
    findLastLeaf(p->Right);
}

int main() {
    // v, l, r은 노드의 이름이다!
    int n, v, l, r;
    
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> v >> l >> r;
        
        // 해당하는 이름의 노드가 아직 없으면 만든다
        if (!nodePointer[v]) {
            nodePointer[v] = makeNode(v);
        }
        
        if (l != -1) {
            if (!nodePointer[l]) {
                nodePointer[l] = makeNode(l);
            }
            nodePointer[v]->Left = nodePointer[l];
        }
        if (r != -1) {
            if (!nodePointer[r]) {
                nodePointer[r] = makeNode(r);
            }
            nodePointer[v]->Right = nodePointer[r];
        }
    }
    
    findLastLeaf(nodePointer[1]);
    pseudoInTraverse(nodePointer[1]);
    
    cout << ans - 1;
}