#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
    int n, rep;
    cin >> n;
    char **arr = (char **) malloc(sizeof(char *) * n);
    for (int i = 0; i < n; i++) {
        arr[i] = (char *) malloc(sizeof(char) * 21);
    }
    
    for (int i = 0; i < n; i++) {
        cin >> rep >> arr[i];
        int len = strlen(arr[i]);
        
        for (int j = 0; j < len; j++) {
            for (int k = 0; k < rep; k++) {
                cout << arr[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}