#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int vectors, root, querys;

vector<int> v[100001];

vector<int> ans;


int bfs(int target) {
    vector<bool> visited(100001, false);
    
    queue<int> q;
    
    q.push(root);
    visited[root] = true;
    
    int pp;
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        if (pp == target) {
            // 타겟을 찾았으면 -> 해당 타겟 거르고 bfs 진행
            // 이렇게 되면, 나중에 visited false인거만 새보면 해당 서브트리
            visited[pp] = false;
            pp = q.front();
            q.pop();
        }
        
        for (int i = 0; i < v[pp].size(); i++) {
            if (!visited[v[pp][i]]) {
                q.push(v[pp][i]);
                visited[v[pp][i]] = true;
            }
        }
    }
    
    int howmanyvisit = (int) count(visited.begin(), visited.end(), true);
    
    return vectors - howmanyvisit;
}

int main() {
    cin >> vectors >> root >> querys;
    
    int a, b;
    for (int i = 1; i <= vectors - 1; i++) {
        cin >> a >> b;
        
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int c;
    for (int i = 0; i < querys; i++) {
        cin >> c;
        
        if(c == root){
            ans.push_back(vectors);
        }
        else{
            ans.push_back(bfs(c));
        }
    }
    
    for (int it: ans) {
        cout << it << "\n";
    }
}