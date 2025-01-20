#include <iostream>
#include <deque>
#include <vector>
using namespace std;

deque<int> dq;
vector<int> ans;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n;
    cin >> n;
    
    int tmp;
    for(int i=0; i<n; i++){
        cin >> tmp;
        dq.push_back(tmp);
    }
    
    int first;
    bool found;
    for(int i=0; i<n; i++){
        first = dq.front();
        found = false;
        
        for(auto it: dq){
            if(first < it){
                ans.push_back(it);
                found = true;
                break;
            }
        }
        
        if(!found){
            ans.push_back(-1);
        }
        
        dq.pop_front();
    }
    
    int anssz = (int) ans.size();
    for(int i=0; i<anssz; i++){
        cout << ans[i] << " ";
    }
}