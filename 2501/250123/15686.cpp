#include <iostream>
#include <vector>
#include <cmath>

#define INF 987654321;
#define DEBUG 0

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

typedef int idx;

int n, m; // n*n사이즈 도시에서 m개만큼의 치킨집 남기기

// 이 벡터들은 저장용으로만 쓰인다
vector<Pos> house;
vector<Pos> bhc;
int hsz, bsz;

int dist[100][13]; // 집(row)에서 치킨집(col)까지의 거리
int ans;


bool checked[13]; // 치킨집 방문하면 체크
vector<idx> comb; // 치킨집의 인덱스의 조합

// backtrack에서 m개의 치킨집이 결정될 경우 치킨거리
int calc() {
    int ret = 0;
    
    int chickendist, candidate;
    // 리턴값에 각 집의 치킨거리(어떤 치킨집까지의 최소거리)를 더해줌
    for (int i = 0; i < hsz; i++) {
        chickendist = INF;
        
        for (int j = 0; j < m; j++) {
            candidate = dist[i][comb[j]];
            
            if(candidate < chickendist){
                chickendist = candidate;
            }
        }
        
        ret += chickendist;
    }
    
    return ret;
}

void backtrack(int level, int start) {
    if (level == m) {
        int tmpans = calc();
        
        if (tmpans < ans) {
            ans = tmpans;
        }

#if DEBUG
        cout << "==========================\n";
        for (int i = 0; i < m; i++) {
            cout << "idx " << comb[i] << ": (" << bhc[comb[i]].row << "," << bhc[comb[i]].col << ")\n";
            
        }
        cout << "tmpans: " << tmpans << "\n\n";
#endif
    
    }
    else {
        // i는 좌표가 아닌 vector bhc의 인덱스
        for (int i = start; i < bsz; i++) {
            if (!checked[i]) {
                comb.push_back(i);
                checked[i] = true;
                
                backtrack(level + 1, i + 1);
                
                comb.pop_back();
                checked[i] = false;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ans = INF;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 13; j++) {
            dist[i][j] = INF;
        }
    }
    
    cin >> n >> m;
    
    int tmp;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            
            if (tmp == 1) { // 집의 경우
                house.push_back({i, j});
            }
            else if (tmp == 2) { // 치킨집의 경우
                bhc.push_back({i, j});
            }
            else { ;
            }
        }
    }
    
    hsz = (int) house.size();
    bsz = (int) bhc.size();
    
    // 집[i]에서 치킨집[j]까지 "단순 거리", i, j는 인덱스
    for (int i = 0; i < hsz; i++) {
        for (int j = 0; j < bsz; j++) {
            dist[i][j] = abs(house[i].row - bhc[j].row) + abs(house[i].col - bhc[j].col);
        }
    }
    
    ans = 987654321;
    
    backtrack(0, 0);
    
    cout << ans;
    
}