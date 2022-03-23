#include "Complex.h"

bool double_equals(double l, double r)
{
    return abs(l - r) < 0.001;
}

Complex operator+(const Complex& l, const Complex& r)
{
    return Complex(l.real() + r.real(), l.imag() + r.imag());
}

Complex operator+(const Complex& l, double r)
{
    return l + Complex(r, 0);
}

Complex operator+(double l, const Complex& r)
{
    return Complex(l,0) + r;
}

Complex operator-(const Complex& l, const Complex& r)
{
    return Complex(l.real() - r.real(), l.imag() - r.imag());
}

Complex operator-(const Complex& l, double r)
{
    return l - Complex(r, 0);
}

Complex operator-(double l, const Complex& r)
{
    return Complex(l, 0) - r;
}

Complex operator*(const Complex& l, const Complex& r)
{
    return Complex(l.real() * r.real() - l.imag() * r.imag(), (l.real() * r.imag() + r.real()*l.imag()));
}

Complex operator*(const Complex& l, double r)
{
    return l * Complex(r, 0);
}

Complex operator*(double l, const Complex& r)
{
    return Complex(l, 0) * r;
}

Complex operator-(const Complex& obj)
{
    return Complex(-obj.real(), -obj.imag());
}

bool operator==(const Complex& l, const Complex& r)
{
    return (l.real() == r.real() && l.imag() == r.imag());
}

bool operator!=(const Complex& l, const Complex& r)
{
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex)
{
    if (complex.real() == 0 && complex.imag() == 0)
        return out;
    if (complex.is_real())
        out << complex.real();
    else
    {
        if (complex.real() == 0)
        {
            out << complex.imag() << "i";
        }
        else
        {
            out << complex.real() << " " << complex.imag() <<'i';
        }
    }
    return out;
}

Complex::Complex() : Complex(0, 0) { }

Complex::Complex(double real, double imag)
{
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const
{
    return imag() == 0;
}

double Complex::real() const
{
    return real_data;
}

Complex& Complex::Set(double real, double imag)
{
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

double Complex::imag() const
{
    return imag_data;
}

double Complex::abs() const
{
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const
{
    return { real(), -imag() };
}

Complex& Complex::operator--()
{
    Set(real()-1, imag());
    return *this;
}

Complex& Complex::operator--(int)
{
    Complex copy = *this;
    --(*this);
    return copy;
}

Complex& Complex::operator++()
{
    Set(real() + 1, imag());
    return *this;
}

Complex& Complex::operator++(int)
{
    Complex copy = *this;
    ++(*this);
    return copy;
}

Complex& Complex::operator()(double real, double imag)
{
    Set(real, imag);
    return *this;
}
