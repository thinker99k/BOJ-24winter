#include <iostream>
#include <vector>

#define DEBUG 0

using namespace std;

vector<int> arr;

// left는 항상 0, right는 그때 그때의 lis의 크기, target은 arr[i]
int mybsearch(vector<int> &v, int left, int right, int target) {
    while (left < right) {
        int mid = (left + right) / 2;
        
        if (v[mid] >= target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    
    return left;
}

int lis_nlogn(int n) {
    vector<int> lis;
    // lis[i] : arr에서 길이가 i이면서 가장 인덱스가 큰 값
    
    int lsz, pos;
    for (int i = 0; i < n; i++) {
        lsz = (int) lis.size();
        
        pos = mybsearch(lis, 0, lsz, arr[i]);
        
        if (pos == lsz) {
            // 이진탐색으로 찾은 위치가 알려진 최대값보다 클 경우
            lis.push_back(arr[i]); // 새로운 값 push
        }
        else {
            lis[pos] = arr[i]; // 기존 값 갱신
        }
    }

#if DEBUG
    for (auto it: lis) {
        cout << it << " ";
    }
    cout << "\n";
#endif
    
    /** 궁금한 것은 길이가 얼마인지지, lis 수열 자체를 구하는 것이 아니다 */
    return (int) lis.size();
}

int main() {
    vector<bool> ans;
    int t;
    cin >> t;
    
    int n, k, tmp;
    for (int i = 0; i < t; i++) {
        arr.clear();
        
        cin >> n >> k;
        for (int j = 0; j < n; j++) {
            cin >> tmp;
            arr.push_back(tmp);
        }
        
        ans.push_back(lis_nlogn(n) >= k);
        
    }
    
    for (int i = 0; i < t; i++) {
        cout << "Case #" << i+1 << "\n";
        cout << ans[i] << "\n";
    }
}