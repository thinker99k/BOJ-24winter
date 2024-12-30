#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

typedef unsigned long long ull;

ull arr[10001];
vector<ull> ans;

ull mod(ull p, ull q) {
    return p % q;
}

ull fibo(ull p, ull q) {
    memset(arr, 0, sizeof(ull) * 10001);
    
    arr[1] = 1;
    
    for (int i = 2; i <= p; i++) {
        arr[i] = mod(arr[i - 1], q) + mod(arr[i - 2], q);
    }
    
    return mod(arr[p], q);
}

int main() {
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    ull p, q;
    for (int i = 0; i < n; i++) {
        cin >> p >> q;
        ans.push_back(fibo(p, q));
    }
    
    for(int i=0; i<ans.size(); i++){
        cout << "Case #" << i+1 << ": " << ans[i] << endl;
    }
}