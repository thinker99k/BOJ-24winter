#include <iostream>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

string arr;
string exp;

stack<char> s;

void dp() {
    int arrlen = (int) arr.size();
    int explen = (int) exp.size();
    
    // 폭발이 일어나는 트리거 = 폭발 문자열의 마지막 char
    char trigger = exp.back();
    
    for (int idx = 0; idx < arrlen; idx++) {
        s.push(arr[idx]);
        
        /**
         * 조건 1. 트리거 작동 - 문제에서 폭발 문자열의 char는 모두 다르다 함
         * 조건 2. 스택 사이즈가 폭발할 정도의 길이 이상일 때
         */
        if (s.top() == trigger && (int) s.size() >= explen) {
            string str;
            
            // 폭발문자열 길이만큼 꺼냄
            for (int i = 0; i < explen; i++) {
                str += s.top();
                s.pop();
            }
            
            reverse(str.begin(), str.end());
            
            /**
             * 폭발 문자열과 일치 : 꺼낸 이후에 뭐 더 할거 없이 땡!
             * 폭발 문자열과 일치 x : 꺼낸만큼 다시 그대로 넣어줌
             */
            if (str != exp) {
                for (int i = 0; i < explen; i++) {
                    s.push(str[i]);
                }
            }
        }
    }
}

void print() {
    if (s.empty()) {
        cout << "FRULA";
    }
    else {
        int ssz = (int) s.size();
        
        string ans;
        for (int i = 0; i < ssz; i++) {
            ans += s.top();
            s.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        cout << ans;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> arr;
    cin >> exp;
    
    dp();
    print();
}