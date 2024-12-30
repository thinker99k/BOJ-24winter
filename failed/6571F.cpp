#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ull;

vector<ull> v;

ull arr[10000001];

ull fibo1(ull start, ull end) {
    ull sidx = 0, eidx = 0;
    
    for (ull i = 0;; i++) {
        if (i == 0) {
            arr[i] = 0;
        }
        else if (i == 1) {
            arr[i] = 1;
        }
        else {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        
        if(arr[i] >= start){
            sidx = i;
            break;
        }
    }
    
    for (ull i = sidx+1;; i++){
        if (i == 0) {
            arr[i] = 0;
        }
        else if (i == 1) {
            arr[i] = 1;
        }
        else {
            arr[i] = arr[i - 1] + arr[i - 2];
        }
        
        if(arr[i] >= end){
            eidx = i;
            break;
        }
    }
    
    return eidx - sidx;
}

ull fibo2(ull start, ull end) {
    ull sidx = 0, eidx = 0;
    
    for (ull i = 0;; i++) {
        if (arr[i] >= start) {
            sidx = i;
            break;
        }
    }
    
    for (ull i = sidx;; i++) {
        if (arr[i] >= end) {
            eidx = i;
            break;
        }
    }
    
    return eidx - sidx;
}

int main() {
    int s, e;
    
    while (1) {
        cin >> s >> e;
        
        if (s == e && e == 0) {
            break;
        }
        
        if (v.empty()) {
            v.push_back(fibo1(s, e));
        }
        else {
            v.push_back(fibo2(s, e));
        }
    }
    
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}