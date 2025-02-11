#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull a, r, n, m;

ull mod(ull x) {
    return x % m;
}

ull pow(ull x, ull k) {
    ull ret = 1;
    
    while (k) {
        if (k % 2) {
            ret = mod(mod(ret) * mod(x));
        }
        x = mod(mod(x) * mod(x));
        k /= 2;
    }
    
    return ret;
}

int main() {
    cin >> a >> r >> n >> m;
    
    ull ans = 0;
    ans += a;
    for(int i=2; i<=n; i++){
        ans += mod(mod(a) * mod(pow(r, n)));
        ans = mod(ans);
    }
    
    cout << ans;
}