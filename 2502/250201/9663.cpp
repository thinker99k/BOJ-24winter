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

// 대각선 체크하여 가능한 경우만 마크
bool diagmark(Pos *P) {
    // col 뒤집어야함
    int newcol = (m - 1) - P->col;
    
    if (!diag12chk[0][P->row + P->col] &&
        !diag12chk[1][P->row + newcol]) {
        diag12chk[0][P->row + P->col] = true;
        diag12chk[1][P->row + newcol] = true;
        
        return true;
    }
    
    return false;
}

void diagunmark(Pos *P) {
    diag12chk[0][P->row + P->col] = false;
    
    // col 뒤집어야함
    int newcol = (m - 1) - P->col;
    diag12chk[1][P->row + newcol] = false;
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
            // 행 조건 날림
            if (!colchk[i]) {
                // 열 조건 날림
                Pos newQueen = {rr, i};
                
                if(diagmark(&newQueen)){
                    // 여기는 마크가 성공적으로 되었을 때 - 대각선에 충돌이 없을 때만 실행
                    comb.push_back(newQueen);
                    colchk[i] = true;
                    
                    backtrack(rr + 1);
                    
                    diagunmark(&newQueen);
                    comb.pop_back();
                    colchk[i] = false;
                }
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