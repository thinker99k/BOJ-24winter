#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull a, b, c;

ull mod(ull n) {
    return n % c;
}

ull pow(ull n, ull k) {
    ull ret = 1;
    
    while (k) {
        if (k % 2) {
            ret = mod(mod(ret) * mod(n));
        }
        n = mod(mod(n) * mod(n));
        k /= 2;
    }
    
    return ret;
}

int main() {
    cin >> a >> b >> c;
    
    cout << pow(a, b);
}