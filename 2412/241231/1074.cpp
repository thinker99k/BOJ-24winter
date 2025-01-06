#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

ull pow(ull a, ull b) {
    ull ret = 1;
    
    for (int i = 0; i < b; i++) {
        ret *= a;
    }
    
    return ret;
}

ull dp(ull n, ull r, ull c) {
    ull ret = 0;
    
    ull length = pow(2, n);
    ull size = pow(length, 2) / 4;
    
    while (length >= 2) {
        if (r < length/2) {
            if(c < length/2){
                // 좌상
                ret += 0 * size;
                r = r;
                c = c;
            }
            else{
                // 우상
                ret += 1 * size;
                r = r;
                c = c - length/2;
            }
        }
        else{
            if(c < length/2){
                // 좌하
                ret += 2 * size;
                r = r - length/2;
                c = c;
            }
            else{
                // 우하
                ret += 3 * size;
                r = r - length/2;
                c = c - length/2;
            }
        }
        
        length /= 2;
        size /= 4;
    }
    
    return ret;
}

int main() {
    ull n, r, c;
    
    cin >> n >> r >> c;
    
    cout << dp(n, r, c);
}