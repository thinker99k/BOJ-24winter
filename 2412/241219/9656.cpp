#include <iostream>
#include <string>

using namespace std;

string name[2] = {"SK", "CY"};

int main(){
    int n, i;
    cin >> n;
    
    cout << name[(n % 2)];
    
    return 0;
}