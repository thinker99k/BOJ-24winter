#include <list>
#include <iostream>

using namespace std;

typedef struct __Edge {
    int distance; // 거리를 기준으로 먼저 정렬
    int start;
    int end;
    
    bool operator<(const __Edge &other) const {
        return distance < other.distance;
    }
} Edge;

int main() {
    int v, e;
    list<Edge> edges; // 간선들의 집합
    
    edges.push_back({1, 1, 2});
    edges.push_back({2, 2, 1});
    edges.push_back({3, 3, 1});
    edges.push_back({4, 4, 1});
    edges.push_back({5, 2, 3});
    edges.push_back({6, 3, 3});
    
    int root = 1;
    
    // 도착점이 root인 모든 간선 제거
    for (auto it = edges.begin(); it != edges.end();) {
        if (it->end == root) {
            it = edges.erase(it);
        }
        else {
            it = next(it);
        }
        
    }
    
    for(auto it : edges){
        cout << it.distance << " " << it.start << " " << it.end << "\n";
    }
}