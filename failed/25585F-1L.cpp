#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> pos;

int n;
int arr[100][100];

pos start;
bool startevenodd; // 0 - 좌표 합 짝수위치, 1 = 좌표 합 홀수위치

bool evenused; // 좌표 합 짝수위치 사용?
bool oddused; // 좌표 합 홀수위치 사용?

//////////////////////////////////////////////////
/** 적은 최대 10마리 */
vector<pos> enemy;

/** 좌표 변환 */
int dist[10][10]; // 적 a->b로 가는 거리
int esz;


//////////////////////////////////////////////////
int btdistmin;

vector<int> comb;
bool visited[10];

int calcbtdist(){
    int ret = 0;
    
    for(int i=0; i<esz-1; i++){
        ret += dist[comb[i]][comb[i+1]];
    }
    
    return ret;
}

void backtrack(int level) {
    if (level == esz) {
        int curcombdist = calcbtdist();
        
        if(curcombdist < btdistmin){
            btdistmin = curcombdist;
        }
    }
    else {
        for(int i=0; i<esz; i++){
            if(!visited[i]){
                comb.push_back(i);
                visited[i] = true;
                
                backtrack(level + 1);
                
                comb.pop_back();
                visited[i] = false;
            }
        }
    }
}

//////////////////////////////////////////////////
pos convpos(pos &p) {
    pos ret;
    ret.first = p.first + p.second;
    ret.second = ((n - 1) - p.first) + p.second;
    
    return ret;
}


int calcdist(pos &p1, pos &p2) {
    pos cp1 = convpos(p1), cp2 = convpos(p2);
    
    return (abs(cp1.first - cp2.first) + abs(cp1.second - cp2.second)) / 2;
}

int solve() {
    /**
     * 총 거리 = 첫 적으로 이동 거리 + 모든 적을 처리하는 거리
     * 후자는 백트랙으로 계산 가능
     */
    
    esz = (int) enemy.size();
    
    // 1. (출발 - 적) 최소거리 계산
    int startdistmin = 1000000000;
    
    int tmpdist;
    for (auto it: enemy) {
        tmpdist = calcdist(start, it);
        if (tmpdist < startdistmin) {
            startdistmin = tmpdist;
        }
    }
    
    
    // 2. (적 - 적) 거리들 계산
    for (int i = 0; i < esz; i++) {
        for (int j = 0; j < esz; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                dist[i][j] = calcdist(enemy[i], enemy[j]);
            }
        }
    }
    
    // 3. 백트랙으로 적 방문할 경로 나열
    btdistmin = 1000000000;
    backtrack(0);
    
    return startdistmin + btdistmin;
}

int main() {
    cin >> n;
    
    int a;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a;
            arr[i][j] = a;
            
            // 적
            if (a == 1) {
                if ((i + j) / 2) {
                    oddused = true;
                }
                else {
                    evenused = true;
                }
                
                enemy.push_back({i, j});
            }
            
            // 시작
            if (a == 2) {
                start.first = i;
                start.second = j;
            }
        }
    }
    
    if (evenused && oddused) {
        // 홀짝 전부 적 있으면 -> 무조건 안됨
        cout << "Shorei\n";
    }
    else {
        // 홀짝중 하나만 사용되는데
        startevenodd = ((start.first + start.second) % 2) == 1;
        
        if (startevenodd) {
            // 시작 좌표 합 홀수
            if (oddused) {
                // 시작, 적 모두 홀수
                cout << "Undertaker\n";
                cout << solve();
            }
            else {
                // 시작은 홀수인데, 적은 짝수
                cout << "Shorei\n";
            }
        }
        else {
            // 시작 좌표 합 짝수
            if (evenused) {
                // 시작, 적 모두 짝수
                cout << "Undertaker\n";
                cout << solve();
            }
            else {
                // 시작은 짝수인데, 적은 홀수
                cout << "Shorei\n";
            }
        }
    }
}