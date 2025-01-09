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

void dp() {
    int offset = n;
    
    while (offset >= 1) {
        for (int i = 0; i < n; i += offset) {
            for (int j = 0; j < n; j += offset) {
                if(!visited[i][j]){
                    if (isArea(i, j, offset)) {
                        ans[arr[i][j]+1]++;
                    }
                }
            }
        }
        
        offset /= 3;
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp();
    
    for (int i = 0; i < 3; i++) {
        cout << ans[i] << endl;
    }
}