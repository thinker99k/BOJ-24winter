#include <iostream>

using namespace std;

int ans;
int arr[100000];

// i번째 칸에 올 수 있는 최대 합
int sum[100000];

int max(int a, int b) {
    return a > b ? a : b;
}

void search(int n) {
    ans = -1001;
    
    for(int i=1; i < n; i++){
        sum[i] = max(arr[i], sum[i-1] + arr[i]);
    }
    
    for(int i=0; i<n; i++){
        ans = sum[i] > ans ? sum[i] : ans;
    }
}

int main() {
    int n;
    cin >> n;
    
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // 0번째 칸 도착 시 최대 합은 arr[0];
    sum[0] = arr[0];
    
    search(n);
    
    cout << ans;
}