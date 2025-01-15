#include <iostream>
#include <queue>
#include <vector>

#define INF 987654321

using namespace std;

int n, k;

bool arr[100001];
bool visited[100001];
int steps[100001];

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
    queue<int> q;
    
    // 시작 점 큐에 푸시
    q.push(n);
    
    mindist = INF;  // 최소 시간 일단은 INF로 설정
    int phase = 0;  // 걸린 시간
    int loops = 1;  // 한 while문당 탐색 횟수, 가장 처음에는 n만 푸시했기에 1
    
    while (!q.empty()) {
        int nextloops = 0;
        
        for (int i = 0; i < loops; i++) {
            int pp = q.front();
            q.pop();
            visited[pp] = true;
            
            steps[pp] = phase;
            
            if (pp == k) { // 목적지에 도착한 경우 큐에 삽입이 없어야함
                // 1. 최소 값 갱신
                if (phase < mindist) {
                    mindist = phase;
                }
                // 2. 값이 최소건 아니건 목적지 도착시 일단 푸시
                v.push_back(phase);
            }
            else { // 목적지에 아직 도착하지 못한 경우에만 큐에 삽입
                // +1 이동
                if (val(pp + 1)) {
                    q.push(pp + 1);
                    nextloops++;
                }
                
                // -1 이동
                if (val(pp - 1)) {
                    q.push(pp - 1);
                    nextloops++;
                }
                
                // *2 이동
                if (val(pp * 2)) {
                    q.push(pp * 2);
                    nextloops++;
                }
            }
        }
        phase++;
        
        // 한 탐색에서 큐가 비어있지 않다고 탐색 칠렐레 팔렐레 도는거 방지
        loops = nextloops;
    }
}

void print() {
    int vsz = (int) v.size();
    
    int ans1 = mindist; // 최소거리
    int ans2 = 0;
    
    for (int i = 0; i < vsz; i++) {
        // 목적지에 도착한 어떤 경우가 최소거리라면
        if (v[i] == mindist) {
            ans2++;
        }
    }
    
    cout << ans1 << '\n' << ans2;
}

int main() {
    cin >> n >> k;
    
    bfs();
    
    print();
}