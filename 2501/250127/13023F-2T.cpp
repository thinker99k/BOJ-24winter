#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool tomodachi[2001][2001];

vector<int> comb;

bool checked[2000];

void backtrack(int level, int prev) {
    if (level == 5) {
        cout << 1;
        exit(0);
    }
    else {
        for (int i = 1; i <= n; i++) {
            // 체크되지 않았을 때
            if (!checked[i]) {
                // 이전에 추가된 사람과 친구 관계이면 백트랙 전개
                if(tomodachi[prev][i]){
                    comb.push_back(i);
                    checked[i] = true;
                    
                    backtrack(level + 1, i);
                    
                    comb.pop_back();
                    checked[i] = false;
                }
            }
        }
    }
}

int main() {
    // 가상의 사람 0은 1~2000 모두와 친구!
    for (int i = 0; i <= 2000; i++) {
        tomodachi[0][i] = true;
        tomodachi[i][0] = true;
    }
    
    cin >> n >> m;
    
    int tmp1, tmp2;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        
        tomodachi[tmp1 + 1][tmp2 + 1] = true;
        tomodachi[tmp2 + 1][tmp1 + 1] = true;
    }
    
    backtrack(0, 0);
    
    cout << 0;
}