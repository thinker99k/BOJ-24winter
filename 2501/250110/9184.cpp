#include <iostream>
#include <vector>

using namespace std;

typedef struct{
    int a;
    int b;
    int c;
    int answer;
}ans;

vector<ans> v;

int arr[21][21][21]; // dp(a, b, c)의 값
int x, y, z;

int dp(int a, int b, int c){
    if(a <= 0 || b <= 0 || c <= 0){
        return 1;
    }
    else if(a > 20 || b > 20 || c > 20){
        return dp(20, 20, 20);
    }
    else if(a < b && b < c){
        // 메모이제이션 활용
        if(arr[a][b][c]){
            return arr[a][b][c];
        }
        else{
            arr[a][b][c] = dp(a, b, c-1) + dp(a, b-1, c-1) - dp(a, b-1, c);
            
            return arr[a][b][c];
        }
    }
    else{
        // 메모이제이션 활용
        if(arr[a][b][c]){
            return arr[a][b][c];
        }
        else{
            arr[a][b][c] = dp(a-1, b, c) + dp(a-1, b-1, c) + dp(a-1, b, c-1) - dp(a-1, b-1, c-1);
            
            return arr[a][b][c];
        }
    }
}

int main(){
    while(true){
        cin >> x >> y >> z;
        
        if(x == -1 && y == -1 && z == -1){
            break;
        }
        
        v.push_back({x, y, z, dp(x, y, z)});
    }
    
    int anssz = (int)v.size();
    
    for(int i=0; i<anssz; i++){
        cout << "w(" << v[i].a << ", " << v[i].b << ", " << v[i].c << ") = " << v[i].answer << endl;
    }
}