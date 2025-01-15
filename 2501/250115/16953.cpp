#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

typedef unsigned long long ull;
typedef pair<ull, ull> srch; // 걸린 시간, 현재 위치

ull a, b; // a->b

ull mindist = INF; // k까지 도착했을 때 최소 시간
vector<ull> v; // 각 도착마다 걸린 시간

/** 항상 증가만 하는점을 고려해보면, checked 배열이 필요하지 않음을 알 수 있음 */
void bfs(srch s) {
    if (s.second > b) {  // 범위를 초과한다면 탐색 종료
        return;
    }
    else if (s.second == b) {  // 도착했다면
        if (s.first < mindist) {
            mindist = s.first;
            return;
        }
    }
    else {
        bfs(srch{s.first + 1, s.second * 2});
        bfs(srch{s.first + 1, s.second * 10 + 1});
    }
}

int main() {
    cin >> a >> b;
    
    bfs(srch{1, a});
    
    if (mindist == INF) {  // bfs를 마쳤음에도 최소거리가 갱신이 안되어있다면 도달 불가능한 지점
        cout << -1;
    }
    else {
        cout << mindist;
    }
}