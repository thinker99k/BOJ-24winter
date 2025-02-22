#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int a = 12;
    
    cout << bitset<32>(a & (-a));
}