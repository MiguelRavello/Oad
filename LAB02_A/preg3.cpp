#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

class tupla{
public:
	int m_index;
	int m_x;
	string m_y;
	
	tupla():m_index(0),m_x(0),m_y(""){}
	tupla(int key,int nx,string ny):m_index(key), m_x(nx), m_y(ny){}
	tupla(tupla const &o):m_index(o.m_index), m_x(o.m_x), m_y(o.m_y){}
};

int maxtupla(stack<tupla> xs){
	tupla inicial(xs.top());
	int i=inicial.m_x;
	int index=inicial.m_index;
	xs.pop();
	while(!xs.empty()){
		tupla temp(xs.top());
		if(i<temp.m_x){
			i=temp.m_x;
			index=temp.m_index;
			xs.pop();
		}
		xs.pop();
	}
	return index;
}

void contador(){
	stack<tupla> lista;
	int i=0;
	while (true) {
		string oraciones;
		int len;
		cout << "Escriba algo: ";
		getline(cin, oraciones);
		len=oraciones.length();
		tupla xs(i,len,oraciones);
		lista.push(xs);
		i++;
		if (oraciones == "") break;
	}
	int j=maxtupla(lista);
	while(!lista.empty()){
		if(j==lista.top().m_index){
			cout<<lista.top().m_y;
			break;
		}
		lista.pop();
	}
	
}

int main(){
	contador();
	return 0;
}
