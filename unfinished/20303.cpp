#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 1

using namespace std;

int n, m, k;
vector<int> candy(30001);
vector<int> parents(30001);
vector<int> groupcount(30001);


int find_set(int x) {
    if (parents[x] == x) {
        // 부모 = 그 자신 (처음 세팅한것에서 바뀌지 않음)
        return x; // 내가 부모다
    }
    else {
        parents[x] = find_set(parents[x]); // 재귀적으로 탐색
        
        return parents[x]; // 최종적으로 업데이트된 값 반환!
    }
}

void union_set(int a, int b) {
    int roota = find_set(a);
    int rootb = find_set(b);
    
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

int main() {
    cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        cin >> candy[i];
        parents[i] = i;
    }
    
    int x, y;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        union_set(x, y);
        
    }

#if DEBUG
    for (int i = 1; i <= n; i++) {
        cout << parents[i] << " ";
    }
    cout << "\n";
#endif
    
    for (int i = 1; i <= n; i++) {
        groupcount[parents[i]]++;
    }
    
    vector<int> ans;
    bool groupused[30001] = {false,};
    
    for (int i = 1; i <= n; i++) {
        if (groupcount[i]) {
            if(!groupused[i]){

#if DEBUG
                cout << "** " << i << "번 그룹 검색!! **\n";
#endif
                
                int tmp = 0;
                
                for (int j = 1; j <= n; j++) {
                    if (parents[j] == i){

#if DEBUG
                        cout << j << "는 " << i <<"번 그룹!\n";
#endif
                        tmp += candy[j];
                    }
                }
                
                ans.push_back(tmp);

#if DEBUG
                cout << tmp << "\n";
#endif
            }
        }
    }
    
    cout << *max_element(ans.begin(), ans.end());
    
}