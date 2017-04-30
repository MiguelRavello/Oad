#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

string cesar(string &xs, int n){ //preg 1 codigo cesar
	int i=0;
	for(string::iterator it=xs.begin();it!=xs.end();it++){
		if(*it >= 'a' && *it <= 'z'){
			if(*(it) +n > 'z'){
				*it='a'-'z'+ *it + n - 1;
				xs[i]=*it;
				i++;
			}
			else if(*it + n < 'a'){
				*it='z'-'a' + *it + n + 1;
				xs[i]=*it;
				i++;
			}
			else{
				*it+=n;
				xs[i]=*it;
				i++;
			}
		}
		else if(*it >= 'A' && *it <= 'Z'){
			if(*(it) +n > 'Z'){
				*it='A'-'Z'+ *it + n - 1;
				xs[i]=*it;
				i++;
			}
			else if(*it + n < 'A'){
				*it='Z'-'A' + *it + n + 1;
				xs[i]=*it;
				i++;
			}
			else{
				*it+=n;
				xs[i]=*it;
				i++;
			}
		}
		else {
			xs[i]=*it;
			i++;
		}
	}
	return xs;
}

int main(){
	string a("abcd ABCD");
	string b=cesar(a,2);
	cout<<b<<endl;
	
	string c("abcd ABCD");
	string d=cesar(c,-2);
	cout<<d;
	
	return 0;
}
