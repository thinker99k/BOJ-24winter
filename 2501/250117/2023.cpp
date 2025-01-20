#include <iostream>
#include <cmath>

using namespace std;

int n;

// 무조건 두자리 수부터 주어지기에, if(x<2) 조건 삭제
bool isprime(int x) {
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) {
            return false;
        }
    }
    
    return true;
}

// current에는 소수만 주어짐이 보장됨
void backtrack(int digit, int current) {
    if (digit == n) {
        cout << current << "\n";
    }
    else {
        int next;
        
        // 마지막자리가 짝수이면 아예 글러먹기에, 홀수만 붙혀줌
        for (int i = 1; i <= 9; i += 2) {
            next = 10 * current + i;
            
            if (isprime(next)) {
                backtrack(digit + 1, next);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    backtrack(1, 2);
    backtrack(1, 3);
    backtrack(1, 5);
    backtrack(1, 7);
}