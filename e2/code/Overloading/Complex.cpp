#include <iostream>

double real;
double imag;

using namespace std;


/*
The Complex Object provides methods for math operations with complex numbers.
In addition it also overloads the operators for those operations.
*/

class Complex
{
    public:
        Complex(double real, double imag);
        double real;
        double imag;
};


Complex::Complex(double r, double i)
{
    this->real = r;
    this->imag = i;
}

// ---------------- OPERATION FUNCTIONS -------------------- //

Complex add(Complex a, Complex b)
{
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex subtract(Complex a, Complex b)
{
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex multiply(Complex a, Complex b)
{
    return Complex(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag * b.real);
}

Complex divide(Complex a, Complex b)
{
    return Complex((a.real*b.real + a.imag*b.imag) / (b.real*b.real + b.imag* b.imag),
    (a.imag*b.real - a.real*b.imag) / (b.real*b.real + b.imag* b.imag));
}

Complex conjugate(Complex a)
{
    return Complex(a.real, -a.imag);
}

// ---------------- OPERATOR OVERLOADING -------------------- //

Complex operator+(Complex a, Complex b)
{
    return Complex(a.real + b.real, a.imag + b.imag);
}

Complex operator-(Complex a, Complex b)
{
    return Complex(a.real - b.real, a.imag - b.imag);
}

Complex operator*(Complex a, Complex b)
{
    return Complex(a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag * b.real);
}

Complex operator/(Complex a, Complex b)
{
    return Complex((a.real*b.real + a.imag*b.imag) / (b.real*b.real + b.imag* b.imag),
    (a.imag*b.real - a.real*b.imag) / (b.real*b.real + b.imag* b.imag));
}

Complex operator!(Complex a)
{
    return Complex(a.real, -a.imag);
}

ostream& operator<<(ostream& os, const Complex& a) 
{
    if (a.imag >= 0)
    {
        return os << a.real << " + " << a.imag << "i";
    }
    else
    {
        return os << a.real << " - " << -a.imag << "i";
    }

}

int main()
{
    // test operation functions
    Complex a = Complex(1, 5);
    Complex b = Complex(5, 3);
    Complex c = Complex(2,-3);
    Complex d = Complex(2,-4);

    Complex result = subtract(a, divide(add(b, c), d));
   
    cout << result << endl;


    // test operator overloading
    cout << "Operator overloading : " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Addition : a + b = " << a + b << endl;
    cout << "Subtraction: a - b = " << a - b << endl;
    cout << "Multiplication : a * b = " << a * b << endl;
    cout << "Division : a / b = " << a / b << endl; 
    cout << "Conjugation : a= " << a << " and a! = "<< !a << endl;
    
    
    return 0;
}