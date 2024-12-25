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
        return mod(mod(comb(n - 1, r - 1)) + mod(comb(n - 1, r)));
    }
}

int main() {
    int n, r;
    
    cin >> n >> r;
    
    cout << comb(n, r);
}