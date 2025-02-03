#include <iostream>
#include <vector>
#include <cstring>

#define MOD 10000

using namespace std;
typedef unsigned long long ull;

vector<ull> v;

// 단위 행렬
ull ans_init[2][2] = {
        {1, 0},
        {0, 1}
};

ull mat_init[2][2] = {
        {1, 1},
        {1, 0}
};

// 단위 행렬
ull ans[2][2];

ull mat[2][2];

ull mod(ull x){
    return x % MOD;
}

int r, c, rc;
ull t_mat[2][2];
ull t_ull;

// ans *= matrix
void power1() {
    for(r=0; r<2; r++){
        for(c=0; c<2; c++){
            t_mat[r][c] = 0;
        }
    }
    
    for(r=0; r<2; r++){
        for(c=0; c<2; c++){
            t_ull = 0;
            
            for(rc=0; rc<2; rc++){
                t_ull += ans[r][rc] * mat[rc][c];
            }
            
            t_mat[r][c] = mod(t_ull);
        }
    }
    
    for(r=0; r<2; r++){
        for(c=0; c<2; c++){
            ans[r][c] = t_mat[r][c];
        }
    }
}

// matrix = matrix^2
void power2() {
    for(r=0; r<2; r++){
        for(c=0; c<2; c++){
            t_mat[r][c] = 0;
        }
    }
    
    for(r=0; r<2; r++){
        for(c=0; c<2; c++){
            t_ull = 0;
            
            for(rc=0; rc<2; rc++){
                t_ull += mod(mod(mat[r][rc]) * mod(mat[rc][c]));
            }
            
            t_mat[r][c] = mod(t_ull);
        }
    }
    
    for(r=0; r<2; r++){
        for(c=0; c<2; c++){
            mat[r][c] = t_mat[r][c];
        }
    }
}

ull fibo(ull n) {
    memcpy(ans, ans_init, sizeof(ull) * 4);
    memcpy(mat, mat_init, sizeof(ull) * 4);
    
    ull k = n;
    
    while (k) {
        // k가 홀수 -> ans *= matrix
        if (k % 2) {
            power1();
        }
        
        // matrix = matrix^2
        power2();
        
        k /= 2;
    }
    
    return ans[1][0];
}

int main() {
    ull n;
    
    while (true){
        cin >> n;
        
        if(n == -1){
            break;
        }
        
        v.push_back(fibo(n));
    }
    
    for(ull it : v){
        cout << it << "\n";
    }
}