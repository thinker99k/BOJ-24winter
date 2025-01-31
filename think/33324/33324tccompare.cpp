#include <iostream>
#include <chrono>

#define MAX 30000000000000

using namespace std;
using namespace chrono;

typedef long long ll;
typedef unsigned long long ull;

high_resolution_clock::time_point t1, t2;
ull calccount;

void prn() {
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    
    cout << "time  : " << elapsed_ms.count() << "\n";
    cout << "count : " << calccount << "\n";
}

ll calc1(ll n) {
    t1 = high_resolution_clock::now();
    
    ll result = 0;
    ll i;
    for (i = 1; i * i <= n; i++) {
        result += (n / i) * 2;
        ++calccount;
    }
    
    t2 = high_resolution_clock::now();
    cout << "== calc1 == \n";
    prn();
    return result - (i - 1) * (i - 1);
}

ll calc2(ll n) {
    t1 = high_resolution_clock::now();
    
    ll result = 0;
    ll v, j;
    for (ll i = 1; i <= n;) {
        v = n / i;
        j = n / v + 1;
        
        result += v * (j - i);
        i = j;
        
        ++calccount;
    }
    
    t2 = high_resolution_clock::now();
    cout << "== calc2 == \n";
    prn();
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    ll ans1 = calc1(MAX);
    ll ans2 = calc2(MAX);
    
    cout << ans1 << "\n" << ans2 << "\n";
}