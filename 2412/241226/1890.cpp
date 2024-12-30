#include <iostream>

using namespace std;

typedef unsigned long long ull;

int n;
int arr[100][100];
ull sum[100][100];

void dp() {
    sum[0][0] = 1;
    
    int distance;
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            distance = arr[row][col];
            
            if(!distance){
                continue;
            }
            else{
                if(row + distance < n){
                    sum[row+distance][col] += sum[row][col];
                }
                if(col + distance < n){
                    sum[row][col+distance] += sum[row][col];
                }
            }
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp();
    
    cout << sum[n-1][n-1] << endl;
}