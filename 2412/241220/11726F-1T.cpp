#include <iostream>

using namespace std;

// x mod 10007 반환
int mod(int x) {
    return x % 10007;
}

int comb(int n, int r) {
    if (r == 0 || r == n) {
        return 1;
    }
    else {
        return comb(n - 1, r - 1) + comb(n - 1, r);
    }
}

int calc(int k) {
    int ret = 0;
    
    int t = k / 2 + 1;
    int tmp;
    
    for(int i=0; i<t; i++){
        tmp = mod(comb(k-i, i));
        ret += tmp;
    }
    
    return ret;
}

int main() {
    // 2 * n 사이즈
    int n;
    cin >> n;
    
    cout << calc(n);
}