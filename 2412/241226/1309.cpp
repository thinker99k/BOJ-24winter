#include <iostream>

using namespace std;

int n;
int sum[100000][3];

int mod(int x) {
    return x % 9901;
}

int dp() {
    sum[0][0] = 1;
    sum[0][1] = 1;
    sum[0][2] = 1;
    
    for (int i = 1; i < n; i++) {
        sum[i][0] = mod(mod(sum[i - 1][0]) + mod(sum[i - 1][1]) + mod(sum[i - 1][2]));
        sum[i][1] = mod(mod(sum[i - 1][0]) + mod(sum[i - 1][1]));
        sum[i][2] = sum[i][1];
    }
    
    return mod(mod(sum[n - 1][0]) + mod(sum[n - 1][1]) + mod(sum[n - 1][2]));
}

int main() {
    cin >> n;
    
    cout << dp();
}드