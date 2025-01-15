#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> stair;
vector<int> score;

class history{
public:
    int twoprev;
    int oneprev;
    int current;
    int score;
    
    history(){
        twoprev = -20;
        oneprev = -10;
        current = 0;
        score = 0;
    }
    
    history(int a, int b, int c, int d){
        twoprev = a;
        oneprev = b;
        current = c;
        score = d;
    }
    
public:
    void addScore(int s){
        score += s;
    }
    
    bool isValid(){
        if(twoprev != 0 && twoprev + 1 == oneprev && oneprev + 1 == current)
            return false;
        else
            return true;
    }
    
    bool isExceedLimit(){
        if(current > n)
            return true;
        else
            return false;
    }
    
    bool isEnd(){
        if(current == n)
            return true;
        else
            return false;
    }
    
    history nextstep(int s){
        return history(oneprev, current, current+s, score);
    }
};

int dp(history h) {
    int ret = 0;
    
    // 세 계단 연속으로 밟음 || 범위 넘어감
    if (!h.isValid() || h.isExceedLimit()){
        return 0;
    }
    else{
        h.addScore(stair[h.current]);
        
        if(h.isEnd()){
            score.push_back(h.score);
            return 0;
        }
        else{
            ret = dp(h.nextstep(1)) + dp(h.nextstep(2));
        }
    }
    
    return ret;
}

int main() {
    cin >> n;
    
    stair.push_back(0);
    
    int tmp;
    
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        stair.push_back(tmp);
    }
    
    dp(history());
    
    int ans = *max_element(score.begin(), score.end());
    
    cout << ans;
    
    
    return 0;
}