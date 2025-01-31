#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define EXIT exit(0)
#define DEBUG 0

using namespace std;

typedef pair<int, int> Position; // <row, col>

typedef struct {
    Position pos;
    int direction;
} bfsobj;

typedef struct {
    Position t;
    Position s;
    int collision_row;
    int collision_col;
} Collision;

int n;

char arr[6][6];
vector<Position> x;
vector<Position> t;
vector<Position> s;
int xsz, tsz, ssz;

vector<Collision> c;

vector<Position> comb;

char tmparr[6][6];

bool isvalid(const int row, const int col) {
    if ((row < 0 || row >= n) || (col < 0 || col >= n)) {
        return false;
    }
    
    return true;
}

/** case : O'Clock */
void auto_enqueue(bfsobj *o, queue<bfsobj> *ptrq) {
    switch (o->direction) {
        case 3: {
            if (isvalid(o->pos.first, o->pos.second + 1)) {
                ptrq->push({{o->pos.first, o->pos.second + 1}, o->direction});
            }
            break;
        }
        case 6: {
            if (isvalid(o->pos.first + 1, o->pos.second)) {
                ptrq->push({{o->pos.first + 1, o->pos.second}, o->direction});
            }
            break;
        }
        case 9: {
            if (isvalid(o->pos.first, o->pos.second - 1)) {
                ptrq->push({{o->pos.first, o->pos.second - 1}, o->direction});
            }
            break;
        }
        case 12: {
            if (isvalid(o->pos.first - 1, o->pos.second)) {
                ptrq->push({{o->pos.first - 1, o->pos.second}, o->direction});
            }
            break;
        }
        default: { ;
        }
    }
}

bool bfsrslt; // 맞는 경우라면 true 유지, false 되자마자 bfs 무조건 종료

void directed_bfs() {
    queue<bfsobj> q;
    
    // 선생부터 bfs 탐색 시작할거임
    for (int i = 0; i < tsz; i++) {
        q.push({t[i], 0});
    }
    
    while (!q.empty()) {
        if (!bfsrslt) {
            return;
        }
        
        bfsobj pp = q.front();
        q.pop();
        
        if (pp.direction) {
            // 방향성 있게 탐색하는 동안
            switch (tmparr[pp.pos.first][pp.pos.second]) {
                case 'S': {
                    // 학생을 만난 경우 -> bfs 즉시 종료 트리거 설정
                    bfsrslt = false;
                    break;
                }
                case 'X': {
                    // 빈 칸을 만난경우 -> 다음 탐색 준비
                    auto_enqueue(&pp, &q);
                    break;
                }
                default: {
                    // 장애물 or 선생을 만난 경우 -> 해당 탐색은 종료
                    break;
                }
            }
        }
        else {
            // pp.direction == 0 -> bfs 첫 시작시에만 동작함
            bfsobj oo{pp.pos, pp.direction};
            
            for (int i = 1; i <= 4; i++) {
                oo.direction = i * 3;
                auto_enqueue(&oo, &q);
            }
        }
    }
}

bool eval() {
    bfsrslt = true;
    
    // checked, tmparr 배열 초기화
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmparr[i][j] = arr[i][j];
        }
    }
    
    // tmparr에 장애물 표시
    for (int i = 0; i < 3; i++) {
        tmparr[comb[i].first][comb[i].second] = 'O';
    }
    
    directed_bfs();
    
    return bfsrslt;
}

void backtrack(int level, int start) {
    if (level == 3) {
        if (eval()) {
#if DEBUG
            for (int i = 0; i < 3; i++) {
                cout << "(" << comb[i].first << "," << comb[i].second << ") ";
            }
            cout << "\n";
            cout << "YES\n";
#else
            cout << "YES\n";
            EXIT;
#endif
        }
    }
    else {
        for (int i = start; i < xsz; i++) {
            comb.push_back(x[i]);
            
            backtrack(level + 1, i + 1);
            
            comb.pop_back();
        }
    }
}

#if DEBUG
void testcase(){
    comb.push_back({0,3});
    comb.push_back({1,1});
    comb.push_back({2,2});
    
    for (int i = 0; i < 3; i++) {
        cout << "(" << comb[i].first << "," << comb[i].second << ") ";
    }
    cout << "\n";
    
    if (eval()) {
        cout << "YES\n";
        
    }
    cout << "\n";
}
#endif

int main() {
    cin >> n;
    
    char tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            
            if (tmp == 'X') {
                x.push_back({i, j});
            }
            else if (tmp == 'T') {
                t.push_back({i, j});
            }
            else {
                s.push_back({i, j});
            }
            
            arr[i][j] = tmp;
        }
    }
    
    xsz = (int) x.size();
    tsz = (int) t.size();
    ssz = (int) s.size();
    
    for (int tidx = 0; tidx < tsz; tidx++) {
        for (int sidx = 0; sidx < ssz; sidx++) {
            if (t[tidx].first == s[sidx].first) {
                // row 충돌
                if (abs(t[tidx].second - s[sidx].second) == 1) {
                    // 선생학생 거리가 1이면 사이에 장애물 배치 불가
                    cout << "NO\n";
                    EXIT;
                }
                else {
                    c.push_back({t[tidx], s[sidx], t[tidx].first, -1});
                }
            }
            
            if (t[tidx].second == s[sidx].second) {
                // col 충돌
                if (abs(t[tidx].first - s[sidx].first) == 1) {
                    // 선생학생 거리가 1이면 사이에 장애물 배치 불가
                    cout << "NO\n";
                    EXIT;
                }
                else {
                    c.push_back({t[tidx], s[sidx], -1, t[tidx].second});
                }
            }
        }
    }

#if DEBUG
    cout << "==== collisions ====\n";
    
    for (int i = 0; i < c.size(); i++) {
        cout << i + 1;
        if (c[i].t.first == c[i].s.first) {
            cout << " : row\n";
            
            if (c[i].t.second < c[i].s.second) {
                cout << "T(" << c[i].t.first << "," << c[i].t.second << ")-S(" << c[i].s.first << "," << c[i].s.second
                     << ")\n";
            }
            else {
                cout << "S(" << c[i].s.first << "," << c[i].s.second << ")-T(" << c[i].t.first << "," << c[i].t.second
                     << ")\n";
            }
            
        }
        else {
            cout << " : col\n";
            
            if (c[i].t.first < c[i].s.first) {
                cout << "T(" << c[i].t.first << "," << c[i].t.second << ")\n";
                cout << "  |  \n";
                cout << "S(" << c[i].s.first << "," << c[i].s.second << ")\n";
            }
            else {
                cout << "S(" << c[i].s.first << "," << c[i].s.second << ")\n";
                cout << "  |  \n";
                cout << "T(" << c[i].t.first << "," << c[i].t.second << ")\n";
            }
        }
    }
    cout << "====================\n\n";
#endif
    
    /** 위에서 아예 불가능한 상황을 걸러냈기에
     * 백트랙은 장애물을 놓을 수 있는 상황에 대해서만 실행됨
     */
    
    backtrack(0, 0);
    
    cout << "NO\n";
    
    return 0;
}