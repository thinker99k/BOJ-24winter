#include <iostream>
#include <cstring>
#include <queue>

#define DEBUG 0

using namespace std;

typedef struct {
    int row;
    int col;
    int day;
} Pos;

int row, col;
int tomato[1000][1000];
int checked[1000][1000];

queue<Pos> q;

bool isValid(Pos *p) {
    // 1. 범위 체크
    if (p->row >= row || p->row < 0 || p->col >= col || p->col < 0) {
        return false;
    }
    
    // 2. 이미 지나간 곳 체크 - 이는 빈 칸 체크, 시작 시 바로 옆의 익은 토마토 체크를 겸한다
    if (checked[p->row][p->col] == 1) {
        return false;
    }
    
    return true;
}

int bfs() {
    int ret, prevday = 0;
    Pos pp, p1, p2, p3, p4;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (tomato[i][j] == 1) {
                /** checked = 1을 while문에서 해주는데
                 시작하는 토마토의 바로 인근 토마토도 익어있으면 큐에 중복되어 들어감 */
                checked[i][j] = 1;
                q.push(Pos{i, j, 0});
            }
            if (tomato[i][j] == -1){
                /** 빈 칸도 걸러지게끔 체크 */
                checked[i][j] = 1;
            }
        }
    }
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        if (pp.day > prevday) {
            prevday = pp.day;
        }
        
        checked[pp.row][pp.col] = 1;
        
        p1 = {pp.row + 1, pp.col, pp.day + 1};
        p2 = {pp.row - 1, pp.col, pp.day + 1};
        p3 = {pp.row, pp.col + 1, pp.day + 1};
        p4 = {pp.row, pp.col - 1, pp.day + 1};
        
        if (isValid(&p1)) {
            // 하
            q.push(p1);
        }
        if (isValid(&p2)) {
            // 상
            q.push(p2);
        }
        if (isValid(&p3)) {
            // 우
            q.push(p3);
        }
        if (isValid(&p4)) {
            // 좌
            q.push(p4);
        }
    }
    
    // 일단은 지나간 날 수
    ret = prevday;

#if DEBUG
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%4d", checked[i][j]);
        }
        printf("\n");
    }
#endif
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            // bfs가 끝났는데도 안 익은 토마토가 있으면
            if (checked[i][j] == 0)
                return -1;
        }
    }
    
    return ret;
}

int main() {
    cin >> col >> row;
    
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> tomato[i][j];
        }
    }
    
    cout << bfs();
    
}