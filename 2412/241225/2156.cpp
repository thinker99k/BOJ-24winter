#include <iostream>

using namespace std;

int wine[10001];
int sum[10001];

int max(int a, int b) {
    return a > b ? a : b;
}

int threemax(int a, int b, int c) {
    if (a >= b && a >= c) {
        return a;
    }
    else if (b >= a && b >= c) {
        return b;
    }
    else if (c >= a && c >= b) {
        return c;
    }
    else {
        // 실행되면 안됨
        return -1;
    }
}

int dp(int n) {
    sum[1] = wine[1];
    
    sum[2] = wine[1] + wine[2];
    
    int a, b, c;
    
    for (int i = 3; i <= n; i++) {
        
        // i번째를 안먹는 경우
        a = sum[i - 1];
        
        // i-1번째를 안먹는 경우
        b = wine[i] + sum[i - 2];
        
        // i-2번째를 안먹는 경우
        c = wine[i] + wine[i - 1] + sum[i - 3];
        
        sum[i] = threemax(a, b, c);
    }
    
    return sum[n];
}

int main() {
    int n;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    
    cout << dp(n);
}