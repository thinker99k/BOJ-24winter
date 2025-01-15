#include <iostream>
#include <vector>
#include <queue>

#define INF -987654321

using namespace std;

/**
 * distance, nodename
 * std::greater를 pair에 적용할 경우
 * 먼저 첫 번째 원소를 비교, 첫번째 원소가 같으면 두 번째 원소를 비교
 * 거리를 기준으로 다익스트라를 전개해 나가야 하기에, 직관적이지 못하게도 첫 번째 원소에 거리
*/
typedef pair<int, int> Edge;

int numv, nume;
int vstart;

vector<Edge> graph[20001]; // map으로 바꾸면 시간 개선 가능
int ans[20001];


void dijkstra(){
    for(int i=1; i<=numv; i++){
        ans[i] = INF;
    }
    
    // 시작정점 -> 시작정점 거리 0
    ans[vstart] = 0;
    
    // 지금까지 진행된 거리, 탐색할 노드가 저장될 우선순위 큐
    priority_queue<Edge> pq;
    
    pq.push({0, vstart});
    
    int currv, mindist, currvsz, nextv, nextdist;
    
    while(!pq.empty()){
        currv = pq.top().second;
        mindist = pq.top().first;
        
        /** 거리를 기준으로 가장 짧은 원소가 pop되기에, 한 간선에 여러 거리가 있어도 가장 낮은 거리가 pop됨이 보장됨 */
        pq.pop();
        
        currvsz = (int) graph[currv].size();
        
        for(int i=0; i<currvsz; i++){
            // 다음 정점 후보는 현 정점에서 간선으로 이어진 정점
            nextv = graph[currv][i].second;
            // 다음 정점까지 최소거리 후보는 현재까지 진행된 거리(시작점으로부터의 거리) + 다음 정점까지 거리
            nextdist = mindist + graph[currv][i].first;
            
            // 알려진 거리보다 짧을 경우
            if(nextdist > ans[nextv]){
                ans[nextv] = nextdist;
                pq.push(Edge(ans[nextv], nextv));
            }
        }
    }
}

void print() {
    for (int i = 1; i <= numv; i++) {
        if(ans[i] == INF){
            cout << "INF";
        }
        else{
            cout << -1 * ans[i];
        }
        
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> numv >> nume;
    cin >> vstart;
    
    int u, v, w;
    
    for (int i = 0; i < nume; i++) {
        cin >> u >> v >> w;
        
        graph[u].push_back({-1 * w, v});
    }
    
    dijkstra();
    
    print();
    
}