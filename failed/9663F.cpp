#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

bool checked[15][15];

bool isrowused[15];
bool iscolused[15];
bool isdiag1used[29];
bool isdiag2used[29]; // col 뒤집어야함


int m, msq, ans;

/** 사용중인지 찾는 함수들*/
bool chkrowused(Pos *P) {
    return isrowused[P->row];
}

bool chkcolused(Pos *P) {
    return iscolused[P->col];
}

bool chkdiag1used(Pos *P) {
    return isdiag1used[P->row + P->col];
}

// col 뒤집어야함
bool chkdiag2used(Pos *P) {
    int newcol = (m - 1) - P->col;
    return isdiag2used[P->row + newcol];
}

/** 하나라도 사용중이면 return true, 전부 미사용중이면 return false */
bool chkused(Pos *P) {
    return (chkrowused(P)
            || chkcolused(P)
            || chkdiag1used(P)
            || chkdiag2used(P));
}

void mark(Pos *P) {
    isrowused[P->row] = true;
    
    iscolused[P->col] = true;
    
    isdiag1used[P->row + P->col] = true;
    
    // col 뒤집어야함
    int newcol = (m - 1) - P->col;
    isdiag2used[P->row + newcol] = true;
}

void unmark(Pos *P) {
    isrowused[P->row] = false;
    
    iscolused[P->col] = false;
    
    isdiag1used[P->row + P->col] = false;
    
    // col 뒤집어야함
    int newcol = (m - 1) - P->col;
    isdiag2used[P->row + newcol] = false;
}

Pos tmppos;
vector<Pos> comb;

void prn() {
    for (int i = 0; i < m; i++) {
        cout << "(" << comb[i].row << ", " << comb[i].col << ") ";
    }
    cout << "\n";
}

void backtrack(int level, int start) {
    if (level == m) {
        prn();
        ans++;
    }
    else {
        for (int i = start; i < msq; i++) {
            tmppos.row = i / m;
            tmppos.col = i % m;
            
            cout << "L" << level<< " - "<<"checking (" << tmppos.row << ", " << tmppos.col << ")\n";
            
            // 사용중이지 않으면
            if (!chkused(&tmppos)) {
                cout << ": pushed\n";
                comb.push_back(tmppos);
                mark(&tmppos);
                
                backtrack(level + 1, start + 1);
                
                comb.pop_back();
                unmark(&tmppos);
            }
        }
    }
}

int main() {
    cin >> m;
    
    msq = m * m;
    
    backtrack(0, 0);
    
    cout << ans;
}