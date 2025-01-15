#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

// sqrt(100000) = 316.xx
int sq[320];

void square() {
    sq[0] = 0;
    sq[1] = 1;
    for (int i = 2; i < 320; i++) {
        sq[i] = i * i;
    }
}

int findSq(int x) {
    for (int i = 0; i < 320; i++) {
        if (sq[i] > x) {
            return sq[i - 1];
        }
    }
}

int dp(int n) {
    int ret = 0, tmp = n, x;
    
    while (tmp) {
        cout << "tmp : " << tmp << endl;
        x = findSq(tmp);
        ret += 1;
        tmp -= x;
    }
    
    return ret;
}

int main() {
    square();
    
    cout << dp(48);
}