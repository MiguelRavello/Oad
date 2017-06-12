#include"link.h"

int Hash::getValue(int key){
    int hash= key%TABLE_SIZE;
    if(m_table[hash]==NULL)
        return -1;
    else{
        Nodo *entry=m_table[hash];
        while(entry!=NULL && entry->m_key!=key)
            entry=entry->m_next;
        if(entry==NULL)
            return -1;
        else
            return entry->m_valor;
    }
}
void Hash::put(int key, int value){
    Nodo *xs=new Nodo(value,key);
    int hash=key%TABLE_SIZE;
    if(m_table[hash]==NULL)
        m_table[hash]=xs;
    else{
        Nodo *prev, *cur;
        prev=m_table[hash];
        cur=m_table[hash]->m_next;
        while(cur!=NULL){
            prev=cur;
            cur=cur->m_next;
        }
        prev->m_next=xs;
    }
    m_table[hash]->m_colision++;
}
void Hash::remove(int key){
    int hash=key%TABLE_SIZE;
    int i=0;
    if(m_table[hash]==NULL)
        ;
    else{
        Nodo *prev, *cur, *victima;
        prev=m_table[hash];
        cur=m_table[hash]->m_next;
        while(cur!=NULL){
            if(prev->m_key==key)
                break;
            prev=cur;
            cur=cur->m_next;
            i++;
        }
        if(i==0){
            prev=m_table[hash];
            cur=m_table[hash]->m_next;
            delete prev;
            m_table[hash]=cur;
        }
        else{
            prev->m_next=cur->m_next;
            victima=cur;
            delete victima;
        }
        m_table[hash]->m_colision--;
    }
}

int main(){
    Hash a;
    a.put(257,1);
    a.put(1,2);
    a.put(632,3);
    a.put(120,4);
    a.put(248,5);
    a.put(376,6);
    /*cout<<a.getValue(257)<<endl;
    cout<<a.getValue(1)<<endl;
    cout<<a.getValue(632)<<endl;*/
    cout<<a<<endl;
    cout<<"-----------------------------"<<endl;
    a.remove(248);
    cout<<a;
    cout<<"-----------------------------"<<endl;
    a.remove(632);
    cout<<a;
    return 0;
}
