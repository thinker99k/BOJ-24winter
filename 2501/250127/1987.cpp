#include <iostream>

#define DEBUG 0

using namespace std;

typedef struct{
    int row;
    int col;
} Pos;

int r, c;
int ans;

char arr[20][20];
bool checked[26];

bool isValid(Pos &pp){
    // 1. 범위 체크
    if((pp.row < 0 || pp.row >= r)
    || (pp.col < 0 || pp.col >= c)){
        return false;
    }
    
    // 2. 알파벳 사용 체크
    if(checked[arr[pp.row][pp.col] - 'A']){
        return false;
    }
    
    return true;
}

void backtrack(Pos p, int level){
#if DEBUG
    cout << "level " << level << "\n";
    cout << "Searching (" << p.row << ", " << p.col << ")\n";
#endif
    
    Pos parr[4] = {
            {p.row+1, p.col},
            {p.row-1, p.col},
            {p.row, p.col+1},
            {p.row, p.col-1}
    };
    
    bool pvalid[4] = {false, false, false, false};
    int pvalidnum = 0;
    
    for(int i=0; i<4; i++){
        if(isValid(parr[i])){
            pvalid[i] = true;
            ++pvalidnum;
        }
    }
    
    if(!pvalidnum){
        if(level > ans){
#if DEBUG
            cout << "ans " << ans << "->" << level << "\n";
#endif
            ans = level;
        }
    }
    else{
        for(int i=0; i<4; i++){
            if(pvalid[i]){
                checked[arr[parr[i].row][parr[i].col] - 'A'] = true;
                
                backtrack(parr[i], level+1);
                
                checked[arr[parr[i].row][parr[i].col] - 'A'] = false;
            }
        }
    }
}

int main(){
    cin >> r >> c;
    
    for(int i=0; i<r; i++){
        cin >> arr[i];
    }
    
    checked[arr[0][0] - 'A'] = true;
    backtrack({0, 0}, 0);
    
    cout << ans + 1;
}