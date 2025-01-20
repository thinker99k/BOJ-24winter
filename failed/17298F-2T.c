#include <stdio.h>
#include <stdbool.h>

int arr[1000000];
int ans[1000000];

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    
    int tmp;
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        getchar();
    }
    
    int first;
    bool found;
    
    for(int i=0; i<n; i++){
        first = arr[i];
        found = false;
        
        for(int j=i+1; j<n; j++){
            if(arr[j] > first){
                ans[i] = arr[j];
                found = true;
                break;
            }
        }
        
        if(!found){
            ans[i] = -1;
        }
    }
    
    for(int i=0; i<n; i++){
        printf("%d ", ans[i]);
    }
}