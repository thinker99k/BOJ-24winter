#include <iostream>

using namespace std;

int mod(int x){
    return x % 10007;
}

int dp(int lv, int start) {
    int ret = 0;
    
    if (lv == 1) {
        for (int i = start; i < 10; i++) {
            ret += 1;
        }
    }
    else {
        for (int i = start; i < 10; i++) {
            ret += mod(dp(lv - 1, i));
        }
    }
    
    return mod(ret);
}

int main() {
    int n;
    cin >> n;
    
    cout << dp(n, 0);
}