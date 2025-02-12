#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
vector<int> ans;

int lis(int n) {
    int ret = 0;
    
    // dp[i] : i번째에서 끝나는 증가하는 수열
    vector<int> dp(n, 1);
    
    // prev[i] : i번째에서 dp[i]에 대한 이전 인덱스
    vector<int> prev(n, -1);
    
    int last = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (v[j] < v[i] &&
                dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1; // 업데이트 될 때만
                prev[i] = j; // 이전 인덱스 찾기
            }
        }
        
        if (dp[i] > ret) {
            ret = dp[i];
            last = i;
        }
    }
    
    // 백트래킹
    while (last != -1) {
        ans.push_back(v[last]);
        last = prev[last];
    }
    
    reverse(ans.begin(), ans.end());
    
    return ret;
}

int main() {
    int n;
    
    cin >> n;
    
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        
        v.push_back(a);
    }
    
    cout << lis(n) << "\n";
    
    for (auto it: ans) {
        cout << it << " ";
    }
}