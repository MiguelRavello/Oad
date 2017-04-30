#include<iostream>
#include<fstream>
#include<map>
#include<set>
using namespace std;

int main (int argc, char *argv[]) {
	ifstream archivo;
	archivo.open("english_words.txt");
	if(archivo.fail()){
		cerr<<"error";
		exit(1);
	}
	map<int,int> lista;
	set<int> letras;
	//lista.insert(pair<int,string>(1,"andufala"));
	while(!archivo.eof()){
		string xs;
		getline(archivo,xs);
		int c=xs.length();
		letras.insert(c);
		//lista.insert(pair<int,string>(i,xs));
	}
	int b=0;
	for(set<int>::iterator it=letras.begin();it!=letras.end();it++){
		lista.insert(pair<int,int>(*it,b));	
	}
	ifstream buro;
	buro.open("english_words.txt");
	while(!buro.eof()){
		string ys;
		getline(buro,ys);
		int cont=ys.length();
		lista.find(cont)->second+=1;
	}
	
	for(map<int,int>::iterator it=lista.begin();it!=lista.end();++it){
		cout<<it->first<<"=>"<<it->second<<endl;
	}
	return 0;
}

