#include <iostream>

using namespace std;

int n;
int arr[2187][2187];
int visited[2187][2187];

int ans[3]; // 각각 색상 -1, 0, 1

bool isArea(int r, int c, int offset) {
    int color = arr[r][c];
    
    int rlim = r + offset;
    int clim = c + offset;
    
    for (int i = r; i < rlim; i++) {
        for (int j = c; j < clim; j++) {
            if (arr[i][j] != color) {
                return false;
            }
        }
    }
    
    // 이 이후로는 영역있음이 확인된 true인 경우만 실행
    
    for (int i = r; i < rlim; i++) {
        for (int j = c; j < clim; j++) {
            visited[i][j] = true;
        }
    }
    
    return true;
}

void dp(int row, int col, int offset) {
    if(isArea(row, col, offset)){
        ans[arr[row][col]+1]++;
    }
    
    int newoffset = offset / 3;
    
    if(newoffset == 0){
        return;
    }
    
    for(int i=row; i<row+offset; i+=newoffset){
        for(int j=col; j<col+offset; j+=newoffset){
            if(!visited[i][j]){
                dp(i, j, newoffset);
            }
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp(0, 0, n);
    
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << endl;
    }
}