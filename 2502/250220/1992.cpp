#include <iostream>
#include <string>
#include <cstring>

#define OP ans+="("
#define CP ans+=")"

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

int n;
int arr[64][64];

string ans;

bool chk(int dist, Pos &p) {
    int start = arr[p.row][p.col];
    
    for (int i = p.row; i < p.row + dist; i++) {
        for (int j = p.col; j < p.col + dist; j++) {
            if (arr[i][j] != start) {
                return false; // 해당 영역이 동일하지 않음
            }
        }
    }
    
    return true; // 해당 영역이 동일함
}

void quadtree(int dist, Pos p) {
    if (chk(dist, p)) {
        ans += to_string(arr[p.row][p.col]);
    }
    else {
        int nextdist = dist / 2;
        
        Pos q[4]{
                {p.row, p.col},
                {p.row, p.col + nextdist},
                {p.row + nextdist, p.col},
                {p.row + nextdist, p.col + nextdist}
        };
        
        OP;
        for (Pos it: q) {
            quadtree(nextdist, it);
        }
        CP;
    }
}

int main() {
    cin >> n;
    
    char buf[65];
    for (int i = 0; i < n; i++) {
        memset(buf, 0, 65);
        cin >> buf;
        
        for (int j = 0; j < n; j++) {
            arr[i][j] = buf[j] - '0';
        }
    }
    
    quadtree(n, {0, 0});
    
    cout << ans;
}