#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> tomodachi[2000];

vector<int> comb;

bool checked[2000];

void backtrack(int level, int cursearchv) {
    if (level == 5) {
        cout << 1;
        exit(0);
    }
    else {
        // 한 깊이 당 벡터의 사이즈만큼 탐색
        int sz = (int) tomodachi[cursearchv].size();
        int next;
        
        for (int i = 0; i < sz; i++) {
            next = tomodachi[cursearchv][i];
            if (!checked[next]) {
                comb.push_back(next);
                checked[next] = true;
                
                backtrack(level + 1, next);
                
                comb.pop_back();
                checked[next] = false;
                
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    int tmp1, tmp2;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        
        tomodachi[tmp1].push_back(tmp2);
        tomodachi[tmp2].push_back(tmp1);
    }
    
    for (int i = 0; i < n; i++) {
        backtrack(0, i);
    }
    
    cout << 0;
}