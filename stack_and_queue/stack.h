#ifndef STACK_H
#define STACK_H
using namespace std;

template <typename ObjType>
class Stack
/*The base class for stack*/
{
    public:
    int N_obj;
    public:
    Stack();
    virtual void push (ObjType obj) = 0;
    virtual ObjType pop() = 0;
    bool isEmpty() {return (N_obj == 0);}
    int size();
};

template <typename ObjType>
class StackArray : public Stack<ObjType>
/*resized-array implementation of stack*/
{
    ObjType *objs; // the array used to store the objects
    int capacity; // the length of the array
    void resize(int new_capacity);
    public:
    StackArray();
    ~StackArray();
    void push(ObjType) override;
    ObjType pop() override;
};

template <typename ObjType>
class Node
{
    ObjType obj;
    Node<ObjType> * next;
    public:
    void set_obj(ObjType new_obj) {obj = new_obj;};
    ObjType get_obj() {return obj;};
    void set_next(Node* new_next) {next = new_next;};
    Node<ObjType> * get_next() {return next;};
};

template <typename ObjType>
class StackLinkedList : public Stack<ObjType>
{
    Node<ObjType> * first;
    public:
    StackLinkedList();
    ~StackLinkedList();
    void push(ObjType new_obj) override;
    ObjType pop() override;
};

#include "stack.cpp"  //include the implementation in the head file to avoid compile error

#endif