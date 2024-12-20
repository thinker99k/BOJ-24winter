#include <iostream>

using namespace std;

int arr[500][500];

// [i][j]의 최대 값
int sum[500][500];

int max(int a, int b){
    return a > b ? a : b;
}

int dp(int n){
    // 삼각형 윗 곡지점 = 자기 자신
    sum[0][0] = arr[0][0];
    
    for(int i=1; i<n; i++){
        // 삼각형 가장 왼쪽의 합 = 바로 위 가장 왼쪽의 합 + 자신
        sum[i][0] = sum[i-1][0] + arr[i][0];
        
        // 삼각형 중간
        for(int j=1; j<i; j++){
            sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + arr[i][j];
        }
        
        // 삼각형 가장 오른쪽
        sum[i][i] = sum[i-1][i-1] + arr[i][i];
    }
    
    
    int ret = 0;
    for(int i=0; i<n; i++){
        ret = sum[n-1][i] > ret ? sum[n-1][i] : ret;
    }
    
    return ret;
}

int main(){
    int n;
    cin >> n;
    
    int tmp;
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            cin >> tmp;
            arr[i][j] = tmp;
        }
    }

    cout << dp(n);
    
}