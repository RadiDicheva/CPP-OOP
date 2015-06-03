#include <iostream>
#include <cmath>
#include "Manipulations.h"


 Complex::Complex()
 {
	 this->a=0;
	 this->b=0;
 }

 Complex::Complex(double real, double imaginary)
 {
	this->a = real;
	this->b = imaginary;
 }

  double Complex::Real() const
 {
	return this->a;
 }

  double Complex::Imaginary() const
 {
	return this->b;
 }
  
  Complex Complex::Conjugate() const
 {
	Complex conj;
	double x = this->a;
	double y = (this->b)*(-1);
	conj=Complex(x, y);
	return conj;
 }

   double Complex::Modulus() const
 {
	 return sqrt(pow(a,2)+pow(b,2));
 }

   Complex Complex::Power(double n) const
 {
	Complex p;
	p.a = pow(this->Modulus(),n)*(cos(this->Argument()*n));
	p.b = pow(this->Modulus(),n)*(sin(this->Argument()*n));
	return p;
 }

   Complex Complex::Root(double n, double k) const
 {
	 if (k<0 || k>n-1)
		 exit(1);
	 Complex r;
	 r.a=pow(this->Modulus(),1/n)*(cos(this->Argument()/n+2*k*PI/n));
	 r.b=pow(this->Modulus(),1/n)*(sin(this->Argument()/n+2*k*PI/n));
	 return r;
 }

  double Complex::Argument() const 
 {
	double arg = atan(b/a);
	return arg;
  }

   bool Complex::IsReal() const
 {
	if (b==0)
		return true;
	else return false;
 }

   Complex operator+(const Complex& p, const Complex& q)
   {
		Complex sum(p.Real()+q.Real(),p.Imaginary()+q.Imaginary());
		return sum;
   }

   Complex operator-(const Complex& p, const Complex& q)
   {
		Complex sub(p.Real()-q.Real(),p.Imaginary()-q.Imaginary());
		return sub;
   }

   Complex operator*(const Complex& p, const Complex& q)
   {
		Complex mult(p.Real()*q.Real()-p.Imaginary()*q.Imaginary(),p.Real()*q.Imaginary()+q.Real()*p.Imaginary());
		return mult;
   }

   Complex operator/(const Complex& p, const Complex& q)
   {
		Complex div((p.Real()*q.Real()+p.Imaginary()*q.Imaginary())/(q.Real()*q.Real()+q.Imaginary()*q.Imaginary()),(p.Imaginary()*q.Real()-p.Real()*q.Imaginary())/(q.Real()*q.Real()+q.Imaginary()*q.Imaginary()));
		return div;
   }

   Complex operator^(const Complex& number, double n)
   {
		Complex c(pow(number.Modulus(),n)*cos(n*number.Argument()),pow(number.Modulus(),n)*sin(n*number.Argument()));
		return c;
   }

   bool operator==(const Complex& lhs, const Complex& rhs)
   {
	   if (lhs.Real()==rhs.Real() && lhs.Imaginary()==rhs.Imaginary())
		   return true;
	   else return false;
   }

    bool operator!=(const Complex& lhs, const Complex& rhs)
   {
	   if (lhs.Real()!=rhs.Real() && lhs.Imaginary()!=rhs.Imaginary())
		   return true;
	   else return false;
   }

   std::istream& operator>>(std::istream& stream, Complex& number)
   {
	   std::cout << "Real number: ";
	   stream >> number.a;
	   std::cout << "Imaginary number: ";
	   stream >> number.b;
	   return stream;
   }

   std::ostream& operator<<(std::ostream& stream, const Complex& number)
   {
	   stream << number.Real();
	   if (number.Imaginary() >= 0)
		   stream << '+';
	   stream << number.Imaginary() << 'i' << std::endl;
	   return stream;
   }