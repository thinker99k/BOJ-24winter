#include <iostream>
#include <vector>
#include <queue> q;

using namespace std;

int n;

vector<int> v[100001];
bool visited[100001];
int parent[100001];

void bfs() {
    queue<int> q;
    int pp;
    
    pp = 1; // 트리의 루트는 무조건 1, 1의 루트는 없음
    q.push(pp);
    visited[pp] = true;
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        for (int i = 0; i < (int) v[pp].size(); i++) {
            if (!visited[v[pp][i]]) {
                q.push(v[pp][i]); // bfs 탐색
                visited[v[pp][i]] = true;
                parent[v[pp][i]] = pp;
            }
        }
    }
}

int main() {
    cin >> n;
    
    int a, b;
    for (int i = 1; i <= n - 1; i++) {
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    bfs();
    
    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }
}