#include <iostream>
#include <vector>

using namespace std;

int n;

vector<int> comb;
bool *barr;

void backtrack(int lv){
    if(lv == n){
        for(int i=0; i<n; i++){
            cout << comb[i] + 1 << " ";
        }
        cout << "\n";
    }
    else{
        for(int i=0; i<n; i++){
            if(!barr[i]){
                comb.push_back(i);
                barr[i] = true;
                
                backtrack(lv+1);
                
                comb.pop_back();
                barr[i] = false;
            }
        }
    }
}

int main(){
    cin >> n;
    
    barr = new bool[n];
    
    backtrack(0);
    
    delete barr;
}