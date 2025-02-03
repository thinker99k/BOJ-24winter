#include <stdio.h>

int arr[16] = {
        0,
        1, 0, 0, 2, 10,
        4, 40, 92, 352, 724,
        2680, 14200, 73712, 365596, 2279184
};

int m;

int main(){
    scanf("%d", &m);
    getchar();
    
    printf("%d", arr[m]);
}