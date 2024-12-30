#include <iostream>

using namespace std;

typedef unsigned long long ull;

int arr[31][31];

void pascal() {
    arr[0][0] = 1;
    arr[1][0] = 1;
    arr[1][1] = 1;
    
    for (int i = 2; i <= 30; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                arr[i][j] = 1;
            }
            else {
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            }
        }
    }
}

ull tri(int r, int c, int w) {
    ull ret = 0;
    
    int rr = r - 1, cc = c - 1;
    
    int columns = 1;
    for (int i = rr; i < rr + w; i++) {
        for (int j = cc; j < cc + columns; j++) {
            // cout << "(" << i << ", " << j << ")" << " = " << arr[i][j] << endl;
            ret += arr[i][j];
        }
        columns++;
    }
    
    return ret;
}

int main() {
    pascal();
    
    int r, c, w;
    
    cin >> r >> c >> w;
    
    cout << tri(r, c, w);
}