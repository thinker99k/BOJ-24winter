#include <iostream>
#include <vector>

using namespace std;

int t, m, n, x, y;

vector<int> ans;

// 최대 40000*40000번의 끔찍하게 많은 루프 돌아야함;
int fun() {
    int i = 1, j = 1, cnt = 0, max = m * n;
    
    while (true) {
        cnt++;
        
        if (cnt > max) {
            return -1;
        }
        
        if (i == x && j == y) {
            return cnt;
        }
        
        if (i < m) {
            i++;
        }
        else if (i == m){
            i = 1;
        }
        else{
            exit(-1); // 일어나면 안되는 경우
        }
        
        if (j < n) {
            j++;
        }
        else if (j == n){
            j = 1;
        }
        else{
            exit(-1); // 일어나면 안되는 경우
        }
    }
}

int main() {
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> m >> n >> x >> y;
        
        ans.push_back(fun());
    }
    
    for(int an : ans){
        cout << an << endl;
    }
}