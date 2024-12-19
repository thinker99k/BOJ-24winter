#include <iostream>
#include <vector>

using namespace std;

// 계단 별 점수
int stair[301];

int n, ans;

void dp(vector<int> v) {
    int sz = v.size();
    
    if (v[sz-3] != 0
    && v[sz - 3] + 1 == v[sz - 2]
    && v[sz - 2] + 1 == v[sz - 1]) {
        // 세 계단 연속
        return;
    }
    
    if (v.back() > n) {
        // 범위 초과
        return;
    }
    else if (v.back() == n) {
        // 마지막 계단 도착
        int s = 0;
        
        for (int i = 3; i < v.size(); i++) {
            //cout << v[i] << "(" << stair[v[i]] << ") ";
            s += stair[v[i]];
        }
        
        //cout << "-> " << s << endl;
        
        if (s > ans) {
            ans = s;
        }
    }
    else {
        // 중간 어딘가
        vector<int> v1 = v;
        vector<int> v2 = v;
        
        v1.push_back(v.back() + 1);
        v2.push_back(v.back() + 2);
        
        dp(v1);
        dp(v2);
    }
}

int main() {
    cin >> n;
    
    int tmp;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        stair[i + 1] = tmp;
    }
    
    vector<int> vstart;
    vstart.push_back(-20);
    vstart.push_back(-10);
    vstart.push_back(0);
    
    dp(vstart);
    
    cout << ans;
}