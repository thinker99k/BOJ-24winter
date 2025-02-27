#include <iostream>
#include <vector>

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

int main(){
    int t, v, e, q;
    int x, y;
    
    cin >> t;
    
    vector<bool> ans[t];
    
    for(int i=0; i<t; i++){
        cin >> v;
        cin >> e;
        
        vector<int> vec(v);
        for(int j=0; j<v; j++){
            vec[j] = j;
        }
        
        for(int j=0; j<e; j++){
            cin >> x >> y;
            union_set(vec, x, y);
        }
        
        cin >> q;
        for(int j=0; j<q; j++){
            cin >> x >> y;
            ans[i].push_back(isSameRoot(vec, x, y));
        }
    }
    
    for(int i=0; i<t; i++){
        cout << "Scenario " << i+1 << ":\n";
        
        for(bool it : ans[i]){
            cout << it << "\n";
        }
        
        cout << "\n";
    }
}