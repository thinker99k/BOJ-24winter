#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <sstream>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

typedef struct __Node {
    string val;
    __Node *childs[4];
} Node;

Node *makeNode() {
    Node *ret = new Node;
    ret->val = "";
    
    for(auto it : ret->childs){
        it = nullptr;
    }
    
    return ret;
}

int n;
int arr[512][512];
string ans;
Node *root;


void bfs() {
    queue<Node *> q;
    
    q.push(root);
    Node *pp;
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        ans += pp->val;
        
        for(auto it : pp->childs){
            if(it){
                q.push(it);
            }
        }
        
    }
}

bool chk(int dist, Pos &p) {
    int start = arr[p.row][p.col];
    
    for (int i = p.row; i < p.row + dist; i++) {
        for (int j = p.col; j < p.col + dist; j++) {
            if (arr[i][j] != start) {
                return false; // 해당 영역이 동일하지 않음
            }
        }
    }
    
    return true; // 해당 영역이 동일함
}

void quadtree(int dist, Pos p, Node *current) {
    if (chk(dist, p)) {
        // 현재 영역이 동일하면
        current->val = to_string(0) + to_string(arr[p.row][p.col]);
    }
    else {
        // 동일하지 않으면
        current->val = "1"; // "1" : 자식이 있다
        
        int nextdist = dist / 2;
        
        for(auto & child : current->childs){
            child = makeNode();
        }
        
        Pos q[4] = {
                {p.row,            p.col},
                {p.row,            p.col + nextdist},
                {p.row + nextdist, p.col},
                {p.row + nextdist, p.col + nextdist}
        };
        
        for (int i = 0; i < 4; i++) {
            quadtree(nextdist, q[i], current->childs[i]);
        }
    }
}

void reset() {
    n = 0;
    memset(arr, 0, 4 * 512 * 512);
    ans = "";
    root = nullptr;
}

int main() {
    int t;
    cin >> t;
    
    vector<string> s;
    
    for (int c = 0; c < t; c++) {
        reset();
        
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> arr[i][j];
            }
        }
        
        root = makeNode();
        quadtree(n, {0, 0}, root);
        
        bfs();
        
        s.push_back(ans);
    }
    
    uint number;
    for (const string &it: s) {
        number = stoi(it ,nullptr, 2);
        
        cout << std::uppercase << std::hex << number << "\n";
    }
}