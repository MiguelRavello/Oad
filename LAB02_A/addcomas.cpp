#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string addcomas(string &xs){ // anhadir comas pregunta 2
	int i=0;
	int c=0;
	for(string::iterator it=xs.end();it!=xs.begin();it--){
		if(i==0){
			i++;
		}
		else if(i%3 == 0){
			xs=xs.substr(0,xs.length()-i-c)+","+xs.substr(xs.length()-i-c);
			i++;
			c++;
		}
		else if(*it==','){
			continue;
		}
		else
				i++;
	}
	return xs;
	
}

int main(){
	string a("123456789");
	string b=addcomas(a);
	cout<<b;
	return 0;
}
