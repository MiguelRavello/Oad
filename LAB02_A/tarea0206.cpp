#include<iostream>
#include<stack>
#include<string>
using namespace std;


template<class T>
void roll(stack<T> & xs,int n,int k){
	if(n<0 || k<0){
		cout<<"argumento de error";	
	}
	else{
		stack<T> temp;
		if(n<k){
			k=k%2;
			if(k==0)
				;
			else{
				for(int i=0;i<n;i++){
					T cs=xs.top();
					temp.push(cs);
					xs.pop();
				}
				for(int j=0;j<n;j++){
					T rs=temp.top();
					xs.push(rs);
					temp.pop();
				}
			}
		}
		else{
			T reten;
			for(int i=1;i<=n;i++){
				if(i==k){
					reten=xs.top();
					xs.pop();
					continue;
				}
				T cs=xs.top();
				temp.push(cs);
				xs.pop();
			}
			k=k%2;
			xs.push(reten);
			if(k==0){
				stack<T> temp2;
				while(!temp.empty()){
					T cs=temp.top();
					temp2.push(cs);
					temp.pop();
				}
				while(!temp2.empty()){
					T ps=temp2.top();
					xs.push(ps);
					temp2.pop();
				}
			}
			else{
				while(!temp.empty()){
					T cs=temp.top();
					xs.push(cs);
					temp.pop();
				}
			}
		}
	}
	
}

int main() {
	stack<char> a;
	a.push('a');
	a.push('b');
	a.push('c');
	a.push('d');
	roll(a,4,1);
	while(!a.empty()){
		cout<<a.top()<<endl;
		a.pop();
	}
	cout<<"........................."<<endl;
	stack<char> b;
	b.push('a');
	b.push('b');
	b.push('c');
	b.push('d');
	roll(b,3,2);
	while(!b.empty()){
		cout<<b.top()<<endl;
		b.pop();
	}
	cout<<"........................."<<endl;
	stack<char> c;
	c.push('a');
	c.push('b');
	c.push('c');
	c.push('d');
	roll(c,2,4);
	while(!c.empty()){
		cout<<c.top()<<endl;
		c.pop();
	}
	
	return 0;
}

