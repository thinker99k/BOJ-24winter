#include <iostream>
#include <cstring>

#define szint 4

using namespace std;

int arr[2][100001];
int sum[2][100001];

int max(int a, int b) {
    return a > b ? a : b;
}

int dp(int n) {
    sum[0][1] = arr[0][1];
    sum[1][1] = arr[1][1];
    
    int twoprev;
    
    for (int i = 2; i <= n; i++) {
        // 두 칸 전은 위 아래 상관없고, 최대값만 가져오면 됨
        twoprev = max(sum[0][i - 2], sum[1][i - 2]);
        
        // 한 칸 전은 대각선 방향으로 가져와야 함
        sum[0][i] = max(twoprev, sum[1][i - 1]) + arr[0][i];
        sum[1][i] = max(twoprev, sum[0][i - 1]) + arr[1][i];
    }
    
    int ret = 0;
    
    for (int i = 0; i < 2; i++) {
        for (int j = 1; j <= n; j++) {
            ret = sum[i][j] > ret ? sum[i][j] : ret;
        }
    }
    
    return ret;
}

int main() {
    int t, n;
    cin >> t;
    
    int *ans = (int *) malloc(szint * t);
    
    for (int i = 0; i < t; i++) {
        memset(arr, 0, szint * 2 * 100001);
        memset(sum, 0, szint * 2 * 100001);
        cin >> n;
        
        for (int j = 1; j <= n; j++) {
            cin >> arr[0][j];
        }
        for (int j = 1; j <= n; j++) {
            cin >> arr[1][j];
        }
        
        ans[i] = dp(n);
    }
    
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    
    free(ans);
}