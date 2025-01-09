#include <iostream>

#define INF 999999999

using namespace std;

long long costs[101][101];

int citys, buses, from, to, cost;

void fw(){
    long long viacost;
    for(int m=1; m<=citys; m++){
        for(int s=1; s<=citys; s++){
            for(int e=1; e<=citys; e++){
                viacost = costs[s][m] + costs[m][e];
                // 거쳐가는게 더 빠르면 거쳐서 간다
                if(costs[s][e] > viacost){
                    costs[s][e] = viacost;
                }
            }
        }
    }
}

int main(){
    cin >> citys;
    for(int i=1; i<=citys; i++){
        for(int j=1; j<=citys; j++){
            if(i != j){
                costs[i][j] = INF;
            }
        }
    }
    
    cin >> buses;
    
    for(int i=1; i<=buses; i++){
        cin >> from >> to >> cost;
        
        if(cost < costs[from][to]){
            costs[from][to] = cost;
        }
    }
    
    fw();
    
    for(int i=1; i<=citys; i++){
        for(int j=1; j<=citys; j++){
            if(costs[i][j] == INF){
                cout << "0 ";
            }
            else{
                cout << costs[i][j] << " ";
            }
        }
        cout << endl;
    }
}