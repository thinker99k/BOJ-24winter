#include <iostream>

using namespace std;

int wine[10001];
int sum[10001];

int max(int a, int b) {
    return a > b ? a : b;
}

int dp(int n) {
    sum[1] = wine[1];
    sum[2] = wine[1] + wine[2];
    sum[3] = max(wine[1] + wine[3], wine[2] + wine[3]);
    
    for (int i = 4; i <= n; i++) {
        int p = sum[i-3] + wine[i-1] + wine[i];
        int q = sum[i-1] + wine[i];
        
        sum[i] = max(p, q);
    }
    
    int ret;
    for(int i=1; i<=n; i++){
        ret = sum[i] > ret ? sum[i] : ret;
    }
    
    return ret;
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    cout << dp(n);
}