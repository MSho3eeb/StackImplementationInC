#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int *arr;
}stack;

stack * stack_create(int capacity){
    stack * stackk = malloc(sizeof(stack));
    stackk->capacity = capacity;
    stackk->top = -1;
    stackk->arr = malloc((stackk->capacity)*sizeof(int));

    return stackk;
}

void stack_double_size(stack * stackk){
    stackk->capacity *= 2;
    stackk->arr = realloc(stackk->arr, (stackk->capacity)*sizeof(int) );
}

int stack_isFull(stack* stackk){
    return(stackk->top == (stackk->capacity) - 1);
}

int stack_isEmpty(stack *stackk){
    return(stackk->top == -1);
}

int stack_getSize(stack* stackk){
    return(stackk->top + 1);
}

void stack_push(stack* stackk, int data){
    if(stack_isFull(stackk)){
        stack_double_size(stackk);
    }
    stackk->arr[++(stackk->top)] = data;
}

int stack_pop(stack* stackk){
    if(stack_isEmpty(stackk)){
        printf("Empty stack\n");
        return -999;
    }
    return (stackk->arr[(stackk->top)--]);
}

int stack_peek(stack* stackk){
    if(stack_isEmpty(stackk)){
        printf("Empty stack\n");
        return -999;
    }
    return(stackk->arr[(stackk->top)]);
}

void stack_delete(stack* stackk){
    if(stackk){
        if(stackk->arr){
            free(stackk->arr);
        }
        free(stackk);
    }
}


int main(void){
    stack* TheStack = stack_create(10);
    stack_push(TheStack, 10);
    stack_push(TheStack, 20);
    int value1 = stack_pop(TheStack);
    printf("%d\n", value1);
    int value2 = stack_pop(TheStack);
    printf("%d\n", value2);

}
