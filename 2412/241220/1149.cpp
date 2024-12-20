#include <iostream>

using namespace std;

int rgb[1000][3];
int sum[1000][3];

int min(int a, int b){
    return a < b ? a : b;
}

int dp(int n){
    for(int i=0; i<3; i++){
        sum[0][i] = rgb[0][i];
    }
    
    for(int i=1; i<n; i++){
        sum[i][0] = min(sum[i-1][1], sum[i-1][2]) + rgb[i][0];
        sum[i][1] = min(sum[i-1][0], sum[i-1][2]) + rgb[i][1];
        sum[i][2] = min(sum[i-1][0], sum[i-1][1]) + rgb[i][2];
    }
    
    int ret = 0x7fffffff; // int의 최대 값;
    
    for(int i=0; i<3; i++){
        ret = sum[n-1][i] < ret ? sum[n-1][i] : ret;
    }
    
    return ret;
}

int main(){
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++){
            cin >> rgb[i][j];
        }
    }
    
    cout << dp(n);
}