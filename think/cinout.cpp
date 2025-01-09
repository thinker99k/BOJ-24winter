#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char str[100];
    memset(str, 0, 100);
    
    cin >> str;
    
    if(str[0]){
        str[99] = 'a';
    }
    
    cout << str;
}