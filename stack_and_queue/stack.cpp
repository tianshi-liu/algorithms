#include <stdexcept>
#include "stack.h"

//implementation of member functions in base class Stack

template <typename ObjType>
Stack<ObjType>::Stack()
{
    N_obj = 0;
}


template <typename ObjType>
int Stack<ObjType>::size()
{
    return (N_obj);
}

//implementation of member functions in derived class StackArray

template <typename ObjType>
StackArray<ObjType>::StackArray()
{
    objs = new ObjType [1];
    capacity = 1;
}

template <typename ObjType>
StackArray<ObjType>::~StackArray()
{
    delete [] objs;
}

template <typename ObjType>
void StackArray<ObjType>::resize(int new_capacity)
{
    ObjType* new_objs = new ObjType [new_capacity];
    for (int i = 0; i < this->N_obj; i ++)
    {
        new_objs[i] = objs[i]; //copy the old array into the new one
    }
    delete [] objs;
    objs = new_objs;
    capacity = new_capacity;
}

template <typename ObjType>
void StackArray<ObjType>::push(ObjType new_obj)
{
    if (this->N_obj == capacity) // array is full, resize to twice the original capacity
    {
        resize(2 * capacity);
    }
    objs[this->N_obj] = new_obj;
    this->N_obj += 1;
}

template <typename ObjType>
ObjType StackArray<ObjType>::pop()
{
    ObjType last_obj;
    if (this->N_obj == 0)
        throw out_of_range("empty stack");
    last_obj = objs[this->N_obj - 1];
    this->N_obj -= 1;
    if (this->N_obj < int(capacity / 4))
        resize(int(capacity / 2));
    return last_obj;
}

//implementation of member functions in StackLinkedList

template <typename ObjType>
StackLinkedList<ObjType>::StackLinkedList()
{
    first = NULL;
}

template <typename ObjType>
StackLinkedList<ObjType>::~StackLinkedList()
{
    ObjType current_obj;
    while (!this->isEmpty())
        current_obj = pop();    
}

template <typename ObjType>
void StackLinkedList<ObjType>::push(ObjType new_obj)
{
    Node<ObjType>* current_node = new Node<ObjType>;
    current_node->set_obj(new_obj);
    current_node->set_next(first);;
    first = current_node;
    this->N_obj += 1;
}

template <typename ObjType>
ObjType StackLinkedList<ObjType>::pop()
{
    Node<ObjType> * current_node;
    ObjType current_obj;
    if (this->isEmpty())
        throw out_of_range("empty stack");
    current_node = first;
    first = current_node->get_next();
    current_obj = current_node->get_obj();
    delete current_node;
    this->N_obj -= 1;
    return current_obj;
}