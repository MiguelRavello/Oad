#include<iostream>
using namespace std;
static int TABLE_SIZE=128;

class Nodo{
public:
    int m_colision;
    int m_valor;
    int m_key;
    Nodo *m_next;
    Nodo():m_valor(0),m_key(0),m_next(NULL),m_colision(0){}
    Nodo(int value,int key):m_valor(value),m_key(key),m_next(NULL),m_colision(0){}
    Nodo(Nodo &xs):m_key(xs.m_key),m_valor(xs.m_valor),m_next(xs.m_next),m_colision(xs.m_colision){}
};

class Hash{
private:
    Nodo **m_table;
public:
    Hash(){
        m_table=new Nodo*[TABLE_SIZE];
        for(int i=0;i<TABLE_SIZE;i++)
            m_table[i]=NULL;
    }
    ~Hash(){
        for(int i=0;i<TABLE_SIZE;i++){
            if(m_table[i]!=NULL){
                Nodo *prev=NULL;
                Nodo *entry=m_table[i];
                while(entry!=NULL){
                    prev=entry;
                    entry=entry->m_next;
                    delete prev;
                }
            }
        }
        delete[] m_table;
    }
    int getValue(int key);
    void put(int key,int value);
    void remove(int key); 
    friend ostream& operator<<(ostream& out, Hash &m){
        Nodo *xs;
        for(int i=0;i<TABLE_SIZE;i++){
            if(m.m_table[i]==NULL)
                continue;
            xs=m.m_table[i];
            while(xs!=NULL){
                out<<xs->m_valor<<"->";
                xs=xs->m_next;
            }
            cout<<endl;
        }
        delete xs;
        return out;
    }
};
