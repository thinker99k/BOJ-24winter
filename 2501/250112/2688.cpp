#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> ans;

ull arr[66][10];

void calc() {
    for (int i = 0; i < 10; i++) {
        arr[1][i] = 1;
    }
    
    for (int row = 2; row <= 65; row++) {
        arr[row][0] = 1;
        
        for (int col = 1; col < 10; col++) {
            arr[row][col] = arr[row][col - 1] + arr[row - 1][col];
        }
    }
}

int main() {
    calc();
    
    int t, n;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> n;
        
        ans.push_back(arr[n + 1][9]);
    }
    
    for (int i = 0; i < t; i++) {
        cout << ans[i] << endl;
    }
    
}