#include <iostream>

using namespace std;

int n;
int ans;
int arr[100][100];

void bfs(int r, int c) {
    if (arr[r][c] == 0) {
        if (r == n - 1 && c == n - 1) {
            // 최종 목적지
            ++ans;
        }
        else {
            // 갇혀버린 상황
            return;
        }
    }
    else if (r >= n || c >= n) {
        // 범위 초과
        return;
    }
    else {
        bfs(r + arr[r][c], c);
        bfs(r, c + arr[r][c]);
    }
}

int main() {
    ans = 0;
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    bfs(0, 0);
    
    cout << ans;
    
}