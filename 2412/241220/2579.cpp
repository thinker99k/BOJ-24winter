#include <iostream>

using namespace std;

int n, tmp;

// 계단 별 점수
int stair[301];

// score[i] : i층에 도달했을 때, 최대 점수
int score[301];


int max(int a, int b) {
    return a > b ? a : b;
}

void dp() {
    // 1층은 바로 갈 수밖에 없음
    score[1] = stair[1];
    
    // 2층은 1-2로 방문해야 최대 점수
    score[2] = stair[1] + stair[2];
    
    // 3층은 1-3, 2-3 중 최대 값
    score[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
    
    // 4층부터는
    for (int i = 4; i <= n; i++) {
        int p = score[i - 2] + stair[i];
        int q = score[i - 3] + stair[i - 1] + stair[i];
        score[i] = max(p, q);
    }
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        stair[i] = tmp;
    }
    
    dp();
    
    cout << score[n];
}