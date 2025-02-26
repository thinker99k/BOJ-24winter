#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> v(1000001); // 0~n

int getroot(int x) {
    if (v[x] == x) {
        // 부모 = 그 자신 (처음 세팅한것에서 바뀌지 않음)
        return x; // 내가 부모다
    }
    else {
        v[x] = getroot(v[x]); // 재귀적으로 탐색
        
        return v[x]; // 최종적으로 업데이트된 값 반환!
    }
}

// 집합 합치기
void op0(int a, int b) {
    int roota = getroot(a);
    int rootb = getroot(b);
    
    // 루트가 같으면 아무것도 안함
    if (roota != rootb) {
        // 루트가 다르면
        if (roota < rootb) {
            v[rootb] = roota;
        }
        else {
            v[roota] = rootb;
        }
    }
}

// 부모가 같냐?
bool op1(int a, int b) {
    return (getroot(a) == getroot(b));
}

vector<bool> ans;

void prn() {
    for(auto it : ans){
        if(it){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
}

int main() {
    cin >> n >> m;
    
    for (int i = 0; i <= n; i++) {
        v[i] = i;
    }
    
    int opcode, a, b;
    for (int i = 0; i < m; i++) {
        cin >> opcode >> a >> b;
        
        if (!opcode) {
            op0(a, b);
        }
        else {
            ans.push_back(op1(a, b));
        }
    }
    
    prn();
}
