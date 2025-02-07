#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

int sudoku[9][9];

bool rowused[9][10];   // idx1번째 행에 idx2가 쓰였는지
bool colused[9][10];   // idx1번째 열에 idx2가 쓰였는지
bool sqused[3][3][10];  // 각 3x3에 idx3가 쓰였는지


void check(Pos p, int x) {
    sudoku[p.row][p.col] = x;
    
    rowused[p.row][x] = true;
    colused[p.col][x] = true;
    sqused[p.row / 3][p.col / 3][x] = true;
}

void uncheck(Pos p, int x) {
    sudoku[p.row][p.col] = 0;
    
    rowused[p.row][x] = false;
    colused[p.col][x] = false;
    sqused[p.row / 3][p.col / 3][x] = false;
}

void prn() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }
}

int bt_end;

vector<Pos> tofill;

void backtrack(int lv) {
    if (lv == bt_end) {
        prn();
        exit(0);
    }
    else {
        for (int j = 1; j <= 9; j++) {
            if (!rowused[tofill[lv].row][j] &&
                !colused[tofill[lv].col][j] &&
                !sqused[tofill[lv].row / 3][tofill[lv].col / 3][j]) {
                
                check(tofill[lv], j);
                
                backtrack(lv + 1);
                
                uncheck(tofill[lv], j);
            }
        }
    }
}

int main() {
    char buf[10];
    
    for (int i = 0; i < 9; i++) {
        memset(buf, 0, sizeof(char) * 10);
        cin >> buf;
        
        for (int j = 0; j < 9; j++) {
            if (buf[j] == '0') {
                tofill.push_back({i, j});
            }
            else {
                sudoku[i][j] = (int) (buf[j] - '0');
                check({i, j}, (int) (buf[j] - '0'));
            }
        }
    }
    
    bt_end = (int) tofill.size();
    
    backtrack(0);
}