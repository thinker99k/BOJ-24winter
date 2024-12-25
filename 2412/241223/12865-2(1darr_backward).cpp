#include <iostream>

using namespace std;

int n, k; // k = 최대 무게 합

int w[101];
int v[101];

int arr[101];

/**
 * arr[i] : [i]번째까지 살펴봤을 때 최대 값
 * 원하는 답은 arr[n][k]에 있음
 */

int max(int a, int b) {
    return a > b ? a : b;
}

void dp() {
    /** arr[0][x]는 아무것도 보지 않았기에 당연히 전부 0 */
    
    for (int i = 1; i <= n; i++) {
        // [i]번째까지 살펴봤을 때
        for (int j = 0; j <= k; j++) {
            // 가방총량이 [j]인 경우
            
            int no_input = arr[i - 1][j]; // i-1번째까지 살펴본 최대 값
            
            if (j - w[i] >= 0) {
                // i번째 물건을 넣을 수 있으면
                
                // i번째 물건을 넣기 전 용량
                int prev_capacity = j - w[i];
                
                // i-1번째까지 살펴본 최대 값중에서, i번째 물건을 넣기 전 용량에 해당하는 가치
                int yes_input = arr[i - 1][prev_capacity];
                
                // arr[i][j]는 max(yes_input + i번째 물건의 가치, no_input)
                arr[i][j] = max(yes_input + v[i], no_input);
            }
            else {
                // i번째 물건을 넣지 못한다면, i번째까지 살펴본 값은 i-1번째까지 살펴본 최대 값과 동일
                arr[i][j] = no_input;
            }
        }
    }
}


int main() {
    cin >> n >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> w[i] >> v[i];
    }
    
    dp();
    
    cout << arr[n][k];
    
}