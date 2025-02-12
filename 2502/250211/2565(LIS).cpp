#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0

using namespace std;

typedef pair<int, int> line;

int n;
vector<line> v;

int lis() {
    // dp[i] : i번째에서 끝나는 증가하는 수열
    int dp[n + 1];
    fill(&dp[0], &dp[0] + (n + 1), 1);
    
    int ret = 0;
    dp[0] = 0; // 당연하다
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i - 1; j++) {
            if (v[j].second < v[i].second) {
                dp[i] = max(dp[i], dp[j]+1); // 지금까지 알려진 최대 길이, 마지막이 j->i로 가는 길이
            }
        }
        
        if (dp[i] > ret) {
            ret = dp[i];
        }
    }

#if DEBUG
    for(auto it : dp){
        cout << it << " ";
    }
    cout << "\n";
#endif
    
    return ret;
}

int main() {
    cin >> n;
    
    v.push_back({0, 0});
    
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        
        v.push_back({a, b});
    }
    
    sort(v.begin(), v.end());

#if DEBUG
    for(auto it : v){
        cout << "(" << it.first << "," << it.second << ") ";
    }
    cout << "\n";
#endif
    
    cout << n - lis();
}