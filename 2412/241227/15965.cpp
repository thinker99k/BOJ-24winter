#include <iostream>
#include <cstring>

// size = 10MB
#define sz 10000000

using namespace std;

char isPrime[sz];

void prime(){
    memset(isPrime, 1, sz);
    
    isPrime[0] = 0;
    isPrime[1] = 0;
    
    for(int i=2; i<sz; i++){
        if(isPrime[i]){
            for(int j=i + i; j<sz; j += i){
                isPrime[j] = 0;
            }
        }
    }
}

int getPrime(int x){
    int idx = 0;
    for(int i=2; i<sz; i++){
        if(isPrime[i]){
            ++idx;
            
            if(idx == x){
                return i;
            }
        }
    }
}

int main(){
    prime();
    
    int k;
    cin >> k;
    
    cout << getPrime(k);
    
}