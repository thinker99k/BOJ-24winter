#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int layer;
    int row;
    int col;
    int day;
} Pos;

int layer, row, col;
int tomato[100][100][100];
int checked[100][100][100];

queue<Pos> q;

bool isValid(Pos *p) {
    // 1. 범위 체크
    if (p->layer >= layer || p->layer < 0 ||
        p->row >= row || p->row < 0 ||
        p->col >= col || p->col < 0) {
        return false;
    }
    
    // 2. 이미 지나간 곳 체크 - 이는 빈 칸 체크, 시작 시 바로 옆의 익은 토마토 체크를 겸한다
    if (checked[p->layer][p->row][p->col] == 1) {
        return false;
    }
    
    return true;
}

int bfs() {
    int ret, prevday = 0, z, y, x;
    Pos pp, pnext[6];
    
    for (int i = 0; i < layer; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                if (tomato[i][j][k] == 1) {
                    /** checked = 1을 while문에서 해주는데
                     시작하는 토마토의 바로 인근 토마토도 익어있으면 큐에 중복되어 들어감 */
                    checked[i][j][k] = 1;
                    q.push(Pos{i, j, k, 0});
                }
                if (tomato[i][j][k] == -1) {
                    /** 빈 칸도 걸러지게끔 체크 */
                    checked[i][j][k] = 1;
                }
            }
        }
    }
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        if (pp.day > prevday) {
            prevday = pp.day;
        }
        
        pnext[0] = {pp.layer + 1, pp.row, pp.col, pp.day + 1};
        pnext[1] = {pp.layer - 1, pp.row, pp.col, pp.day + 1};
        pnext[2] = {pp.layer, pp.row + 1, pp.col, pp.day + 1};
        pnext[3] = {pp.layer, pp.row - 1, pp.col, pp.day + 1};
        pnext[4] = {pp.layer, pp.row, pp.col + 1, pp.day + 1};
        pnext[5] = {pp.layer, pp.row, pp.col - 1, pp.day + 1};
        
        for (auto & i : pnext) {
            z = i.layer;
            y = i.row;
            x = i.col;
            
            if (isValid(&i)) {
                checked[z][y][x] = true;
                q.push(i);
            }
        }
    }
    
    // 일단은 지나간 날 수
    ret = prevday;
    
    for (int i = 0; i < layer; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                // bfs가 끝났는데도 안 익은 토마토가 있으면
                if (checked[i][j][k] == 0) {
                    return -1;
                }
            }
        }
    }
    
    return ret;
}

int main() {
    cin >> col >> row >> layer;
    
    for (int i = 0; i < layer; i++) {
        for (int j = 0; j < row; j++) {
            for (int k = 0; k < col; k++) {
                cin >> tomato[i][j][k];
            }
        }
    }
    
    cout << bfs();
    
}