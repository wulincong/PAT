#ifndef SEQUENCESTACK_C 
#define SEQUENCESTACK_C

#include "SequenceStack.h"

Status InitStack_Sq(SqStack *S){
    S->base = (SElemType_Sq *)malloc(STACK_INIT_SIZE * sizeof(SElemType_Sq));
    if(!S->base) exit(OVERFLOW);
    S->top = S->base;
    S->stackSize = STACK_INIT_SIZE;
    return OK;
}

Status DestroyStack_Sq(SqStack *S){
    free(S->base);
    S->base = NULL;
    S->top = NULL;
    S->stackSize = 0;
    return OK;
}

Status ClearStack_Sq(SqStack *S){
    S->top = S->base;
    return OK;
}

Status StackEmpty_Sq(SqStack S){
    return S.top == S.base;
}

int StackLength_Sq(SqStack S){
    return S.top - S.base;
}

Status GetTop_Sq(SqStack S, SElemType_Sq *e){
    if(S.top == S.base) return ERROR;
    *e = *(S.top - 1);  //不是出栈，不破坏栈
    return OK;
}

Status Push_Sq(SqStack *S, SElemType_Sq e){
    if(S->top - S->base >= S->stackSize){  //栈满
        S->base = (SElemType_Sq *) realloc(S->base, (S->stackSize + STACKINCREMENT) * sizeof(SElemType_Sq));
        if(!S->base) exit(OVERFLOW);
        S->top = S->base + S->stackSize;
        S->stackSize += STACKINCREMENT;
    }
    *(S->top) = e;
    (S->top)++;
    return OK;
}

Status Pop_Sq(SqStack *S, SElemType_Sq *e){
    if(S->top == S->base) return ERROR;
    S->top --;
    *e = *(S->top);
    return OK;
}


Status StackTraverse_Sq(SqStack S, void(Visit)(SElemType_Sq)){
    SElemType_Sq *p = S.base;
    while(p < S.top) Visit(*p++);
    return OK;
}

#endif