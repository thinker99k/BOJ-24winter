#include <iostream>
#include <string>

#define DEBUG 0

// 2^30 - 1 = 1,073,741,823가 최대 길이로 주어짐
// strlen(Messi(40)) = 1,119,972,818 > 2^30 - 1
#define LIM 40

using namespace std;

typedef long long ll;

ll arr[LIM + 1];

string MessiGimossi = " Messi Gimossi ";

void myfibo() {
    arr[1] = 6;
    arr[2] = 14;
    
    for (int i = 3; i <= LIM; i++) {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
}

int getidx(ll x) {
    int i = 0;
    while (arr[i] <= x) {
        ++i;
    }
    
    return i; // 오른쪽에 있는 인덱스 반환
}

/** x는 숫자, arr[x]는 인덱스 */
int dp(long long x) {
    if (x <= 14) {
        return (int) x;
    }
    else {
        long long tmpx = x - arr[getidx(x) - 1];

#if DEBUG
        cout << "->" << tmpx;
#endif
        return dp(tmpx);
    }
}

int main() {
    myfibo();
    
    long long m;
    cin >> m;

#if DEBUG
    cout << "TRACK : " << m;
#endif
    
    int ans = dp(m);

#if DEBUG
    cout << "\n";
#endif
    
    if (ans == 0 || ans == 6 || ans == 14) {
        cout << "Messi Messi Gimossi";
    }
    else {
        cout << MessiGimossi[ans];
    }
}