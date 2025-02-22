#include <iostream>
#include <vector>

using namespace std;


void dp2(int n, vector<int> &pre, vector<int> &in, vector<int> &post) {
    int root = pre.back();
    int most_left = in.front();
    int most_right = in.back();
    
    vector<int> graph[n];
    bool visited[n];
    
}

vector<int> dp() {
    int n;
    cin >> n;
    
    vector<int> pre(n);
    vector<int> in(n);
    vector<int> post(n, 0);
    
    for (int i = 0; i < n; i++) {
        cin >> pre[i];
    }
    
    for (int i = 0; i < n; i++) {
        cin >> in[i];
    }
    
    dp2(n, pre, in, post);
    
    return post;
}

int main() {
    int t;
    cin >> t;
    
    vector<int> ans[t];
    
    for (int i = 0; i < t; i++) {
        dp();
    }
    
    for (auto it: ans) {
        for (auto c: it) {
            cout << c << " ";
        }
        cout << "\n";
    }
}