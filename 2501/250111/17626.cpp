#include <iostream>

// sq(50000) = 223.6
#define MAX 225

using namespace std;

long long square1[MAX+1];
long long square2[MAX+1][MAX+1];
long long square3[MAX+1][MAX+1][MAX+1];

int n, i, j, k;

int dp();

int dp1();

int dp2();

int dp3();

int main() {
    cin >> n;
    
    cout << dp();
}

int dp() {
    for (i = 1; i <= MAX; i++) {
        square1[i] = i * i;
    }
    
    for (i = 1; i <= MAX; i++) {
        for (j = 1; j <= MAX; j++) {
            square2[i][j] = square1[i] + square1[j];
        }
    }
    
    for (i = 1; i <= MAX; i++) {
        for (j = 1; j <= MAX; j++) {
            for (k = 1; k <= MAX; k++) {
                square3[i][j][k] = square1[i] + square2[j][k];
            }
        }
    }
    
    return dp1();
}


int dp1() {
    for (i = 1; i <= MAX; i++) {
        if (square1[i] == n) {
            return 1;
        }
    }
    
    return dp2();
}

int dp2() {
    for (i = 1; i <= MAX; i++) {
        for (j = 1; j <= MAX; j++) {
            if (square2[i][j] == n) {
                return 2;
            }
        }
    }
    
    return dp3();
}

int dp3() {
    for (i = 1; i <= MAX; i++) {
        for (j = 1; j <= MAX; j++) {
            for (k = 1; k <= MAX; k++) {
                if (square3[i][j][k] == n) {
                    return 3;
                }
            }
        }
    }
    
    return 4;
}
