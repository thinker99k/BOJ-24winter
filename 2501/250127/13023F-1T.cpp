#include <iostream>
#include <vector>

#define DEBUG 0

using namespace std;

int n, m;
bool tomodachi[2000][2000];

vector<int> comb;

bool isFiveFriend() {
    if (tomodachi[comb[0]][comb[1]]
        && tomodachi[comb[1]][comb[2]]
        && tomodachi[comb[2]][comb[3]]
        && tomodachi[comb[3]][comb[4]]) {
        return true;
    }
    
    return false;
}

bool checked[2000];

void backtrack(int level) {
    if (level == 5) {
        if (isFiveFriend()) {
            cout << 1;
            exit(0);
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (!checked[i]) {
                comb.push_back(i);
                checked[i] = true;
                
                backtrack(level + 1);
                
                comb.pop_back();
                checked[i] = false;
            }
        }
    }
}

int main() {
    cin >> n >> m;
    
    int tmp1, tmp2;
    for (int i = 0; i < m; i++) {
        cin >> tmp1 >> tmp2;
        
        tomodachi[tmp1][tmp2] = true;
        tomodachi[tmp2][tmp1] = true;
    }
    
    backtrack(0);
    
    cout << 0;
}