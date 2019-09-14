#include<bits/stdc++.h>
using namespace std;

struct Stack
{
    int top;
    int* arr;
    unsigned capacity;
};

Stack* createStack(unsigned capacity)
{
    Stack* stack = new Stack();
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(stack->capacity*sizeof(int));
    return stack;
}

int isfull(Stack* stack)
{
    return stack->top == stack->capacity - 1;
}

int isEmpty(Stack* stack)
{
    return stack->top == -1;
}
void push(Stack* stack,int item)
{
    if(isfull(stack))
        return;
    stack->arr[++stack->top] = item;
    cout<<"pushed" <<endl;
}

void pop(Stack* stack)
{
    if(isEmpty(stack))
        return;
    stack->arr[stack->top--];
}

int peek(Stack* stack)
{
    if(isEmpty(stack))
        return INT_MIN;
    return stack->arr[stack->top];
}

int main()
{
    Stack* stack = createStack(100);
    push(stack,10);
    push(stack,20);
    push(stack,30);
    pop(stack);
    cout<<peek(stack)<<endl;
}