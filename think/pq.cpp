#include <iostream>
#include <vector>
#include <queue>

#define INF -987654321

using namespace std;

typedef pair<int, int> Edge;

int main () {
    priority_queue<Edge> pq;
    
    pq.push({1, 1});
    
    pq.push({2, 2});
    
    pq.push({3, 3});
    
    auto temp1 = pq;
    int t1sz = (int) temp1.size();
    cout << "========= temp 1 =========" << endl;
    for(int i=0; i<t1sz; i++){
        cout << temp1.top().first << " " << temp1.top().second << endl;
        
        temp1.pop();
    }
    
    pq.empty();
    
    auto temp2 = pq;
    int t2sz = (int) temp2.size();
    cout << "========= temp 2 =========" << endl;
    for(int i=0; i<t2sz; i++){
        cout << temp2.top().first << " " << temp2.top().second << endl;
        
        temp2.pop();
    }
    
    vector<int> v;
}