#include <iostream>
#include <vector>

using namespace std;

int n, m; // 1~n에서 길이 m만큼
vector<int> comb;

// 중복 체크 없음
void backtrack(int level, int start){
    // level == m이면, 출력
    if(level == m){
        for(int i=0; i<m; i++){
            cout << comb[i] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=start; i<=n; i++){
                comb.push_back(i);
                
                backtrack(level+1, i);
                
                comb.pop_back();
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    backtrack(0, 1);
}