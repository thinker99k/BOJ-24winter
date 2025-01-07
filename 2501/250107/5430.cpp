#include <iostream>
#include <cstring>
#include <deque>
#include <vector>

using namespace std;

int t;

char p[100001];
int n;

char tmp;
char arr[222222];

vector<deque<int>> ans1;
vector<int> ans2;

void ac(deque<int> &d) {
    /** false = front, true = back */
    int wherestart = 0;
    
    for (int i = 0; i < strlen(p); i++) {
        if (p[i] == 'R') {  // 시작점이 어디인지
            wherestart = !wherestart;
        }
        else if (p[i] == 'D') {  // 덱에서 하나 빼기
            if (wherestart) {  // 시작점이 뒤면
                d.pop_back();
            }
            else {  // 시작점이 앞이면
                d.pop_front();
            }
        }
        else {  // 실행되면 안됨
            exit(-1);
        }
    }
    ans1.push_back(d);
    ans2.push_back(wherestart);
}

void printdeque(int x) {
    
    deque<int> &dd = ans1[x];
    int sz = (int) dd.size();
    
    if (ans2[x] >= 0) {
        cout << '[';
        
        if (ans2[x] == 1) {  // 역방향 출력
            for (int i = sz - 1; i >= 0; i--) {
                cout << dd[i];
                
                if (i != 0) {  // 마지막에 쉼표 출력 안함
                    cout << ',';
                }
            }
        }
        else if (ans2[x] == 0) {  // 정방향 출력
            for (int i = 0; i < sz; i++) {
                cout << dd[i];
                
                if (i != sz - 1) {  // 마지막에 쉼표 출력 안함
                    cout << ',';
                }
            }
        }
        
        cout << ']' << endl;
    }
    else {  // -1 = 오류
        cout << "error" << endl;
    }
}

int main() {
    cin >> t;
    
    char *ptr;
    
    for (int i = 0; i < t; i++) {
        deque<int> d;
        memset(p, 0, 100001);
        memset(arr, 0, 222222);
        
        cin >> p;
        cin >> n; // 배열의 원소 갯수
        cin >> arr;
        
        ptr = strtok(arr, "[,]");
        
        while (ptr != nullptr) {
            d.push_back(atoi(ptr));
            ptr = strtok(nullptr, "[,]");
        }
        
        deque<int> &dd = d;
        ac(dd);
    }
    
    for (int i = 0; i < t; i++) {
        printdeque(i);
    }
}