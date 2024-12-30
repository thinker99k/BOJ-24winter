#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull a, b, c;

ull mod(ull n) {
    return n % c;
}

ull pow(ull n, ull k) {
    if (k == 0) {
        return 1;
    }
    else if (k == 1) {
        return mod(n);
    }
    else {
        ull x = mod(pow(n, k / 2));
        
        if (k % 2) {
            return mod(mod(x * x) * mod(a));
        }
        else {
            return mod(x * x);
        }
    }
}

int main() {
    cin >> a >> b >> c;
    
    cout << pow(a, b);
}