#include <iostream>

using namespace std;

// nCr, idx1 = n, idx2 = r
int pascal[1001][1001];

// x mod 10007 반환
int mod(int x) {
    return x % 10007;
}

int comb(int n, int r) {
    pascal[1][0] = 1;
    pascal[1][1] = 1;
    
    for(int i=2; i<=n; i++){
        for(int j=0; j<=i; j++){
            if (j == 0 || j == i){
                pascal[i][j] = 1;
            }
            else{
                pascal[i][j] = mod(mod(pascal[i-1][j-1]) + mod(pascal[i-1][j]));
            }
        }
    }
    
    return pascal[n][r];
}

int main() {
    int n, r;
    
    cin >> n >> r;
    
    cout << comb(n, r);
}