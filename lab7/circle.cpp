#include<iostream>
#include<iomanip> //setprecision(x) cifras significativas
#include<cmath>
using namespace std;

const double pi = 3.1415926535897;

struct Punto{
    int m_x;
    int m_y;
    Punto():m_x(0), m_y(0){}
    Punto(int a, int b):m_x(a),m_y(b){}
    Punto(Punto &m){
        m_x=m.m_x;
        m_y=m.m_y;
    }
};

class Circle {
private:
    Punto m_inicial;
    Punto m_final;
    double m_radio;
    double m_perimetro;
    double m_area;
public:
    Circle():m_inicial(0,0),m_final(0,0),m_radio(0),m_perimetro(0),m_area(0){}
    Circle(int xo,int yo, int xf, int yf):m_inicial(xo,yo),m_final(xf,yf){
        setCircle();
    }
    Circle(Punto o,Punto f):m_inicial(o),m_final(f){
        setCircle();
    }
    Circle(Circle &c){
        m_inicial=c.getPuntoA();
        m_final=c.getPuntoB();
        m_radio=c.getRadius();
        m_perimetro=c.getCircunferencia();
        m_area=c.getArea();
    }

    void setCircle(){
        double rpta;
        rpta=sqrt(pow(m_final.m_x-m_inicial.m_x,2)+pow(m_final.m_y-m_inicial.m_y,2));
        m_radio=rpta;
        m_perimetro=2*pi*m_radio;
        m_area=pi*pow(m_radio,2);
    }

    double getCircunferencia(){ return m_perimetro;}
    double getRadius(){ return m_radio;}
    double getArea(){   return m_area;}
    Punto getPuntoA(){  return m_inicial;}
    Punto getPuntoB(){  return m_final;}
// returna una representación string tal como &quot;Circulo{radius=2.5}&quot;
    string toString(){
        double Number = this->getRadius();//number to convert int a string
        string Result;//string which will contain the result
        stringstream convert; // stringstream used for the conversion
        convert << Number;//add the value of Number to the characters in the stream
        Result = convert.str();
        Result = "&quot;Circulo{radius="+Result+"}&quot";
        return Result;
    }
};

int main(){
    Punto p;
    Punto q(2,2);
    Circle a(p,q);
    string r=a.toString();
    cout<<r<<endl;
    cout<<"area: "<<a.getArea()<<"u^2"<<endl;
    cout<<"perimetro: "<<a.getCircunferencia()<<"u"<<endl;
    return 0;
}
