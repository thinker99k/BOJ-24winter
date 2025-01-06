#include <iostream>

using namespace std;

int n;
int arr[1001];
int len[1001]; // i번째에서 끝나는 증가수열의 최대 길이

int max(int a, int b){
    return a > b ? a : b;
}

int dp() {
    int ret = 0;
    
    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = 0;
        
        for (int j = 1; j < i; j++) {
            // j번째 수 보다 i번째 수가 더 클 경우
            if (arr[j] < arr[i]) {
                // tmp 갱신
                tmp = max(tmp, len[j]);
            }
        }
        
        len[i] = tmp + 1;
        
        if(len[i] > ret){
            ret = len[i];
        }
    }
    
    return ret;
}

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    
    cout << dp();
}