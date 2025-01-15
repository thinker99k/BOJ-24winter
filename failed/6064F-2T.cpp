#include <iostream>
#include <vector>

using namespace std;

int t, m, n, x, y;

vector<int> ans;

// 최대 40000*40000번의 끔찍하게 많은 루프 돌아야함;
int fun() {
    x %= m;
    y %= n;
    
    int cnt = 0, max = m * n;
    
    while (true) {
        cnt++;
        
        if (cnt > max) {
            return -1;
        }
        
        if ((cnt % m == x) && (cnt % n == y)) {
            return cnt;
        }
    }
}

int main() {
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> x >> y;
        
        ans.push_back(fun());
    }
    
    for (int an: ans) {
        cout << an << endl;
    }
}