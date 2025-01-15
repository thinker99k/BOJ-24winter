#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull mod(ull n, int m) {
    return (ull)(n % m);
}

ull dp(int a, int b, int c) {
    ull ret = a;
    
    for (int i = 0; i < b; i++) {
        ret = mod(ret * a, c);
    }
    
    return ret;
}

int main() {
    int a, b, c;
    
    cin >> a >> b >> c;
    
    cout << dp(a, b, c);
}