#include <iostream>

#define DEBUG 0
#define INF 987654321

using namespace std;

long long dist[1001][1001];
long long ans[1001];
bool visited[1001];

int numv, nume;
int startv, endv;

void print();

void init() {
    for (int i = 0; i <= 1000; i++) {
        for (int j = 0; j <= 1000; j++) {
            dist[i][j] = INF;
        }
        ans[i] = INF;
        dist[i][i] = 0;
    }
}

void dijkstra() {
    for (int i = 1; i <= numv; i++) {
        ans[i] = dist[startv][i];
    }
    // 출발 정점은 거리 0
    ans[startv] = 0;
    
    int current; // 이번 loop에 탐색 할 노드
    long long mindist;
    while (true) {
        current = -1;
        mindist = INF;
        
        // 이번 loop에 탐색할 노드 정함 - 우선순위 큐로 개선 가능
        for (int j = 1; j <= numv; j++) {
            /** 조건
             * 1. 아직 방문하지 않았어야함
             * 2. 거리가 INF가 아니어야함 (간선이 존재 함), 최소 거리 갱신 (노드 결정)
             */
            if (!visited[j] && ans[j] < mindist) {
                mindist = ans[j];
                current = j;
            }
        }
        
        // 더이상 탐색할 정점이 없는 경우
        if (current == -1) {
            break;
        }

#if DEBUG
        cout << "current searching " << current << endl;
#endif
        
        visited[current] = true;
        
        // current로부터 간선으로 연결된 정점들 거리 갱신
        for (int j = 1; j <= numv; j++) {
            // 정점 j가 아직 탐색이 안됐을 경우
            if (!visited[j]) {
                // j의 현재 거리와, startv->current->j의 거리를 비교
                if (ans[current] + dist[current][j] < ans[j]) {
#if DEBUG
                    cout << "fixing " << j << " from " << ans[j] << " to " << ans[current] + dist[current][j] << endl;
#endif
                    ans[j] = ans[current] + dist[current][j];
                }
            }
        }

#if DEBUG
        print();
#endif
    }
}

void print() {
    for (int i = 1; i <= numv; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

int main() {
    init();
    
    cin >> numv >> nume;
    
    long long s, e, d, prevd;
    for (int i = 0; i < nume; i++) {
        cin >> s >> e >> d;
        prevd = dist[s][e];
        
        // 새로 들어온 길이가 더 짧으면 dist[][] 갱신
        if (d < prevd) {
            /** 방향성 존재 !!!!! */
            dist[s][e] = d;
        }
        
    }
    
    cin >> startv >> endv;
    
    dijkstra();
    
    cout << ans[endv];
}