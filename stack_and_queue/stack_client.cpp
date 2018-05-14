#include <iostream>
#include "stack.h"

int main()
{
    StackLinkedList<int> my_stack;
    Stack<int> * p_stack = & my_stack;
    p_stack->push(1);
    p_stack->push(2);
    p_stack->push(3);
    cout << p_stack->pop() << endl;
    cout << p_stack->isEmpty() << endl;
    return 0;
}