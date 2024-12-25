#include <iostream>

using namespace std;

int arr[1000][1000];
int sum[1000][1000];

int threemax(int a, int b, int c){
    if(a >= b && a >= c){
        return a;
    }
    else if(b >= a && b >= c){
        return b;
    }
    else if(c >= a && c >= b){
        return c;
    }
    else{
        // 실행되면 안됨
        return -1;
    }
}

int dp(int r, int c){
    // 시작점 (0,0)으로 정해짐, 무조건 먹게 됨
    sum[0][0] = arr[0][0];
    
    // [0][x]는 무조건 오른쪽으로만 이동해야만 도달 가능
    for(int j=1; j<c; j++){
        sum[0][j] = sum[0][j-1] + arr[0][j];
    }
    
    // [x][0]은 무조건 아래로 이동해야만 도달 가능
    for(int i=1; i<r; i++){
        sum[i][0] = sum[i-1][0] + arr[i][0];
    }
    
    for(int i=1; i<r; i++){
        for(int j=1; j<c; j++) {
            sum[i][j] = threemax(sum[i-1][j], sum[i-1][j-1], sum[i][j-1]) + arr[i][j];
        }
    }
    
    return sum[r-1][c-1];
}

int main(){
    int row, col;
    
    cin >> row >> col;
    
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            cin >> arr[i][j];
        }
    }
    
    cout << dp(row, col);
}