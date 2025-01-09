#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef struct {
    int vertex;
    int step;
} vs;

vector<int> v[20001];
bool checked[20001];
char color[20001];

int vcount, ecount;
vector<bool> ans;

char c;

void swapcolor() {
    if (c == 1) {
        c = 2;
    }
    else {
        c = 1;
    }
}

bool bfs(int x) {
    queue<vs> q;
    
    int startidx = x;
    
    vs pp;
    int currv, currvsz, nextv;
    char currc;
    
    int step = 0;
    c = 1;
    
    q.push({startidx, 1});
    checked[startidx] = true;
    color[startidx] = c;
    
    while (!q.empty()) {
        pp = q.front();
        q.pop();
        
        currv = pp.vertex;
        currc = color[currv];
        
        // bfs의 다음 step이 되면
        if (pp.step > step) {
            step = pp.step; // step 갱신
            swapcolor(); // 색깔 전환
        }
        
        currvsz = (int) v[currv].size();
        
        for (int i = 0; i < currvsz; i++) {
            nextv = v[currv][i];
            
            /** nextv의 색 검사는 다음 bfs step에 들어가던지 말던지 무조건 한다 */
            if (color[nextv]) {  // nextv의 color가 0이 아니면 다른놈이 칠해놨다는 얘기
                if (color[nextv] == currc) {  // 다음 step에 다른 색으로 칠해야 할 색이 curcolor와 같을 경우
                    return false;
                }
            }
            
            if (!checked[nextv]) {
                q.push({nextv, step + 1});
                checked[nextv] = true;
                color[nextv] = c;
            }
        }
    }
    
    return true;
}

int main() {
    int t;
    
    int start, end;
    bool tmp;
    
    cin >> t;
    
    int i, j;
    
    for (i = 0; i < t; i++) {
        cin >> vcount >> ecount;
        
        for (j = 1; j <= ecount; j++) {
            cin >> start >> end;
            
            v[start].push_back(end);
            v[end].push_back(start);
        }
        
        tmp = true;
        
        for(j = 1; j<= vcount; j++){
            if(!checked[j]){
                if(!bfs(j)){  // 어떤 정점들에 대한 bfs 결과들 중 하나라도 true가 아니면
                    tmp = false;
                    break;
                }
            }
        }
        
        ans.push_back(tmp);  // 모든 정점들에 대한 bfs 결과
        
        for (j = 1; j <= vcount; j++) {
            v[j].clear();
        }
        
        memset(checked, 0, vcount + 1);
        memset(color, 0, vcount + 1);
    }
    
    int anssz = (int) ans.size();
    
    for (i = 0; i < anssz; i++) {
        if (ans[i]) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}