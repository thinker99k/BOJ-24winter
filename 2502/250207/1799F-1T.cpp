#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

bool diag1used[19]; // y=x꼴 대각선
bool diag2used[19]; // y=-x꼴 대각선

int m, ans;

vector<Pos> tofill;
int tofillsz;

void mark(Pos p) {
    int newcol = (m - 1) - p.col;
    
    diag1used[p.row + p.col] = true;
    diag2used[p.row + newcol] = true;
}

void unmark(Pos p) {
    int newcol = (m - 1) - p.col;
    
    diag1used[p.row + p.col] = false;
    diag2used[p.row + newcol] = false;
}

bool isplace(Pos p) {
    int newcol = (m - 1) - p.col;
    
    if (diag1used[p.row + p.col] ||
        diag2used[p.row + newcol]) {
        return false;
    }
    
    return true;
}

void backtrack(int lv, int start) {
    // 현재 ans보다 더 높은 레벨의 백트랙이 실행 될 경우 갱신
    if (lv > ans) {
        ans = lv;
    }
    
    // cout << "current lv : " << lv << '\n';
    
    for (int i = start; i < tofillsz; i++) {
        // 이 자리에 비숍을 놓을 수 있으면, 백트랙 다음 레벨 전개
        
        if (isplace(tofill[i])) {
            mark(tofill[i]);
            
            backtrack(lv + 1, i + 1);
            
            unmark(tofill[i]);
        }
    }
}

int main() {
    cin >> m;
    
    int b;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b;
            
            if (b == 1) {
                tofill.push_back({i, j});
            }
        }
    }
    
    tofillsz = (int) tofill.size();
    
    backtrack(0, 0);
    
    cout << ans;
    
}