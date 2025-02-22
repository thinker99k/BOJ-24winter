#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>

#define DEBUG 0
using namespace std;

typedef unsigned int ui;

ui n;

vector<ui> ip;

void prn(bitset<32> bitip){
    ui field[4];
    for(int i=3; i>=0; i--){
        field[3-i] = (int) (bitip >> i*8).to_ulong() & 0xFF;
    }
    
    cout << field[0] << "." << field[1] << "." << field[2] << "." << field[3] << "\n";
}

void solve() {
    ui s = ip.front(); // 가장 큰 수
    bitset<32> b_largest(s);

#if DEBUG
    cout << "가장 큰 수(b_largest)\n" << b_largest << "\n";
#endif
    
    ui x = 0xFFFFFFFF; // 모든 비트 1
    for (auto it: ip) {
        x &= it; // 모든 ip에 대해 bitwise and 연산
    }
    
    bitset<32> b_andall(x);

#if DEBUG
    cout << "전부 비트엔드 연산(b_andall)\n" << b_andall << "\n";
#endif
    
    int sameidx;
    for (int idx = 31; idx >= 0; idx--) {

#if DEBUG
        cout << idx << ": " << b_largest[idx] << " vs " << b_andall[idx] << "\n";
#endif
        
        if (b_largest[idx] != b_andall[idx]) {
            sameidx = idx + 1;
            break;
        }
    }

#if DEBUG
    cout << "[" << sameidx << "]번째 비트까지 같음\n";
#endif
    
    bitset<32> ipmin(0);
    bitset<32> mask(0);
    for (int idx = 31; idx >= sameidx; idx--) {
        ipmin[idx] = b_andall[idx];
        mask[idx] = true;
    }
    
    prn(ipmin);
    prn(mask);
}

int main() {
    cin >> n;
    
    char buf[16];
    
    ui field;
    ui tmp;
    for (int i = 0; i < n; i++) {
        memset(buf, 0, 16);
        tmp = 0;
        
        cin >> buf;
        char *tok = strtok(buf, ".");
        
        for (int j = 0; j < 4; j++) {
            field = (ui) atoi(tok);
            tmp |= field << 8 * (3 - j); // 앞 필드부터 채움
            tok = strtok(nullptr, ".");
        }
        
        ip.push_back(tmp);
    }
    
    sort(ip.begin(), ip.end());
    reverse(ip.begin(), ip.end());
    
    solve();
}