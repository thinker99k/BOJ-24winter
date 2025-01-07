#include <iostream>

using namespace std;

int n; // n = 3^k, 1<=k<=8

// 3^8 = 6561
bool arr[6561][6561]; // 별 출력 안해야 하면 1
bool checked[6561][6561];

void print();

void dp() {
    int offset = 3;
    int rs, re, cs, ce;
    
    while (offset <= n) {
        // printf("==== offset : %d ====\n", offset);
        
        for (int i = 0; i < n; i += offset) {
            for (int j = 0; j < n; j += offset) {
                // printf("searching (%d, %d)\n", i, j);
                
                rs = i + (offset / 3) * 1;
                re = rs + (offset / 3);
                cs = j + (offset / 3) * 1;
                ce = cs + (offset / 3);
                
                // printf("emptying (%d, %d) <= (x, y) < (%d, %d)\n", rs, cs, re, ce);
                
                for (int ii = rs; ii < re; ii++) {
                    for (int jj = cs; jj < ce; jj++) {
                        arr[ii][jj] = true;
                    }
                }
            }
        }
        
        // print();
        
        offset *= 3;
    }
}

void print() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 별 츌력 해야 하면
            if (!arr[i][j]) {
                printf("*");
            }
                // 별 출력 안해야 하면
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
}


int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    scanf("%d", &n);
    
    dp();
    
    print();
}