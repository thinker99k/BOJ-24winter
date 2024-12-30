#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull gcd(ull x, ull y) {
    ull a, b, tmp;
    a = x;
    b = y;
    
    while (b != 0) {
        tmp = a % b;
        a = b;
        b = tmp;
    }
    
    return a;
}

int main(){
    ull A, B;
    
    cin >> A >> B;
    
    for(ull i=0; i<gcd(A, B); i++){
        cout << '1';
    }
}