#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> comb;

void backtrack(int start) {
    // size를 활용하면, dfs 전개시 매개변수 level 필요 없음
    int csz = (int) comb.size();
    
    if (csz == M) {
        for (int i = 0; i < csz; i++) {
            cout << comb[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    for (int i = start; i <= N; i++) {
        comb.push_back(i);
        backtrack(i + 1);
        comb.pop_back();
    }
}

int main() {
    cin >> N >> M;
    
    backtrack(1);
}
