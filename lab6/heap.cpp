#include "heap.h"

Heap::Heap():m_size(0){
    m_head=new int[m_size];
}
Heap::Heap(int *nodos){
    int tam = sizeof(nodos)/sizeof(int);
    for(int i=0;i<tam;i++)
        this->push(nodos[i]);
}
Heap::Heap(Heap &xs){
    this->m_size=xs.getSize();
    this->m_head=new int[m_size];
    for(int i=0;i<m_size;i++)
        this->m_head[i]=xs.m_head[i];
}
Heap::~Heap(){
    delete[] m_head;
}

void Heap::resize(int newsize){
    int *xs=new int[newsize];
    int minsize= (newsize>m_size ? m_size:newsize);
    for(int i=0;i<minsize;i++)
        xs[i]=m_head[i];
    delete[] m_head;
    m_size=newsize;
    m_head=xs;
}
void Heap::clear(){
    this->resize(0);
}
void Heap::push(int &p){
    this->resize(m_size+1);
    this->m_head[m_size-1]=p;
    this->bubbleUp();
}
void Heap::swap(int child,int parent){
    int temp;
    temp=m_head[child];
    m_head[child]=m_head[parent];
    m_head[parent]=temp;
}
int Heap::getParent(int child){
    if(child%2==0)
        return (child/2)-1;
    else
        return child/2;
}
int Heap::getLeftChild(int parent){
    return 2*parent+1;
}
int Heap::getRightChild(int parent){
    return 2*parent+2;
}
void Heap::bubbleUp(){
    int child=m_size-1;
    int parent=getParent(child);
    while(m_head[child]>m_head[parent] && child >=0 && parent >=0){
        swap(child, parent);
        child=parent;
        parent=getParent(child);
    }
}
void Heap::bubbleDown(){
    int parent=0;
    while(1){
        int left=getLeftChild(parent);
        int right=getRightChild(parent);
        int length=this->m_size;
        int largest=parent;
        if(left < length && m_head[left] > m_head[largest])
            largest=left;
        if(right < length && m_head[right] > m_head[largest])
            largest=right;
        if(largest!=parent){
            swap(largest, parent);
            parent=largest;
        }
        else
            break;
    }
}
int Heap::top(){
    int value=m_head[0];
    return value;
}
void Heap::pop(){
    int child=this->m_size - 1;
    swap(child,0);
    this->resize(m_size-1);
    this->bubbleDown();
}

int main(){
    int a[]={4,5,2,3,6,7};
    int len=sizeof(a)/sizeof(int);
    Heap lista;
    for(int i=0;i<len;i++)
        lista.push(a[i]);
    while(lista.getSize()>0){
        cout<<lista.top()<<" ";
        lista.pop();
    }
    return 0;
}







