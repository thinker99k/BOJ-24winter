#include <iostream>

using namespace std;

int arr[1001][10];

int mod(int x) {
    return x % 10007;
}

int dp(int lv) {
    int ret = 0;
    
    for(int i=0; i<10; i++){
        arr[0][i] = 1;
    }
    
    for(int i=1; i<lv; i++){
        for(int j=0; j<10; j++){
            for(int k=j; k<10; k++){
                arr[i][j] += mod(arr[i-1][k]);
                arr[i][j] = mod(arr[i][j]);
            }
        }
    }
    
    for(int i=0; i<10; i++){
        ret += arr[lv-1][i];
        ret = mod(ret);
    }
    
    return mod(ret);
}

int main() {
    int n;
    cin >> n;
    
    cout << dp(n);
}