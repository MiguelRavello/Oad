#include<iostream>
using namespace std;

struct Nodo{
    int m_val;
    Nodo *m_next;

    Nodo():m_val(0),m_next(NULL){}
    Nodo(int valor):m_val(valor),m_next(NULL){}
    Nodo(const Nodo *xs):m_val(xs->m_val),m_next(xs->m_next){}
};

class Celda{
protected:
    int m_size;
    Nodo *m_head;
public:
    Celda():m_size(0),m_head(NULL){}
    Celda(int valor){
        Nodo *xs=new Nodo(valor);
        m_head=xs;
        m_size=1;
    }
    Celda(const Celda &m){
        *this=m;
    }
    Nodo* head(){   return m_head;}
    int getSize(){  return m_size;}
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
        m_size++;
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
        xs=m.head();
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
        prev=m.head();
        cur=m.head()->m_next;
        while(cur!=NULL){
            rpta.push(prev->m_val);
            prev=cur;
            cur=cur->m_next;
        }
        rpta.push(prev->m_val);

        prev=n.head();
        cur=n.head()->m_next;
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
    void duplicar(){
        Nodo *xs, *prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        while(cur!=NULL){
            xs=new Nodo(prev->m_val);
            prev->m_next=xs;
            xs->m_next=cur;
            prev=cur;
            cur=cur->m_next;
        }
        xs=new Nodo(prev->m_val);
        prev->m_next=xs;
        xs->m_next=cur;
        this->setLen();
    }
    void remove(int index){
        if(index>=m_size)
            ;
        else if(index==0){
            Nodo *prev, *cur;
            prev = m_head;
            cur = m_head->m_next;
            delete prev;
            m_head=cur;
        }
        else{
            Nodo *prev, *cur, *victima;
            prev=m_head;
            cur=m_head->m_next;
            int i=1;
            while(cur!=NULL){
                if(i==index){
                    prev->m_next=cur->m_next;
                    victima=cur;
                    delete victima;
                    m_size--;
                    break;
                }
                prev=cur;
                cur=cur->m_next;
                i++;
            }
        }
    }
    void pop(){
        Nodo *prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        if(prev==NULL)
            ;
        else if(cur==NULL){
            m_head=NULL;
            m_size--;
            delete m_head;
        }
        else{
            while(cur->m_next!=NULL){
                prev=cur;
                cur=cur->m_next;
            }
            prev->m_next=NULL;
            m_size--;
            delete cur;
        }
    }
    bool isEmpty() const{
        if(m_size==0)
            return true;
        else
            return false;
    }
    bool isSorted() const{
        if(m_size==1)
            return true;
        Nodo *prev, *cur;
        prev=m_head;
        cur=m_head->m_next;
        int a=prev->m_val;
        int b=cur->m_val;
        if(a>b)
            return false;
        while(cur->m_next!=NULL){
            if(a>b)
                return false;
            prev=cur;
            cur=cur->m_next;
            a=prev->m_val;
            b=cur->m_val;
        }
        return true;
    }
    void insert(int index, int value){
        Nodo* xs=new Nodo(value);
        m_size++;
        if(m_head==NULL)
            m_head=xs;
        else{
            Nodo *prev, *cur;
            prev=m_head;
            cur=m_head->m_next;
            int i=0;
            while(cur!=NULL){
                if(index==0){
                    xs->m_next=prev;
                    m_head=xs;
                    break;
                }
                else if(i==(index-1)){
                    prev->m_next=xs;
                    xs->m_next=cur;
                    break;
                }
                prev=cur;
                cur=cur->m_next;
                i++;
            }
        }
    }
    void negative(){
        Nodo *prev, *cur, *xs, *ys;
        ys=m_head;
        prev=m_head;
        cur=m_head->m_next;
        while(cur!=NULL){
            if(cur->m_val<0){
                //if(cur->m_next==NULL){}
                xs=cur->m_next;
                prev->m_next=xs; //aqui libere a cur
                cur->m_next=ys;
                m_head=cur;
                //prev=xs;
                cur=xs;
                ys=m_head;
            }
            else{
                prev=cur;
                cur=cur->m_next;
            }
        }
    }
    int contador(){
        Nodo *prev, *cur;
        int c=0;
        prev=m_head;
        cur=m_head->m_next;
        while(cur!=NULL){
            if(prev->m_val==cur->m_val)
                c++;
            prev=cur;
            cur=cur->m_next;
        }
        return c;
    }
};

int main(){
    cout<<"Agregamos elementos a la celda a: "<<endl;
    Celda a;
    a.push(1);
    a.push(8);
    a.push(4);
    a.push(19);
    a.push(17);
    a.duplicar();
    cout<<"para duplicarla"<<endl;
    cout<<a<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"creamos otra celda d para ordenar los negativos solo ordenando punteros"<<endl;
    Celda d;
    d.push(8);
    d.push(7);
    d.push(0);
    d.push(19);
    d.push(-7);
    d.push(43);
    d.push(-8);
    d.push(-4);
    d.push(2);
    d.negative();
    cout<<d<<endl;
    cout<<"------------------------------"<<endl;
    cout<<"contamos los valores duplicados de la celda a: ";
    int con=a.contador();
    cout<<con;
    return 0;
}
