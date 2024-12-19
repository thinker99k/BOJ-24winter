#include <iostream>

using namespace std;

/** 결국 피보나치가 나오는데?????? */

int arr[1001];

// x mod 10007 반환
int mod(int x) {
    return x % 10007;
}

int fibo(int x){
    for(int i=2; i<=x; i++){
        arr[i] = mod(arr[i-1]) + mod(arr[i-2]);
        arr[i] = mod(arr[i]);
    }
    
    return arr[x];
}

int main() {
    // 2 * n 사이즈
    int n;
    cin >> n;
    
    arr[0] = 0;
    arr[1] = 1;
    
    cout << fibo(n+1);
}