#include <iostream>
#include <vector>
#define FIXEDSTART 1

using namespace std;

int n, m; // 1~n에서 길이 m만큼
vector<int> comb;

bool checked[9];

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
            // 중복 방지 - 아직 사용하지 않은 경우만 vector에 push
            if(!checked[i]){
                comb.push_back(i);
                checked[i] = true;
                
                backtrack(level+1, FIXEDSTART);
                
                comb.pop_back();
                checked[i] = false;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    backtrack(0, FIXEDSTART);
}