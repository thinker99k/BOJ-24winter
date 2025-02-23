#include <iostream>
#include <vector>
#include <queue>

#define DEBUG 0

using namespace std;

int n, root, del;
vector<int> v[50];

int bfs(){
    vector<bool> visited(50, false);
    queue<int> q;
    
    q.push(root);
    visited[root] = true;
    
    int leaf = 0;
    
    int pp;
    while(!q.empty()){
        pp = q.front();
        q.pop();
        
        // 삭제 타겟 발견시에
        if(pp == del){
            visited[pp] = false;
        }
        else{
        
#if DEBUG
            cout << pp << " visited!\n";
#endif
            if(!v[pp].empty()){
                // 리프 노드가 아닐 경우 bfs 계속 전개
                for(auto it : v[pp]){
                    if(!visited[it]){
                        q.push(it);
                        visited[it] = true;
                    }
                }
            }
            else{
                // 리프 노드일 경우 ++
                leaf++;
            }
        }
    }
    
    return leaf;
}

int main(){
    cin >> n;
    
    int a;
    
    // i가 자식노드, a가 부모노드
    for(int i=0; i<n; i++){
        cin >> a; // i의 부모는 a다
        
        // 부모가 -1일 경우
        if(a == -1){
            root = i; // i는 루트노드
        }
        else{
            v[a].push_back(i);
        }
    }
    
    cin >> del;

#if DEBUG
    cout << "root : " << root << "\ndel : " << del << "\n";
#endif
    
    cout << bfs();
}