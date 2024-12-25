#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull arr[1000001];

// x mod 15746 반환
ull mod(ull x) {
    return x % 15746;
}

ull fibo(ull x) {
    arr[1] = 1;
    for (int i = 2; i <= x + 1; i++) {
        arr[i] = mod(mod(arr[i - 1]) + mod(arr[i - 2]));
    }
    
    return arr[x + 1];
}

int main() {
    int n;
    cin >> n;
    
    cout << fibo(n);
}