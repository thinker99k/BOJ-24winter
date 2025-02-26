#include <iostream>
#include <list>
#include <vector>

#define DEBUG 1

#if DEBUG
#include <chrono>
#include <thread>
#endif

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

#if DEBUG
void prn(vector<int> &vec){
    for(auto it: vec){
        cout << it << " ";
    }
    cout << "\n";
}
#endif

int kruskal(){
    vector<int> mst; // int 집어넣음
    int mstdist = 0;
    
    int root = edges.front().start; // 트리의 시작점 : 가장 거리가 짧은 간선의 시작점
    int tail = edges.front().end;
    
    mst.push_back(root);
    mst.push_back(tail);
    
    edges.pop_front();
    
    // 도착점이 root인 모든 간선 제거
    for(auto it = edges.begin(); it != edges.end();){
        if(it->end == root){
            it = edges.erase(it);
        }
        else{
            it = next(it);
        }
    }
    
    while (true){
        tail = mst.back();

#if DEBUG
        cout << "tail : " << tail << "\n";
#endif
        // edges에는 도착점이 root가 아닌 간선만이 있음이 보장됨
        for(auto it = edges.begin(); it != edges.end();){
            if(it->start == tail){
                // 이어질 때
                mst.push_back(it->end);
                mstdist += it->distance;
                edges.erase(it);
                break;
            }
            else{
                ++it;
            }
        }

#if DEBUG
        prn(mst);
        this_thread::sleep_for(chrono::seconds(1));
#endif
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
        
        edges.push_back({c, a, b});
    }
    
    edges.sort();

#if DEBUG
    for(auto it : edges){
        cout << it.start << "->" << it.end << " : " << it.distance << "\n";
    }
#endif
    
    cout << kruskal();
    
}