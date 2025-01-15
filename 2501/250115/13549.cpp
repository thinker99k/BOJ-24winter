#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define INF 987654321

using namespace std;

typedef pair<int, int> srch; // 걸린 시간, 현재 위치

int n, k;

bool visited[100001];

int mindist; // k까지 도착했을 때 최소 시간
vector<int> v; // 각 도착마다 걸린 시간

bool val(int pos) {
    // 1. 범위 맞나 검사
    if (pos < 0 || pos >= 100001) {
        return false;
    }
    // 2. 방문 했나 검사
    if (visited[pos]) {
        return false;
    }
    
    return true;
}

void bfs() {
    queue<srch> q;
    
    // 시작 점 큐에 푸시
    q.push(make_pair(0, n));
    
    mindist = INF;  // 최소 시간 일단은 INF로 설정
    int loops = 1;  // 한 while문당 탐색 횟수, 가장 처음에는 n만 푸시했기에 1
    
    int position, distance;
    while (!q.empty()) {
        int nextloops = 0;
        
        for (int i = 0; i < loops; i++) {
            position = q.front().second;
            distance = q.front().first;
            q.pop();
            
            visited[position] = true;
            
            
            if (position == k) { // 목적지에 도착한 경우 큐에 삽입이 없어야함
                if (distance < mindist) {
                    // 최소 값 갱신
                    mindist = distance;
                }
            }
            else { // 목적지에 아직 도착하지 못한 경우에만 큐에 삽입
                // +1 이동 : 1초
                if (val(position + 1)) {
                    q.push(make_pair(distance + 1, position + 1));
                    nextloops++;
                }
                
                // -1 이동 : 1초
                if (val(position - 1)) {
                    q.push(make_pair(distance + 1, position - 1));
                    nextloops++;
                }
                
                // *2 이동 : 0초
                if (val(position * 2)) {
                    q.push(make_pair(distance, position * 2));
                    nextloops++;
                }
            }
        }
        
        // 한 탐색에서 큐가 비어있지 않다고 탐색 칠렐레 팔렐레 도는거 방지
        loops = nextloops;
    }
}

int main() {
    cin >> n >> k;
    
    bfs();
    
    cout << mindist;
}