#include<iostream>
#include<stack>
#include<string>
using namespace std;

void imprimir(int x){
    string leng;
	leng.resize(x);
    for(int i=0;i<x;i++)
        leng[i]='*';
    for(int i=0;i<x;i++)
        cout<<leng[i];
}

int main(){
    stack<int> lista;
    lista.push(100);
    lista.push(95);
    lista.push(47);
    lista.push(88);
    lista.push(86);
    lista.push(92);
    lista.push(75);
    lista.push(89);
    lista.push(81);
    lista.push(70);
    lista.push(55);
    lista.push(80);
    
    int mnumeros[11];
    for(int i=0;i<11;i++){
        mnumeros[i]=0;
    }

    while(!lista.empty()){
        if(lista.top()<10 && lista.top()>=0){
            ++mnumeros[0];
            lista.pop();
        }
        else if(lista.top()<20){
            ++mnumeros[1];
            lista.pop();
        }
        else if(lista.top()<30){
            ++mnumeros[2];
            lista.pop();
        }
        else if(lista.top()<40){
            ++mnumeros[3];
            lista.pop();
        }
        else if(lista.top()<50){
            ++mnumeros[4];
            lista.pop();
        }
        else if(lista.top()<60){
            ++mnumeros[5];
            lista.pop();
        }
        else if(lista.top()<70){
            ++mnumeros[6];
            lista.pop();
        }
        else if(lista.top()<80){
            ++mnumeros[7];
            lista.pop();
        }
        else if(lista.top()<90){
            ++mnumeros[8];
            lista.pop();
        }
        else if(lista.top()<100){
            ++mnumeros[9];
            lista.pop();
        }
        else if(lista.top()==100){
            ++mnumeros[10];
            lista.pop();
        }
        /*else{
            ++mnumeros[11];
            lista.pop();
        }*/
    }
    for(int i=0;i<11;i++){
        if(i==10){
            cout<<i*10<<"s:";
            imprimir(mnumeros[i]);
            cout<<endl;
            break;
        }
        cout<<i*10<<"s: ";
        imprimir(mnumeros[i]);
        cout<<endl;
    }
    return 0;
}
