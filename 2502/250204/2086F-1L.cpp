#include <iostream>
#include <cstring>

#define MOD 1000000000

using namespace std;
typedef unsigned long long ull;

const ull ans_init[2][2] = {
        {1, 0},
        {0, 1}
};

const ull mat_init[2][2] = {
        {1, 1},
        {1, 0}
};


ull ans[2][2];

ull mat[2][2];

ull mod(ull x) {
    return x % MOD;
}

int r, c, rc;
ull t_mat[2][2];
ull t_ull;

// ans *= mat
void power1() {
    // 1. 임시배열 초기화
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            t_mat[r][c] = 0;
        }
    }
    
    // 2. 행렬 곱
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            t_ull = 0;
            
            for (rc = 0; rc < 2; rc++) {
                t_ull += mod(mod(ans[r][rc]) * mod(mat[rc][c]));
            }
            
            t_mat[r][c] = mod(t_ull);
        }
    }
    
    // 3. 실제 배열 저장
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            ans[r][c] = t_mat[r][c];
        }
    }
}

// mat = mat^2;
void power2() {
    // 1. 임시배열 초기화
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            t_mat[r][c] = 0;
        }
    }
    
    // 2. 행렬 곱
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            t_ull = 0;
            
            for (rc = 0; rc < 2; rc++) {
                t_ull += mod(mod(mat[r][rc]) * mod(mat[rc][c]));
            }
            
            t_mat[r][c] = mod(t_ull);
        }
    }
    
    // 3. 실제 배열 저장
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            mat[r][c] = t_mat[r][c];
        }
    }
}

ull fibo(ull n) {
    memcpy(ans, ans_init, sizeof(ull) * 4);
    memcpy(mat, mat_init, sizeof(ull) * 4);
    
    ull k = n;
    
    while (k) {
        // k가 홀수 -> ans *= mat
        if (k % 2) {
            power1();
        }
        
        // mat = mat^2
        power2();
        
        k /= 2;
    }
    
    return mod(ans[1][0]);
}

int main() {
    ull a, b;
    cin >> a >> b;
    
    cout << fibo(b+2) - fibo(a+1);
}