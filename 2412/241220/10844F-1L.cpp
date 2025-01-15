#include <iostream>

using namespace std;

// [*][0] 미사용
int arr[10][101];
// 첫 번째 인덱스 : 0~9
// 두 번째 인덱스 : marge 횟수

int mod(int x){
    return x % 1000000000;
}

int dp(int n){
    int ret = 0;
    
    // 1. init
    arr[0][1] = 0;
    for(int i=1; i<10; i++){
        arr[i][1] = 1;
    }
    
    // 2. marge
    for(int i=2; i<=n; i++){
        arr[0][i] = mod(arr[1][i-1]);
        arr[0][i] = mod(arr[0][i]);
        
        for(int j=1; j<=8; j++){
            arr[j][i] = mod(arr[j-1][i-1]) + mod(arr[j+1][i-1]);
            arr[j][i] = mod(arr[j][i]);
        }
        
        arr[9][i] = mod(arr[8][i-1]);
        arr[9][i] = mod(arr[9][i]);
    }
    
    
    // 3. sum
    for(int i=0; i<10; i++){
        ret += mod(arr[i][n]);
    }
    ret = mod(ret);
    
    return ret;
}

int main(){
    int n;
    cin >> n;
    
    cout << dp(n);
}