#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0
#define LOW -1234567890

using namespace std;

vector<int> arr;
vector<int> bt;

// left는 항상 0, right는 그때 그때의 lis의 크기, target은 arr[i]
int mybsearch(const vector<int> &v, int left, int right, int target) {
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
    // lis[idx] : arr에서 길이가 i이면서 가장 인덱스가 큰 값
    vector<int> lis;
    
    // lisidx[idx] : lis[idx]의 인덱스
    vector<int> lisidx;
    
    // prev[idx] : 백트랙용
    vector<int> prev(n, LOW);
    
    int lsz, pos;
    for (int idx = 0; idx < n; idx++) {
        lsz = (int) lis.size();
        
        // pos는 arr[i]에서 끝나는 수열의 길이
        pos = mybsearch(lis, 0, lsz, arr[idx]);
        
        // 이진탐색으로 구한 길이가
        if (pos == lsz) {
            // 알려진 최대값보다 클 경우
            lis.push_back(arr[idx]); // 새로운 값 push
            lisidx.push_back(idx); // 그 값의 인덱스 push
        }
        else {
            // 알려진 최대값보다 크지 않을 경우
            lis[pos] = arr[idx]; // 기존 값 갱신
            lisidx[pos] = idx; // 그 값의 인덱스 갱신
        }
        
        if(pos > 0){
            // 길이(pos)가 1부터
            prev[idx] = lisidx[pos-1]; // arr[i]의 이전(prev[i])는 lisidx[현재길이(pos)-1]
        }
    }
    
    prev[0] = LOW;
    
#if DEBUG
    for (int i = 0; i < n; i++) {
        cout.width(4);
        cout << left << i << prev[i] << "\n";
    }
    cout << "\n";
#endif
    
    int last = lisidx[lisidx.size() - 1];
    
    while (last != LOW){
        bt.push_back(arr[last]);
        last = prev[last];
    }
    
    reverse(bt.begin(), bt.end());
    
    return (int) lis.size();
}

int main() {
    int n;
    
    cin >> n;
    
    int a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        
        arr.push_back(a);
    }
    
    cout << lis_nlogn(n) << "\n";
    for (auto it: bt) {
        cout << it << " ";
    }
}