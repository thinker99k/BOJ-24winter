#include <iostream>

using namespace std;

int n; // n = 2^k, 1<=k<=7

int arr[128][128];
bool checked[128][128];

int color1, color2;

void dp() {
    int offset = n;
    
    int start;
    bool issame;
    
    while (offset > 0) {
        for (int i = 0; i < n; i += offset) {
            for (int j = 0; j < n; j += offset) {
                // 해당 영역이 탐색되지 않은 영역일 경우만 탐색
                if (!checked[i][j]) {
                    issame = true;
                    start = arr[i][j];
                    
                    // 구역 내 탐색
                    for (int row = i; row < i + offset; row++) {
                        for (int col = j; col < j + offset; col++) {
                            if (arr[row][col] != start) {
                                issame = false;
                                break;
                            }
                        }
                        if (!issame) {
                            break;
                        }
                    }
                    
                    
                    // 한 구역이 모두 같은 색상이면
                    if (issame) {
                        for (int row = i; row < i + offset; row++) {
                            for (int col = j; col < j + offset; col++) {
                                checked[row][col] = true;
                            }
                        }
                        
                        if (start == 0) {
                            color1++;
                        }
                        else {
                            color2++;
                        }
                    }
                }
            }
        }
        
        offset /= 2;
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
    
    cout << color1 << " " << color2;
}