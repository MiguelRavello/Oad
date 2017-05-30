#ifndef HEAP_H
#define HEAP_H
#include<iostream>
using namespace std;

class Heap{
protected:
    int m_size;
    int *m_head;
public:
    Heap();
    Heap(int *nodos);
    Heap(Heap &xs);
    ~Heap();

    void resize(int newsize);
    void clear();
    int getSize() {    return m_size;}
    void push(int &p);
    int top();
    void pop();
    void bubbleUp();
    void bubbleDown();
    void swap(int child, int parent);
    int getLeftChild(int parent);
    int getRightChild(int parent);
    int getParent(int child);
};

#endif
