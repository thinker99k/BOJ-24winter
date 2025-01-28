#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

vector<string> anagram;

int bt_idx;
int bt_len;

vector<char> comb;
bool checked[21];

void backtrack(int level) {
    if (level == bt_len) {
        for (int i = 0; i < bt_len; i++) {
            cout << comb[i];
        }
        cout << '\n';
    }
    else {
        for (int i = 0; i < bt_len; i++) {
            /** 중복 방지
             * 1. i가 1이상일 때
             * 2. 단어의 i번째 문자가 i-1번째 문자와 같은데
             * 3. i-1번째 문자가 아직 사용되었지 않았다 나오면
             *
             * ex. "aab"
             * 편의상 첫 번째 a를 a1, 두 번째 a를 a2라 함
             * | a1  | a2  |  b  | // checked의 의미 : 해당 원소의 사용여부
             * | [0] | [1] | [2] | // 인덱스
             * |  f  |  f  |  f  | // boolean
             * a1, a2, b -> ok
             * a2, a1, b -> 중복처리 필요
             *
             * 1. 이전 원소와 같은지 살펴봐야 하므로, 인덱스는 무조건 [1] 이상
             * -> a2부터 검사
             * 2. 같은지 살펴봄
             * -> [1] = 'a', [0] = 'a'로 같다
             * 3. 그런데 사용이 안됐다 나왔을 경우
             * -> 여기서 a2, a1, b의 전개가 될 가능성이 생김
             * 왜? a1이 사용되지 않았기에, [1]-[0]-[2]의 백트랙 전개
             * 따라서 이 때 continue
             *
             * 참고로 알고리즘의 전제 상 모든 단어는 이미 정렬되어 있어야함
             * main()의 sort()에서 실행, anagram의 string은 모두 정렬되어있음
             */
            if (i > 0 &&
                anagram[bt_idx][i] == anagram[bt_idx][i - 1] &&
                !checked[i - 1]) {
                continue;
            }
            
            if (!checked[i]) {
                comb.push_back(anagram[bt_idx][i]);
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
    
    int n;
    cin >> n;
    
    char buf[21];
    
    for (int i = 0; i < n; i++) {
        memset(buf, 0, 21);
        
        cin >> buf;
        
        sort(buf, buf + strlen(buf));
        
        anagram.push_back(string(buf));
    }
    
    for (int i = 0; i < n; i++) {
        comb.clear();
        memset(checked, 0, 21);
        
        bt_idx = i;
        bt_len = (int) anagram[i].size();
        
        backtrack(0);
    }
}