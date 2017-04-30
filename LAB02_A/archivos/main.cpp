#include<iostream>
#include<fstream>
using namespace std;

int main () {
	ifstream archivo;
	archivo.open("prueba.c");
	
	ofstream kile;
	kile.open("rpta.c");
	
	if(archivo.fail()){
		cerr<<"error al abrir el archivo";
		exit(1);
	}
	bool estado=false;
	while(!archivo.eof()){
		string xs;
		getline(archivo,xs);
		if(estado==true){
			if(xs.find("*/")==string::npos){
				;
			}
			else{
				estado=false;
				cout<<xs.substr(xs.find("*/")+2)<<endl;
				kile<<xs.substr(xs.find("*/")+2)<<endl;
			}
		}
		else if(estado==false){
			if(xs.find("/*")==string::npos){
				if(xs.find("//")==string::npos){
					cout<<xs<<endl;
					kile<<xs<<endl;
				}
				else{
					int pos=xs.find("//");
					if(pos==0){
						;
					}
					else{
						string izq=xs.substr(0,xs.find("//")-1);
						cout<<izq<<endl;
						kile<<izq<<endl;
					}
				}
			}
			else{
				estado=true;
				if(xs.find("*/")==string::npos){
					int pos=xs.find("/*");
					if(pos==0){
						;
					}
					else{
						string izq=xs.substr(0,xs.find("/*")-1);
						cout<<izq<<endl;
						kile<<izq<<endl;
					}
				}
				else{
					estado=false;
					string izq=xs.substr(0,xs.find("/*")-1);
					string der=xs.substr(xs.find("*/")+2);
					cout<<izq<<der<<endl;
					kile<<izq<<der<<endl;
				}
			}
		}
	}
	
	return 0;
}

