#include<iostream>
using namespace std;

struct Nodo{
    int m_val;
    Nodo *m_next;

    Nodo():m_val(0),m_next(NULL){}
    Nodo(int valor):m_val(valor),m_next(NULL){}
    Nodo(const Nodo *xs):m_val(xs->m_val),m_next(xs->m_next){}
};

struct Celda{
    int m_size;
    Nodo *m_head;
    Celda():m_size(0),m_head(NULL){}
    Celda(int valor){
        Nodo *xs=new Nodo(valor);
        m_head=xs;
        m_size=1;
    }
    Celda(const Celda &m){
        *this=m;
    }
    void push(int val){
        Nodo *xs=new Nodo(val);
        if(m_head==NULL)
            m_head=xs;
        else{
            Nodo *prev, *cur;
            prev=m_head;
            cur=m_head->m_next;
            while(cur!=NULL){
                prev=cur;
                cur=cur->m_next;
            }
            prev->m_next=xs;
            delete cur;
        }
        this->setLen();
    }
    void setLen(){
        Nodo *xs;
        xs=m_head;
        int c=0;
        while(xs!=NULL){
            c++;
            xs=xs->m_next;
        }
        delete xs;
        m_size=c;
    }
    friend ostream& operator<<(ostream& out, Celda &m){
        Nodo *xs;
        xs=m.m_head;
        while(xs!=NULL){
            out<<xs->m_val<<"->";
            xs=xs->m_next;
        }
        delete xs;
        return out;
    }
    int sumarecursiva(Nodo *xs){
        if(xs==NULL)
            return 0;
        return xs->m_val + sumarecursiva(xs->m_next);
    }
    Nodo* toprec(Nodo *xs,Nodo *ys){
        if(ys==NULL)
            return xs;
        else{
            xs=ys;
            ys=ys->m_next;
            return toprec(xs,ys);
        }
    }
    int getValX(int x){
        if(x>=m_size)
            return -1;
        Nodo *prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        int i=0;
        while(true){
            if(i==x){
                return prev->m_val;
            }
            prev=cur;
            cur=cur->m_next;
            i++;
        }
    }
    friend Celda operator+(Celda &m, Celda &n){
        Celda rpta;
        Nodo *prev, *cur;
        prev=m.m_head;
        cur=m.m_head->m_next;
        while(cur!=NULL){
            rpta.push(prev->m_val);
            prev=cur;
            cur=cur->m_next;
        }
        rpta.push(prev->m_val);

        prev=n.m_head;
        cur=n.m_head->m_next;
        while(cur!=NULL){
            rpta.push(prev->m_val);
            prev=cur;
            cur=cur->m_next;
        }
        rpta.push(prev->m_val);
        return rpta;
    }
    void concatenar(Celda &m){
        Nodo *prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        while(true){
            if(cur==NULL){
                prev->m_next=m.m_head;
                delete cur;
                break;
            }
            prev=cur;
            cur=cur->m_next;
        }
        this->setLen();
    }
    void imprimereversa(int r){
        if(r<0)
            ;
        else{
            cout<<this->getValX(r)<<"->";
            this->imprimereversa(r-1);
        } 
    }
};

int main(){
    cout<<"Agregamos 4 elementos a la celda a: "<<endl;
    Celda a;
    a.push(1);
    a.push(2);
    a.push(3);
    a.push(4);
    cout<<a<<endl;
    cout<<"La suma de los elementos de a: "<<a.sumarecursiva(a.m_head)<<endl;
    cout<<"El ultimo elemento de a: "<<a.toprec(a.m_head,a.m_head->m_next)->m_val<<endl;
    Celda b;
    b.push(5);
    b.push(6);
    b.push(7);
    b.push(8);
    cout<<"\nInicializamos otra celda b\n"<<b<<endl;
    Celda c;
    c=a+b;
    cout<<"\nConcatenamos las celdas a y b en c"<<endl;
    cout<<c<<endl;
    a.concatenar(b);
    cout<<"\nConcatenamos la celda b en a"<<endl;
    cout<<a<<endl;
    int r=a.m_size;
    cout<<"\nImprimimos la celda a en reversa"<<endl;
    a.imprimereversa(r-1);
    return 0;
}
