#include <iostream>
#include <vector>
#include <algorithm>

#define DEBUG 0
#define LOW -1234567890
#define NL cout << "\n"

using namespace std;

vector<int> aarr;
vector<int> arr;
vector<int> bt;
int maximum = LOW;

// b전봇대에 해당하는 a전봇대
int b_pole[100001];
vector<int> a_pole_alive;

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
        
        if (pos > 0) {
            // 길이(pos)가 1부터
            prev[idx] = lisidx[pos - 1]; // arr[i]의 이전(prev[i])는 lisidx[현재길이(pos)-1]
        }
    }
    
    prev[0] = LOW;

#if DEBUG
    for (int i = 0; i < n; i++) {
        cout.width(4);
        cout << left << i << prev[i] << "\n";
    }
    NL;
#endif
    
    int last = lisidx[lisidx.size() - 1];
    
    /** bt : b 전봇대에 연결된 것들의 위치 */
    while (last != LOW) {
        bt.push_back(arr[last]);
        last = prev[last];
    }
    
    reverse(bt.begin(), bt.end());
    
    /** 구해야하는 것은 A전봇대에 선 끊어야 하는 것들 */
    
    // 전봇대 a에 아직도 연결된 선들
    for (auto it: bt) {
        a_pole_alive.push_back(b_pole[it]);
    }

#if DEBUG
    for (auto it : a_pole_alive){
        cout << it << " ";
    }
    NL;
#endif
    
    return (int) lis.size();
}

int main() {
    /** 전깃줄의 갯수!!!! */
    int n;
    cin >> n;
    
    vector<pair<int, int>> v;
    
    int aidx, bidx;
    for (int i = 0; i < n; i++) {
        cin >> aidx >> bidx;
        
        v.push_back({aidx, bidx});
        b_pole[bidx] = aidx; // b전봇대의 b슬롯에는 a전봇대의 a슬롯과 연결이 된다!
        
        if (aidx > maximum) {
            maximum = aidx;
        }
        if (bidx > maximum) {
            maximum = bidx;
        }
    }
    
    sort(v.begin(), v.end());
    
    for (auto it: v) {
        aarr.push_back(it.first);
        arr.push_back(it.second);
    }
    
    cout << n - lis_nlogn(n) << "\n";
    
    for (auto it: aarr){
        // 살아있는거에서 찾을 수 없으면 -> 선 잘린거임
        if(find(a_pole_alive.begin(), a_pole_alive.end(), it) == a_pole_alive.end()){
            cout << it << " ";
        }
    }
}