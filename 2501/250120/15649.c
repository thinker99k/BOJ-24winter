#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <stdbool.h>

#define FIXEDSTART 1
#define STACKMAXSZ 15

int n, m; // 1~n에서 길이 m만큼

bool checked[STACKMAXSZ];

typedef int DATA;

typedef struct{
    DATA arr[STACKMAXSZ+1]; // [0]은 사용 x
    int top;
} Stack;

Stack * globalS;

Stack * SInit(){
    Stack * newStack = (Stack*)malloc(sizeof(Stack));
    
    memset(newStack->arr, 0, sizeof(DATA) * (STACKMAXSZ+1));
    newStack->top = 0;
    
    return newStack;
}

bool SEmpty(Stack * S){
    return !S->top;
}

void SPush(Stack* S, DATA d){
    if(S->top < STACKMAXSZ){
        S->arr[++S->top] = d;
    }
    else{
        exit(-1);
    }
}

DATA STop(Stack* S){
    if(SEmpty(S)){
        exit(-1);
    }
    else{
        return S->arr[S->top];
    }
}

void SPop(Stack* S){
    if(SEmpty(S)){
        exit(-1);
    }
    else{
        S->top--;
    }
}

void SPrint(Stack* S){
    for(int i=1; i<=S->top; i++){
        printf("%d ", S->arr[i]);
    }
    printf("\n");
}

void backtrack(int level, int start){
    // level == m이면, 출력
    if(level == m){
        SPrint(globalS);
    }
    else{
        for(int i=start; i<=n; i++){
            // 중복 방지 - 아직 사용하지 않은 경우만 vector에 push
            if(!checked[i]){
                SPush(globalS, i);
                checked[i] = true;
                
                backtrack(level+1, FIXEDSTART);
                
                SPop(globalS);
                checked[i] = false;
            }
        }
    }
}

int main(){
    globalS = SInit();
    scanf("%d %d", &n, &m);
    
    backtrack(0, FIXEDSTART);
}