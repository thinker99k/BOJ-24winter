#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

int n, nn, ans;

vector<Pos> positions;

bool conflict(Pos &a, Pos &b) {
    if (a.row == b.row) {
        return true;
    }
    
    if (a.col == b.col) {
        return true;
    }
    
    double dy = a.row - b.row;
    double dx = a.col - b.col;
    
    if ((dy / dx == 1.0) || (dy / dx == -1.0)) {
        return true;
    }
    
    return false;
}

vector<Pos> comb;

bool noconflict() {
    int sz = comb.size();
    
    for (int i = 0; i < sz - 1; i++) {
        for (int j = i + 1; j < sz; j++) {
            if (conflict(comb[i], comb[j])) {
                return false;
            }
        }
    }
    
    return true;
}


void backtrack(int start) {
    if (comb.size() == n){
        ans++;
        return;
    }
    
    for (int i=start; i<nn; i++){
        comb.push_back(positions[i]);
        
        if(noconflict()){
            backtrack(i+1);
        }
        
        comb.pop_back();
    }
}

int main() {
    cin >> n;
    nn = n * n;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            positions.push_back({i, j});
        }
    }
    
    backtrack(0);
    
    cout << ans;
}