#include <iostream>

using namespace std;

typedef unsigned long long ull;

ull arr[91];

ull fibo(int n){
    arr[1] = 1;
    
    for(int i=2; i<=n; i++){
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr[n];
}

int main(){
    int n;
    cin >> n;
    
    cout << fibo(n);
}