#include <iostream>
#include <cstring>

#define MAX 1000001

using namespace std;

char isPrime[1000001];

void prime() {
    memset(isPrime, 1, MAX);
    
    isPrime[0] = 0;
    isPrime[1] = 0;
    
    for (int i = 2; i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i + i; j < MAX; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

void printp(int start, int end) {
    for(int i=start; i<=end; i++){
        if(isPrime[i]){
            printf("%d\n", i);
        }
    }
}

int main() {
    prime();
    
    int m, n;
    cin >> m >> n;
    
    printp(m, n);
}