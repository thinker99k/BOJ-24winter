#include <iostream>

using namespace std;

int twomax(int &a, int &b) {
    return a > b ? a : b;
}

int twomin(int &a, int &b) {
    return a > b ? b : a;
}

int threemax(int &a, int &b, int &c) {
    if (a >= b && a >= c) {
        return a;
    }
    else if (b >= a && b >= c) {
        return b;
    }
    else if (c >= a && c >= b) {
        return c;
    }
    else {
        // 실행되면 안됨
        return -1;
    }
}

int threemin(int &a, int &b, int &c) {
    if (a <= b && a <= c) {
        return a;
    }
    else if (b <= a && b <= c) {
        return b;
    }
    else if (c <= a && c <= b) {
        return c;
    }
    else {
        // 실행되면 안됨
        return -1;
    }
}

int main() {
    int n, ans1, ans2;
    cin >> n;
    
    int arr[3];  // cin
    int tmp[3];
    int sum1[3]; // max
    int sum2[3]; // min
    
    // 0번째
    for (int &j: arr) {
        cin >> j;
    }
    
    for (int i = 0; i < 3; i++) {
        sum1[i] = arr[i];
        sum2[i] = arr[i];
    }
    
    // 1번째
    for (int i = 1; i < n; i++) {
        for (int &j: arr) {
            cin >> j;
        }
        
        tmp[0] = twomax(sum1[0], sum1[1]) + arr[0];
        tmp[1] = threemax(sum1[0], sum1[1], sum1[2]) + arr[1];
        tmp[2] = twomax(sum1[1], sum1[2]) + arr[2];
        
        for(int j=0; j<3; j++){
            sum1[j] = tmp[j];
        }
        
        tmp[0] = twomin(sum2[0], sum2[1]) + arr[0];
        tmp[1] = threemin(sum2[0], sum2[1], sum2[2]) + arr[1];
        tmp[2] = twomin(sum2[1], sum2[2]) + arr[2];
        
        for(int j=0; j<3; j++){
            sum2[j] = tmp[j];
        }
    }
    
    ans1 = threemax(sum1[0], sum1[1], sum1[2]);
    ans2 = threemin(sum2[0], sum2[1], sum2[2]);
    
    cout << ans1 << " " << ans2;
}