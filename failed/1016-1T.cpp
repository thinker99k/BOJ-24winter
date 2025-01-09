#include <iostream>

using namespace std;

typedef long long ll;

ll minimum, maximum;

bool b[1000001];

ll dp() {
    for (ll i = 0; i <= 1000000; i++) {
        b[i] = true;
    }
    
    ll tocount = maximum - minimum + 1; // max, min 포함
    
    ll square;
    ll vidxstart, pidx;
    
    
    for (ll sqrt = 2;; sqrt++) {
        square = sqrt * sqrt;
        
        if (square > maximum) {
            break;
        }
        
        vidxstart = square;
        
        for (int i = 1;; i++) {
            pidx = vidxstart - minimum;
            if (pidx >= 0) {
                break;
            }
            vidxstart += square;
        }
        
        for (ll i = pidx; i < 1000001; i += square) {
            b[i] = false;
        }
    }
    
    
    ll ret = 0;
    
    for (int i = 0; i < tocount; i++) {
        if (b[i]) {
            ret++;
        }
    }
    
    return ret;
}

int main() {
    cin >> minimum >> maximum;
    
    cout << dp();
}