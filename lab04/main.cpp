#include "fraction.h"

int main (int argc, char *argv[]) {
	fraction a(1,5);
	fraction b(2,5);
	bool c;
    c = b>a;
    bool d;
    d= a>b;
	cout<<c<<d<<endl;
    float x=a.decimal();
    float y=b.decimal();
    cout<<x<<" "<<y<<endl;
    cout<<1/2.0<<endl;
	return 0;
}

