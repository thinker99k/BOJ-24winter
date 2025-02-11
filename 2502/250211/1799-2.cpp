#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

bool diag1used[19]; // y=x꼴 대각선 -> (컨버팅 후) 행
bool diag2used[19]; // y=-x꼴 대각선 -> (컨버팅 후) 열

int m, lim;
int ans;

vector<Pos> tofill[19]; // (컨버팅 된) 각 행에 들어갈 수 있는 후보군
int tofillsz[19];

#if DEBUG
int tiltedchess[19][19];

void prn() {
    for (int i = 0; i < lim; i++) {
        for (int j = 0; j < lim; j++) {
            if (tiltedchess[i][j] >= 0) {
                cout.width(2);
                cout << tiltedchess[i][j];
            }
            else {
                cout << "  ";
            }
        }
        cout << '\n';
    }
}

#endif

/** 체스판을 시계방향으로 45도 회전 */
Pos posconv(Pos pp) {
    Pos ret;
    
    ret.row = pp.row + pp.col;
    ret.col = ((m - 1) - pp.row) + pp.col;
    
    return ret;
}

void mark(Pos p) {
    diag1used[p.row] = true;
    diag2used[p.col] = true;
}

void unmark(Pos p) {
    diag1used[p.row] = false;
    diag2used[p.col] = false;
}

vector<Pos> comb;

#if DEBUG

void prncomb() {
    for (auto &i: comb) {
        cout << "(" << i.row << "," << i.col << ") ";
    }
    cout << "\n";
}

#endif

// 45도 돌린 체스판에서 비숍은 같은 행, 열 x
void backtrack(int row) {
    // comb의 크기가 알려진 크기보다 크면 갱신
    int currcombsz = (int) comb.size();
    if (currcombsz > ans) {
        ans = currcombsz;
    }

#if DEBUG
    prncomb();
#endif
    
    if (row >= lim) {
        /** 매개변수 row로 행 날리기!! */
        return;
    }
    
    if (diag1used[row]) {
        // 시간복잡도 줄이기 - (컨버팅 된) 행에 아예 못놓는 경우는 빠르게 다음 행으로 패스
        backtrack(row + 1);
    }
    else {
        // else 분기는 row번째 행에 놓을 수 있음이 보장됨
        int btcount = 0;
        
        for (int i = 0; i < tofillsz[row]; i++) {
            /** i로 열 날리기!! */
            
            if (!diag2used[tofill[row][i].col]) {
                // 이 열에 에 비숍을 놓을 수 있으면, 백트랙 다음 레벨 전개
                
                comb.push_back(tofill[row][i]);
                mark(tofill[row][i]);
                
                btcount++;
                backtrack(row + 1);
                
                comb.pop_back();
                unmark(tofill[row][i]);
            }
        }
        
        /** 놓을 수는 있는데, tofillsz[row]가 0일경우 -> 다음 행으로 백트랙 전개 실패
         * 따라서 전개가 안 된 경우 강제 전개 */
        if(!btcount){
            backtrack(row + 1);
        }
    }
}

int main() {
    cin >> m;
    
    lim = m * 2 - 1;

#if DEBUG
    fill(&tiltedchess[0][0], &tiltedchess[0][0] + 19 * 19, -1);
#endif
    
    int b;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b;
            
            Pos convedpos = posconv({i, j});
            
            if (b == 1) {
                tofill[convedpos.row].push_back(convedpos);
            }

#if DEBUG
            tiltedchess[convedpos.row][convedpos.col] = b == 1;
#endif
        }
    }

#if DEBUG
    prn();
#endif
    
    for(int i=0; i<19; i++){
        tofillsz[i] = tofill[i].size();
    }
    
    backtrack(0);
    
    cout << ans;
    
}