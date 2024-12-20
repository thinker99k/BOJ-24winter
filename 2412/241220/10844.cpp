#include <iostream>

using namespace std;

// [*][0] 미사용
long long arr[10][101];
// 첫 번째 인덱스 : 0~9
// 두 번째 인덱스 : marge pass

long long mod(long long x){
    return x % 1000000000;
}

long long dp(int n){
    long long ret = 0;
    
    // 1. init
    arr[0][1] = 0;
    for(int i=1; i<10; i++){
        arr[i][1] = 1;
    }
    
    // 2. marge
    for(int i=2; i<=n; i++){
        arr[0][i] = mod(arr[1][i-1]);
        
        for(int j=1; j<=8; j++){
            arr[j][i] = mod(mod(arr[j-1][i-1]) + mod(arr[j+1][i-1]));
        }
        
        arr[9][i] = mod(arr[8][i-1]);
    }
    
    
    // 3. sum
    for(int i=0; i<10; i++){
        ret += arr[i][n];
    }
    ret = mod(ret);
    
    return ret;
}

int main(){
    int n;
    cin >> n;
    
    long long ans = dp(n);
    
    cout << ans;
}