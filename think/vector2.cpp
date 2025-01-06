#include <iostream>
#include <vector>

using namespace std;


int main(){
    vector<int> v[3];
    
    cout << v[1].size() << endl;
    v[1].push_back(1);
    
    cout << v[1].size() << endl;
    
}