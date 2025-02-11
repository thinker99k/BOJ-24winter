#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long ull;

ull n, modulo, power;

ull matrix[100][100];
ull ans[100][100];

ull tmp[100][100];
ull tull;

void init() {
    n = 0;
    modulo = 0;
    power = 0;
    
    memset(matrix, 0, sizeof(matrix));
    memset(ans, 0, sizeof(ans));
    
    memset(tmp, 0, sizeof(tmp));
    tull = 0;
}

ull mod(ull x) {
    return x % modulo;
}

// ans, matrix 곱하여 ans에 저장
void domulti1() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tull = 0;
            
            for (int k = 0; k < n; k++) {
                tull += matrix[i][k] * ans[k][j];
            }
            
            tmp[i][j] = mod(tull);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans[i][j] = tmp[i][j];
        }
    }
}

// matrix, matrix 곱하여 matrix에 저장
void domulti2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tull = 0;
            
            for (int k = 0; k < n; k++) {
                tull += matrix[i][k] * matrix[k][j];
            }
            
            tmp[i][j] = mod(tull);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = tmp[i][j];
        }
    }
}

void multi() {
    ull k = power;
    
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

void prn(){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
    
    cout << "\n";
}

int main() {
    while (true) {
        init();
        
        cin >> n >> modulo >> power;
        
        if (!n && !modulo && !power) {
            break;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
            ans[i][i] = 1;
        }
        
        multi();
        
        prn();
    }
}