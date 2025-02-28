#include <iostream>
#include <vector>
#include <unordered_set>

#define DEBUG 0

using namespace std;

int find_set(vector<int> &parents, int x) {
    if (parents[x] == x) {
        // 부모 = 그 자신 (처음 세팅한것에서 바뀌지 않음)
        return x; // 내가 부모다
    }
    else {
        parents[x] = find_set(parents, parents[x]); // 재귀적으로 탐색
        
        return parents[x]; // 최종적으로 업데이트된 값 반환!
    }
}

void union_set(vector<int> &parents, int a, int b) {
    int roota = find_set(parents, a);
    int rootb = find_set(parents, b);
    
    // 루트가 같으면 아무것도 안함
    if (roota != rootb) {
        // 루트가 다르면
        if (roota < rootb) {
            parents[rootb] = roota;
        }
        else {
            parents[roota] = rootb;
        }
    }
}

bool isSameRoot(vector<int> &parents, int a, int b) {
    return find_set(parents, a) == find_set(parents, b);
}

int main() {
    int v, e;
    cin >> v >> e;
    
    vector<int> parents(v + 1);
    for (int i = 0; i <= v; i++) {
        parents[i] = i;
    }
    
    int x, y;
    for (int i = 0; i < e; i++) {
        cin >> x >> y;
        
        union_set(parents, x, y);
    }
    
    unordered_set<int> ans;
    for(int i=1; i<=v; i++){
        ans.insert(find_set(parents, i));
    }
    
#if DEBUG
    for (auto it: parents) {
        cout << it << " ";
    }
    cout << "\n";
    
    for (auto it: ans) {
        cout << it << " ";
    }
    cout << "\n";
#endif
    
    cout << ans.size();
}