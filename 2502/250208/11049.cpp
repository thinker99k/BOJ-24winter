#include <iostream>
#include <vector>

#define DEBUG 0

using namespace std;

typedef unsigned long long ull;

typedef struct {
    ull row;
    ull col;
} Size;

int t;

vector<Size> matrixes;  // 원소 t개

ull ans[501][501];

void dp() {
    int distance_max = t - 1;
    ull tmpcost;
    
    for (int distance = 1; distance <= distance_max; distance++) {
        for (int start = 0; start + distance <= distance_max; start++) {
            int dest = start + distance;
            ull min = 0xFFFFFFFFFFFFFFFF;
            
            for (int k = start; k < dest; k++) {
                /**
                 * 임시비용
                 * = start ~ k까지 가는 비용 + k+1 ~ dest까지 가는 비용 + 합치는 비용
                 *
                 * 합치는 비용
                 * start ~ k의 최종 사이즈 : start.row * k.col
                 * k + 1 ~ end의 최종사이즈 : k+1.row * dest.col
                 * 이 때 k+1.row = k.col임
                 *
                 * 따라서 합치는 비용은 start.row * k.col * dest.col
                 */
                tmpcost = ans[start][k] + ans[k + 1][dest]
                          + matrixes[start].row * matrixes[k].col * matrixes[dest].col;
                
                if (tmpcost < min) {
                    min = tmpcost;
                }
            }
            
            ans[start][dest] = min;
        }
    }
}

int main() {
    cin >> t;
    
    ull n, m;
    
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        
        matrixes.push_back({n, m});
    }
    
    dp();

#if DEBUG
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            cout.width(4);
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
#endif
    
    cout << ans[0][t - 1] << "\n";
}