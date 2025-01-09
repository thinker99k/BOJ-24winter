#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int nextnode; // 다음 목적지
    int distance; // 까지의 거리
} Edge;

typedef struct {
    int nodename; //
    int distsum;  // 이동한 거리의 총합
} Move;

vector<Edge> v[10001];
bool visited[10001];
int t;

// bfs가 더이상 탐색을 못하는 경우인지
bool isLeaf(int x) {
    int vsz = (int) v[x].size();
    
    int nextv;
    for (int i = 0; i < vsz; i++) {
        nextv = v[x][i].nextnode;
        
        // 하나라도 아직 안 방문한 정점이 있으면 false 반환
        if(!visited[nextv]){
            return false;
        }
    }
    
    return true;
}

int bfs(int start) {
    int ret = 0;
    
    queue<Move> q;
    
    Move pp;
    int currv, currvsz, nextv, nextdist;
    
    q.push({start, 0});
    visited[start] = true;
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        currv = pp.nodename;
        currvsz = (int) v[pp.nodename].size();
        
        // 더이상 탐색 할 정점이 없을 경우
        if (isLeaf(currv)) {
            if (pp.distsum > ret) {
                ret = pp.distsum;
            }
        }
        else {
            for (int i = 0; i < currvsz; i++) {
                nextv = v[currv][i].nextnode;
                nextdist = v[currv][i].distance;
                
                // nextv가 탐색하지 않은 정점일 경우
                if (!visited[nextv]) {
                    q.push({nextv, pp.distsum + nextdist});
                    visited[nextv] = true;
                }
            }
        }
    }
    
    return ret;
}

int main() {
    cin >> t;
    
    int i, parent, child, distance;
    for (i = 1; i < t; i++) {
        cin >> parent >> child >> distance;
        
        v[parent].push_back({child, distance});
        v[child].push_back({parent, distance});
    }
    
    int ans = 0, ret;
    
    for (i = 1; i <= t; i++) {
        // 각 bfs의 결과를 확인해야 하기에, 매 bfs마다 visited 초기화
        memset(visited, false, t + 1);
        
        ret = bfs(i);
        
        if (ret > ans) {
            ans = ret;
        }
    }
    
    cout << ans;
}