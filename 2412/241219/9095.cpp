#include <iostream>
#include <string>

using namespace std;

int rec(int x, int y) {
    int ret = 0;
    
    if (x > y) {
        ret = 0;
    }
    else if (x == y) {
        ret = 1;
    }
    else {
        ret = rec(x + 1, y) + rec(x + 2, y) + rec(x + 3, y);
    }
    
    return ret;
}

int main() {
    int n;
    cin >> n;
    
    int *arr1 = (int *) malloc(sizeof(int) * n);
    int *arr2 = (int *) malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    
    for (int i = 0; i < n; i++) {
        arr2[i] = rec(0, arr1[i]);
    }
    
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << endl;
    }
    
    free(arr1);
    free(arr2);
    
    return 0;
}