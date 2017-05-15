#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>

using namespace std;

class fraction {
protected:
	int m_num;
	int m_den;
public:
	void reduce(){
		int frac_gcd=gcd(this->m_num,this->m_den);
		m_num=m_num/frac_gcd;
		m_den=m_den/frac_gcd;
	}
	int gcd(int u,int v){
		if(v!=0){
			u%=v;
			return gcd(v,u);
		}
		else
		   return u;
	}
	fraction():m_num(1),m_den(1){}
	fraction(int num, int den):m_num(num),m_den(den){
		reduce();
	}
	
	void add(fraction other){
		if(other.getDenom()==this->getDenom()){
			int num=other.getNum()+this->getNum();
			setNum(num);
		}
		else{
			int num=this->getNum()*other.getDenom()+other.getNum()*this->getDenom();
			int den=this->getDenom()*other.getDenom();
			setNum(num);
			setDenom(den);
		}
		reduce();
	}
	void mult(fraction other){
		this->m_num *=other.getNum();
		this->m_den *=other.getDenom();
		reduce();
	}
	float decimal(){
		return (float)this->getNum()/(float)this->getDenom();
	}
	int getNum(){	return m_num;}
	int getDenom(){	return m_den;}
	void setNum(int num){	this->m_num=num;}
	void setDenom(int den){	this->m_den=den;}
	friend ostream& operator<<(ostream& out, fraction &frac){
		out << frac.m_num << "/" << frac.m_den;
		return out;
	}
	void reciprocal(){
		int temp=this->getDenom();
		setDenom(this->getNum());
		setNum(temp);
	}
	void divide(fraction other){
		this->m_num *=other.getDenom();
		this->m_den *=other.getNum();
		reduce();
	}
	friend bool operator== (fraction &m,fraction &o){
		o.reduce();
        m.reduce();
		if(m.getNum()==o.getNum() && m.getDenom()==o.getDenom()){
			return true;
		}
		else
		   return false;
	}
	friend bool operator!= (fraction &m, fraction &o){
		o.reduce();
        m.reduce();
		if(m.getNum()!=o.getNum() || m.getDenom()!=o.getDenom()){
			return true;
		}
		else
		   return false;
	}
	friend bool operator< (fraction &m, fraction &o){
		float a1=m.decimal();
		float a2=o.decimal();
		if(a1<a2)
			return true;
		else
			return false;
	}
	friend bool operator<= (fraction &m, fraction &o){
		float a1=m.decimal();
		float a2=o.decimal();
		if(a1<=a2)
			return true;
		else
			return false;
	}
	friend bool operator> (fraction &m, fraction &o){
		float a1=m.decimal();
		float a2=o.decimal();
		if(a1>a2)
			return true;
		else
			return false;
	}
	friend bool operator>= (fraction &m, fraction &o){
		float a1=m.decimal();
		float a2=o.decimal();
		if(a1>=a2)
			return true;
		else
			return false;
	}
};
#endif
