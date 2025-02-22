#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <bitset>

#define DEBUG 0
using namespace std;

typedef unsigned int ui;

typedef bitset<32> b;

ui n;

vector<ui> ip;

void prn(bitset<32> bitip) {
    ui field[4];
    for (int i = 3; i >= 0; i--) {
        field[3 - i] = (int) (bitip >> i * 8).to_ulong() & 0xFF;
    }
    
    printf("%d.%d.%d.%d\n", field[0], field[1], field[2], field[3]);
}

void solve() {
    ui same = 0xFFFFFFFF;
    ui tmpsame;
    ui tmpsame2;
    
    ui f = ip.front();
    int tmpsameidx;
    
    b b_sibal(32);
    
    for (auto it: ip) {
        tmpsame = ~(f ^ it);
        tmpsame2 = tmpsame;
        same &= tmpsame;

#if DEBUG
        cout << "b_f  : " << b(f) << "\nxnor\n" << "b_it : " << b(it) << "\n";
        cout << "     = " << b(tmpsame) << "\n";
        cout << "b_same " << b(same) << "\n";
        cout << string(40, '=') << "\n";
#endif
        
        b b_f(0);
        b_sibal = b(same);
        tmpsameidx = 31;
        
        while(b_sibal[tmpsameidx]) {
            b_f[tmpsameidx] = b_sibal[tmpsameidx];
            tmpsameidx--;
        }
    }
    
    int sameidx;
    b b_same(same);
    
    for(int i=31; i>=0; i--){
        if(!b_same[i]){
            sameidx = i+1;
            break;
        }
    }

#if DEBUG
    cout << "same : " << b_same << "\n";
    cout << "[" << sameidx << "]번째 비트까지 같음\n";
#endif
    
    bitset<32> b_someip(ip.front()); // 어차피 겹치는거만 복사할거기에 뭘 골라도 상관 없음
    bitset<32> ipmin(0);
    bitset<32> mask(0);
    for (int idx = 31; idx >= sameidx; idx--) {
        ipmin[idx] = b_someip[idx];
        mask[idx] = true;
    }
    
    prn(ipmin & mask);
    prn(mask);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> n;
    
    ui field[4];
    ui tmp;
    
    for (int i = 0; i < n; i++) {
        memset(field, 0, 4 * 4);
        tmp = 0;
        
        scanf("%d.%d.%d.%d", &field[0], &field[1], &field[2], &field[3]);
        getchar();
        
        for (int j = 0; j < 4; j++) {
            tmp |= field[j] << 8 * (3 - j); // 앞 필드부터 채움
        }
        
        ip.push_back(tmp);
    }

#if DEBUG
    for (auto it: ip) {
        cout << bitset<32>(it) << endl;
    }
#endif
    
    if(n == 1){
        prn(b(ip.front()));
        prn(b(0xFFFFFFFF));
    }
    else{
        solve();
    }
}