#ifndef MANIPULATIONS_H_
#define MANIPULATIONS_H_

const double PI = 4.0*atan(1.0);

struct Complex
{
private:
	double a, b;
public:
    // Returns the number i (0 + i)
    static Complex GetI()
	{
		Complex i = Complex (0, 1);
		return i;	
	}

    // Constructs a default Complex number (0 + 0i)
    Complex();

    // Constructs a Complex number with predefined values (real + imaginary * i)
    Complex(double real, double imaginary);

    // Returns the real part of the complex number
    double Real() const;

    // Returns the imaginary part of the complex number
    double Imaginary() const;

    // Computes the conjugate () of the complex number
   Complex Conjugate() const;

    // Computes the modulus (distance to the center of the coordinate system) of the complex number
    double Modulus() const;

    // Computes the n-th power of the complex number. Use de Moivre's formulae
    Complex Power(double n) const;

    // Computes the k-th, n-th root of the complex number (remember that a complex number has multiple n-th roots, you should only return the root with index k, indices start from 0)
    Complex Root(double n, double k) const;

    // Computes the argument of the complex number (the angle between its radius-vector and Ox). Should be in the range [0; 2pi]
    double Argument() const;    

    // Returns true if the number is real (i.e. b = 0)
    bool IsReal() const;

	friend std::istream& operator>>(std::istream& stream, Complex& number);
	
};

Complex operator+(const Complex& p, const Complex& q);

	 Complex operator-(const Complex& p, const Complex& q);

	 Complex operator*(const Complex& p, const Complex& q);

	 Complex operator/(const Complex& p, const Complex& q);

	 Complex operator^(const Complex& number, double n);

	 bool operator==(const Complex& lhs, const Complex& rhs);

	 bool operator!=(const Complex& lhs, const Complex& rhs);

	 std::ostream& operator<<(std::ostream& stream, const Complex& number);

#endif