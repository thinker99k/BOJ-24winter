#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

typedef struct {
    ull row;
    ull col;
} Size;

/** t개의 행렬 -> t-1번의 연산 */
ull t;

vector<Size> matrixes;  // 원소 t개
vector<ull> lengths;    // 원소 t+1개

ull dp() {
    ull ans = 0;
    
    int lsz;
    ull min;
    int minidx;
    
    ull mincandidate;
    
    // tt는 연산의 횟수
    for (int tt = 1; tt <= t - 1; tt++) {
        lsz = (int) lengths.size();
        min = 0xFFFFFFFFFFFFFFFE;
        minidx = -1;
        
        // minidx 선택
        for (int lidx = 1; lidx <= lsz - 2; lidx++) {
            mincandidate = lengths[lidx-1] * lengths[lidx] * lengths[lidx+1];
            
            if (mincandidate < min) {
                min = mincandidate;
                minidx = lidx;
            }
        }
        
        ans += min;
        lengths.erase(lengths.begin() + minidx);
    }
    
    return ans;
}

int main() {
    cin >> t;
    
    ull n, m;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        
        matrixes.push_back({n, m});
    }
    
    lengths.push_back(matrixes.front().row);
    for (int i = 0; i < t; i++) {
        lengths.push_back(matrixes[i].col);
    }
    
    cout << dp();
}