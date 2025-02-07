#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; // n개에서 길이 m만큼

vector<int> v;
vector<int> comb;

bool checked[9]; // 수에 대한것이 아닌 v의 인덱스에 대한 checked

void backtrack(int level) {
    if (level == m) {
        for (int i = 0; i < m; i++) {
            cout << comb[i] << " ";
        }
        cout << "\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            if (i > 0 &&
                v[i] == v[i - 1] &&
                !checked[i - 1]) {
                continue;
            }
            
            //if (!checked[i]) {
                comb.push_back(v[i]);
                checked[i] = true;
                
                backtrack(level + 1);
                
                comb.pop_back();
                checked[i] = false;
            //}
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m;
    
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        v.push_back(tmp);
    }
    
    sort(v.begin(), v.end());
    backtrack(0);
}