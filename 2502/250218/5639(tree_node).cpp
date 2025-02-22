#include <iostream>
#include <vector>

#define START 1
#define DEBUG 0

using namespace std;

typedef struct __Node {
    int val;
    __Node *Left;
    __Node *Right;
} Node;

Node * root;

vector<int> v;

Node *makeNode(int val) {
    Node *ret = new Node;
    ret->val = val;
    ret->Left = nullptr;
    ret->Right = nullptr;
    
    return ret;
}

void makeLc(Node *n, int val) {
    Node *lc = makeNode(val);
    n->Left = lc;
}

void makeRc(Node *n, int val) {
    Node *rc = makeNode(val);
    n->Right = rc;
}

void postTraverse(Node *p) {
    if (p) {
        postTraverse(p->Left);
        postTraverse(p->Right);
        
        cout << p->val << '\n';
    }
}

void pre2tree() {
    int nodenum = (int) v.size() - 1;
    
    root = makeNode(v[1]);
    
    int vi;
    bool LR;
    Node * curr;
    Node * next;
    
    for (int i = 2; i <= nodenum; i++) {
        vi = v[i];
        curr = root;
        
        while (true) {
            LR = vi >= curr->val;
            next = !LR ? curr->Left : curr->Right;
            
            if (next == nullptr) {
                // 저장 가능
                if(!LR){
                    // 왼쪽 자식노드
                    makeLc(curr, v[i]);
                }
                else{
                    // 오른쪽 자식노드
                    makeRc(curr, v[i]);
                }
                
                break;
            }
            else{
                // 저장 불가능 -> 다시 탐색
                curr = next;
            }
        }
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
    
    postTraverse(root);
}