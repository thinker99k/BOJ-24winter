#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // n개에서 길이 m만큼

vector<int> v;
vector<int> comb;

bool checked[9];

void backtrack(int level) {
    if (level == m) {
        for (int i = 0; i < m; i++) {
            cout << comb[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            /** 중복 방지
             * 1. i가 1이상일 때
             * 2. 단어의 i번째 문자가 i-1번째 문자와 같은데
             * 3. i-1번째 문자가 아직 사용되었지 않았다 나오면
             *
             * ex. [1, 1, 7]
             * |  1a |  1b |  7  | // checked의 의미 : 해당 원소의 사용여부
             * | [0] | [1] | [2] | // 인덱스
             * |  f  |  f  |  f  | // boolean
             * 1a, 1b, 7 -> ok
             * 1b, 1a, b -> 중복처리 필요
             *
             * 1. 이전 원소와 같은지 살펴봐야 하므로, 인덱스는 무조건 [1] 이상
             * -> 첫 루프는 거르고, 두 번째 루프부터 검사
             * 2. 같은지 살펴봄
             * -> [1] = 1, [0] = 1로 같다
             * 3. 그런데 사용이 안됐다 나왔을 경우
             * -> 여기서 1b, 1a, 7의 전개가 될 가능성이 생김
             * 왜? a1이 사용되지 않았기에, [1]-[0]-[2]의 백트랙 전개
             * 따라서 이 때 continue
             *
             * 참고로 알고리즘의 전제 상 v는 이미 정렬되어 있어야함
             */
            if (i > 0 &&
                v[i] == v[i - 1] &&
                !checked[i - 1]) {
                continue;
            }
            
            if (!checked[i]) {
                comb.push_back(v[i]);
                checked[i] = true;
                
                backtrack(level + 1);
                
                comb.pop_back();
                checked[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    backtrack(0);
}