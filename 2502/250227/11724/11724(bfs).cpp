#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int V, E;
vector<int> Vertex[1001];
bool visited[1001];
bool checked[1001];

bool val(int x) {
    if (x < 1 || x > 1000) {
        return false;
    }
    
    if (visited[x]) {
        return false;
    }
    
    if (checked[x]) {
        return false;
    }
    
    return true;
}

bool bfs(int s) {
    if (!val(s)) {
        return false;
    }
    
    queue<int> q;
    q.push(s);
    checked[s] = true;
    
    while (true) {
        size_t sz = q.size();
        
        for (int z = 0; z < sz; z++) {
            int p = q.front();
            q.pop();
            
            checked[p] = true;
            
            int k;
            for (int i = 0; i < Vertex[p].size(); i++) {
                k = Vertex[p][i];
                if (val(k)) {
                    q.push(k);
                    checked[k] = true;
                }
            }
        }
        
        if (q.empty()) break;
    }
    
    return true;
}

int main() {
    cin >> V >> E;
    
    int tmp1, tmp2;
    for (int i = 0; i < E; i++) {
        cin >> tmp1 >> tmp2;
        
        Vertex[tmp1].push_back(tmp2);
        Vertex[tmp2].push_back(tmp1);
    }
    
    for (int i = 1; i <= V; i++) {
        sort(Vertex[i].begin(), Vertex[i].end());
    }
    
    int ans = 0;
    
    for (int i = 1; i <= V; i++) {
        if (bfs(i)) {
            ans++;
        }
    }
    
    cout << ans;
    
}