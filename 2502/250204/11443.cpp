#include <iostream>
#include <cstring>

#define MOD 1000000007

using namespace std;
typedef long long ll;

const ll ans_init[2][2] = {
        {1, 0},
        {0, 1}
};

const ll mat_init[2][2] = {
        {1, 1},
        {1, 0}
};


ll ans[2][2];

ll mat[2][2];

ll mod(ll x) {
    return x % MOD;
}

int r, c, rc;
ll t_mat[2][2];
ll t_ll;

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
            t_ll = 0;
            
            for (rc = 0; rc < 2; rc++) {
                t_ll += mod(ans[r][rc] * mat[rc][c]);
            }
            
            t_mat[r][c] = mod(t_ll);
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
            t_ll = 0;
            
            for (rc = 0; rc < 2; rc++) {
                t_ll += mod(mat[r][rc] * mat[rc][c]);
            }
            
            t_mat[r][c] = mod(t_ll);
        }
    }
    
    // 3. 실제 배열 저장
    for (r = 0; r < 2; r++) {
        for (c = 0; c < 2; c++) {
            mat[r][c] = t_mat[r][c];
        }
    }
}

ll fibo(ll n) {
    memcpy(ans, ans_init, sizeof(ll) * 4);
    memcpy(mat, mat_init, sizeof(ll) * 4);
    
    ll k = n;
    
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
    ll n, ret;
    cin >> n;
    
    ret = n % 2 ? fibo(n) - 1 : fibo(n + 1) - 1;
    
    cout << ret;
}