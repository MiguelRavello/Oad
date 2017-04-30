#include<iostream>
#include<fstream>
#include<set>
#include<map>
using namespace std;
void dibujo(int);
void dibujo(int m){
	for(int i=0;i<m;i++){
		cout<<'*';
	}
}

int main (int argc, char *argv[]) {
	fstream archivo;
	archivo.open("num.txt");
	map<int,int> lista;
	int j=0;
	for(int i=0;i<100;i+=10){
		lista.insert(pair<int,int>(i,j));
	}
	
	while(!archivo.eof()){
		int x;
		archivo>>x;
		lista.find(x)->second+=1;
	}
	for(map<int,int>::iterator it=lista.begin();it!=lista.end();++it){
		cout<<it->first<<": ";
		dibujo(it->second);
		cout<<endl;
	}
	
	return 0;
}

