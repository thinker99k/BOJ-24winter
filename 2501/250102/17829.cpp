#include <iostream>
#include <algorithm>

using namespace std;

int n;

int arr[1024][1024];

void show(int border){
    printf("====== border length : %d ======\n", border);
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("%4d", arr[i][j]);
        }
        printf("\n");
    }
    
    printf("================================\n");
}

int tfarr[4];

void twofour(int row, int col, int offset) {
    int* addr[4] = {
            &arr[row][col],
            &arr[row][col+offset],
            &arr[row+offset][col],
            &arr[row+offset][col+offset]
    };
    
    for(int i=0; i<4; i++){
        tfarr[i] = *addr[i];
    }
    
    sort(tfarr, tfarr+4);
    int z = tfarr[2];
    
    for(int i=row; i<row+offset*2; i++){
        for(int j=col;j<col+offset*2; j++){
            arr[i][j] = z;
        }
    }
}

void dp(int border) {
    if (border > n) {
        return;
    }
    
    int r, c, z;
    int offset = border / 2;
    
    for (int i = 0; i < n; i += border) {
        for (int j = 0; j < n; j += border) {
            twofour(i, j, offset);
        }
    }
    
    //show(border);
    
    dp(border * 2);
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp(2);
    
    cout << arr[0][0];
}