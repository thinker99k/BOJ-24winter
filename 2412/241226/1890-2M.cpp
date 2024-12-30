#include <iostream>
#include <queue>

using namespace std;

typedef struct {
    int row;
    int col;
} Pos;

int n;
int arr[100][100];
int sum[100][100];

queue<Pos> q;

void dp() {
    q.push(Pos{0, 0});
    
    Pos Pf, P1, P2;
    int distance;
    
    while (!q.empty()) {
        Pf = q.front();
        
        distance = arr[Pf.row][Pf.col];
        ++sum[Pf.row][Pf.col];
        
        if(distance){
            // 점프 가능 거리가 0 = 갇히는 경우가 아니면
            if(Pf.row + distance < n){
                // row가 범위를 벗어나지 않으면
                P1 = {Pf.row + distance, Pf.col};
                q.push(P1);
            }
            if(Pf.col + distance < n){
                // col이 범위를 벗어나지 않으면
                P2 = {Pf.row, Pf.col + distance};
                q.push(P2);
            }
        }
        
        q.pop();
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    
    dp();
    
    cout << sum[n-1][n-1] << endl;
}