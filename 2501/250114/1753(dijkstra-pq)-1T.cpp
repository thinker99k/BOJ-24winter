#include <iostream>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

int numv, nume;

int vstart;

class Edge {
public :
    int nodename;
    int distance;

public:
    Edge(int n, int d) : nodename(n), distance(d) {};
    
public:
    class EdgeCmp {
    public:
        bool operator ()(const Edge &a, const Edge & b) const {
            if(a.nodename == b.nodename){
                return a.distance > b.distance;
            }
            
            return a.nodename > b.nodename;
        }
    };
};

vector<Edge> graph[20001];
int ans[20001];

void dijkstra() {
    for (int i = 1; i <= numv; i++) {
        ans[i] = INF;
    }
    
    // 시작정점 -> 시작정점 거리 0
    ans[vstart] = 0;
    
    priority_queue<Edge, vector<Edge>, Edge::EdgeCmp> pq;
    
    pq.push(Edge(vstart, 0));
    
    int currv, mindist, currvsz, nextv, nextdist;
    while(!pq.empty()){
        currv = pq.top().nodename;
        mindist = pq.top().distance;
        currvsz = (int) graph[currv].size();
        
        pq.pop();
        
        for(int i=0; i<currvsz; i++){
            nextv = graph[currv][i].nodename;
            nextdist = mindist + graph[currv][i].distance;
            
            if(nextdist < ans[nextv]){
                ans[nextv] = nextdist;
                pq.push(Edge(nextv, ans[nextv]));
            }
        }
    }
}

void print() {
    for (int i = 1; i <= numv; i++) {
        if(ans[i] == INF){
            cout << "INF" << endl;
        }
        else{
            cout << ans[i] << endl;
        }
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
        
        graph[u].push_back(Edge(v, w));
    }
    
    dijkstra();
    
    print();
    
}