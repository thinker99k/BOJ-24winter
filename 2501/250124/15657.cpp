#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // n개의 수에서 m개만큼 출력

vector<int> v;
vector<int> comb;

void backtrack(int level, int start){
    if(level == m){
        for(int i=0; i<m; i++){
            cout << v[comb[i]] << ' ';
        }
        cout << '\n';
        return;
    }
    else{
        for(int i=start; i<n; i++){
            comb.push_back(i);
            
            backtrack(level+1, i);
            
            comb.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    
    int tmp;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    
    backtrack(0,0);
}