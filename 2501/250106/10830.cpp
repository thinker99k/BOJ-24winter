#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

ull n, t;

ull matrix[5][5];

ull ans[5][5];

ull mod(ull x) {
    return x % 1000;
}

ull tmp[5][5];
ull tull;

// ans, matrix 곱하여 ans에 저장
void domulti1() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tull = 0;
            
            for(int k=0; k<n; k++){
                tull += matrix[i][k] * ans[k][j];
            }
            
            tmp[i][j] = mod(tull);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i][j] = tmp[i][j];
        }
    }
}

// matrix, matrix 곱하여 matrix에 저장
void domulti2() {
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            tull = 0;
            
            for(int k=0; k<n; k++){
                tull += matrix[i][k] * matrix[k][j];
            }
            
            tmp[i][j] = mod(tull);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matrix[i][j] = tmp[i][j];
        }
    }
}

void multi() {
    ull k = t;
    
    while (k) {
        // k가 홀수일 경우 matrix, ans 곱
        if (k % 2) {
            domulti1();
        }
        
        // matrix 거듭제곱
        domulti2();
        
        k /= 2;
    }
}

int main() {
    cin >> n >> t;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
        ans[i][i] = 1;  // 단위 행렬
    }
    
    multi();
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
}