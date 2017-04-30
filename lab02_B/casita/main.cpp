#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int contador(string xs){
	int c=0;
	for(string::iterator it=xs.begin();it!=xs.end();it++){
		if(*it=='+'){
			if(*(it+1)=='-'){
				c++;	
			}
			else if(*(it+1)=='+'){}
			else{
				c++;
			}
		}
	}
	return c;
}

string lleno(string &str){
	string::iterator bt=str.begin();
	string::iterator ft=str.end();
	ft--;
	int conta=0;
	bool estado;
	string temp=str;
	int i=0;
	int len=str.length();
	len--;
	if(*bt=='+' && *ft=='+'){
		temp[i]='+';
		temp[len]='+';
		conta++;
		estado=true;
	}
	else if(*bt=='-' && *ft=='-'){
		estado=false;
		temp[i]='-';
		temp[len]='-';
	}
	i++;
	bt++;
	ft--;
	len--;
	while(bt!=ft){
		if(*bt=='-' && *ft=='-'){
			if(estado){
				*bt='+';
				*ft='+';
				temp[i]='+';
				temp[len]='+';
			}
			else if(!estado){
				*bt='-';
				*ft='-';
				temp[i]='-';
				temp[len]='-';
			}
		}
		else if(*bt=='+' && *ft=='+'){
			conta++;
			if(conta==2){
				break;
			}
			else if(estado){
				if(*(bt+1)=='-' && *(ft-1)=='-'){
					*bt='+';
					*ft='+';
					temp[i]='+';
					temp[len]='+';
					estado=false;
				}
				else if(*(bt+1)=='+' && *(ft-1)=='+')
				   ;
			}
			else if(!estado){
				*bt='+';
				*ft='+';
				temp[i]='+';
				temp[len]='+';
				estado=true;
			}
		}
		//cout<<str<<endl;
		bt++;
		ft--;
		i++;
		len--;
	}
	if(*bt=='-' && *ft=='-'){
		if(estado){
			*bt='+';
			*ft='+';
			temp[i]='+';
			temp[len]='+';
		}
		else if(!estado){
			*bt='-';
			*ft='-';
			temp[i]='-';
			temp[len]='-';
		}
	}
	return temp;
}

void rellenar(vector<string> &xs){
	for(vector<string>::iterator it=xs.begin();it!=xs.end();it++){
		string ss=lleno(*it);
		cout<<ss<<endl;
	}
}
	

int main (int argc, char *argv[]) {
	ifstream archivo;
	archivo.open("draw.in");
	if(archivo.fail()){
		cerr<<"error";
		exit(1);
	}
	vector<string> lista;
	while(!archivo.eof()){
		string xs;
		getline(archivo,xs);
		lista.push_back(xs);
		int c=contador(xs);
		cout<<xs<<" : "<<c<<endl;
	}

	rellenar(lista);
	
	return 0;
}

