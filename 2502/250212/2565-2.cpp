#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> line;

vector<line> v;

int lis(int n) {
    int ret = 0;
    
    // dp[i] : i번째에서 끝나는 증가하는 수열
    vector<int> dp(n, 1);
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (v[j].second < v[i].second &&
                dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1; // 업데이트 될 때만
            }
        }
        
        if (dp[i] > ret) {
            ret = dp[i];
        }
    }
    
    return ret;
}

int main() {
    int n;
    
    cin >> n;
    
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end());
    
    cout << n - lis(n);
}