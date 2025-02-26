#include <iostream>
#include <list>
#include <vector>

using namespace std;

typedef struct __Edge{
    int distance; // 거리를 기준으로 먼저 정렬
    int start;
    int end;
    
    bool operator<(const __Edge &other) const {
        return distance < other.distance;
    }
} Edge;

int v, e;
list<Edge> edges; // 간선들의 집합

int kruskal(){
    vector<int> mst; // int 집어넣음
    int mstdist = 0;
    
    int root = edges.front().start; // 트리의 시작점 : 가장 거리가 짧은 간선의 시작점
    mst.push_back(root);
    edges.pop_front();
    
    for(auto it : edges){
    
    }
    
    int tail;
    while (true){
        tail = mst.back();
        
        for(auto it = edges.begin(); it != edges.end();){
            auto ee = *it;
            
            if(ee.end == root){ // 사이클 생기는 경우
                it = next(it);
                continue;
            }
            
            if(ee.start == tail){
                if(ee.end == root){
                    // 사이클 생기는 경우
                    ++it;
                }
                else{
                    mstdist += ee.distance;
                    mst.push_back(ee.end);
                    edges.erase(it);
                    break;
                }
            }
        }
        
        if(mst.size() == v){
            break;
        }
    }
    
    return mstdist;
}

int main(){
    cin >> v >> e;
    
    
    int a, b, c;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        
        edges.push_back({a, b, c});
    }
    
    edges.sort();
    
    cout << kruskal();
    
}