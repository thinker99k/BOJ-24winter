#include <iostream>
#include <vector>

using namespace std;

int n, m, k;
int x, cnt;

bool az[201];

void prn(){
    for(int i=1; i<=x; i++){
        if(az[i]){
            cout << 'a';
        }
        else{
            cout << 'z';
        }
    }
    cout << '\n';
}

void backtrack(int lv, int start) {
    if (lv == n) {
        cnt++;
        
        if(cnt == k){
            prn();
            exit(0);
        }
    }
    else {
        for (int i = start; i <= x; i++) {
            az[i] = true;
            
            backtrack(lv + 1, i + 1);
            
            az[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n >> m >> k;
    
    x = n + m;
    
    backtrack(0, 1);
    
    cout << "-1";
}