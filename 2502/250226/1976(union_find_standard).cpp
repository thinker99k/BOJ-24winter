#include <iostream>
#include <vector>

using namespace std;

int n; // 도시의 수
int m; // 여행경로 상 지나야 할 도시의 수
vector<int> parents(201); // 0~n

vector<int> totravel;

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

bool isSameRoot(int a, int b) {
    return find_set(a) == find_set(b);
}

void solve() {
    for (int i = 0; i < m - 1; i++) {
        if (!isSameRoot(totravel[i], totravel[i + 1])) {
            cout << "NO";
            return;
        }
    }
    
    cout << "YES";
    return;
}

int main() {
    cin >> n;
    cin >> m;
    
    for (int i = 1; i <= n; i++) {
        parents[i] = i;
    }
    
    int x;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> x;
            if (x) {
                union_set(i, j);
            }
        }
    }
    
    totravel.resize(m);
    
    for (int i = 0; i < m; i++) {
        cin >> totravel[i];
    }
    
    solve();
}