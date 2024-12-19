#include <iostream>

using namespace std;

int n, ans, tmp;

// 계단 별 점수
int stair[301];

void dp(int x, int sum, int previnc) {
    if (x > n) {
        // 범위 초과
        return;
    }
    else {
        int newsum = sum + stair[x];
        
        if (x == n) {
            // 마지막 계단
            if (newsum > ans) {
                ans = newsum;
            }
        }
        else {
            // 그 외
            if (x < 2) {
                // x == 0 : 처음에는 한 칸 점프, 두 칸 점프 가능
                // x == 1 : 첫 번째 계단은 시작 시에만 한 칸 점프로 도달 가능
                    dp(x + 1, newsum, 1);
                    dp(x + 2, newsum, 2);
            }
            else {
                if (previnc == 2) {
                    dp(x + 1, newsum, 1);
                    dp(x + 2, newsum, 2);
                }
                else {
                    // n을 1과 2로 분할하는데, "1+1"과 같이 나오면 안됨
                    dp(x + 2, newsum, 2);
                }
            }
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        stair[i] = tmp;
    }
    
    dp(0, 0, 0);
    
    cout << ans;
}