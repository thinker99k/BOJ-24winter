#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

vector<string> v;

int main() {
    int n, rep;
    char buf[21];
    
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        memset(buf, 0, 21);
        
        cin >> rep >> buf;
        int len = (int) strlen(buf);
        
        string s;
        
        // 반복 1. 문자 하나를
        for (int j = 0; j < len; j++) {
            // 반복 2. rep번만큼
            for (int k = 0; k < rep; k++) {
                s += buf[j];
            }
        }
        
        v.push_back(s);
    }
    
    for (int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    
    return 0;
}