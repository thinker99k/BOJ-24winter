#include <iostream>
#include <vector>
#include <queue> q;

using namespace std;

int n;

vector<int> v[200001];
int color[200001]; // 원하는 색
int canvas[200001]; // 칠할 도화지

long long ans;

// s를 루트로 하는 서브트리 전체 색칠
void paint(int s, int c) { // start, color
    queue<int> q;
    int pp;
    
    pp = s;
    q.push(pp);
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        canvas[pp] = c; // canvas에 색칠
        
        for(auto it : v[pp]){
            q.push(it); // bfs 탐색
        }
    }
}

void bfs() {
    queue<int> q;
    int pp;
    
    pp = 1; // 트리의 루트는 무조건 1, 1의 루트는 없음
    q.push(pp);
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        if(color[pp] != canvas[pp]) {
            // 원하는 색과 지금 실제로 칠해진 색이 다르면
            paint(pp, color[pp]); // 색칠
            ans++;
        }
        
        for(auto it : v[pp]){
            q.push(it);
        }
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> color[i];
    }
    
    int a, b;
    for (int i = 1; i <= n - 1; i++) { // 트리 edge의 갯수는 vertex - 1개
        cin >> a >> b;
        
        v[a].push_back(b);
    }
    
    bfs();
    
    cout << ans;
}