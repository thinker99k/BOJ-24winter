#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

int m, msq, mdiag, isz;
int ans;

vector<Pos> comb;

void prn1() {
    for (int i = 0; i < m; i++) {
        cout << "(" << comb[i].row << ", " << comb[i].col << ") ";
    }
    cout << "\n";
}

void prn2() {
    bool isstar;
    
    for (int i = 0; i < m; i++) {
        cout << "|";
        for (int j = 0; j < m; j++) {
            isstar = false;
            
            for (int k = 0; k < m; k++) {
                if (comb[k].row == i && comb[k].col == j) {
                    isstar = true;
                    break;
                }
            }
            
            if (isstar) {
                cout << "*|";
            }
            else {
                cout << " |";
            }
            
        }
        cout << "\n";
    }
    
    cout << "\n";
}

int colchk[15];
int diag12chk[2][29]; // diag2는 col 뒤집어야함

void mark(Pos *P) {
    colchk[P->col]++;
    
    diag12chk[0][P->row + P->col]++;
    
    // col 뒤집어야함
    int newcol = (m - 1) - P->col;
    diag12chk[1][P->row + newcol]++;
}

void unmark(Pos *P) {
    colchk[P->col]--;
    
    diag12chk[0][P->row + P->col]--;
    
    // col 뒤집어야함
    int newcol = (m - 1) - P->col;
    diag12chk[1][P->row + newcol]--;
}

// backtrack()에서 행열 체크 하면서 진행되므로, queen에서는 대각선만 체크
bool queen() {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < mdiag; j++) {
            if (diag12chk[i][j] > 1) {
                return false;
            }
        }
    }
    
    return true;
}

/** m*m개를 전부 백트랙 하는것은 미친짓임!!!!
 * 조건 4개 - 같은 행, 같은 열, 같은 대각선 좌, 같은 대각선 우
 * 이중에서 앞 두개의 조건을 날려주면 연산의 횟수가 극적으로 줄어든다
 *
 * 행 날리는법 : 백트랙의 level을 행으로 생각
 * 열 날리는법 : chkcol[]
 */
void backtrack(int rr) {
    if (rr == m) {
        // prn1();
        if (queen()) {
            ans++;
            // prn2();
        }
    }
    else {
        for (int i = 0; i < m; i++) {
            if (!colchk[i]) {
                Pos newQueen = {rr, i};
                
                mark(&newQueen);
                comb.push_back(newQueen);
                colchk[i] = true;
                
                backtrack(rr + 1);
                
                unmark(&newQueen);
                comb.pop_back();
                colchk[i] = false;
            }
        }
    }
}

int main() {
    cin >> m;
    
    msq = m * m;
    mdiag = m * 2 - 1;
    isz = sizeof(int);
    ans = 0;
    
    backtrack(0);
    
    cout << ans;
}