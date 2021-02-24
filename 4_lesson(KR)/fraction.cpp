#include"fraction.h"
#include<assert.h>

int NOD(int a, int b)
{
    while (a && b)
        if (a >= b)
           a %= b;
        else
           b %= a;
    return a | b;
}

Fraction::Fraction()
{
    m = 0;
    n = 1;
}

Fraction::Fraction(int m_, int n_)
{
    assert(n_ != 0);
    m = m_;
    n = n_;
    this->Reduce();
}

//!@note eps defined at "fraction.h"
//!          as a very small numeral
//!          to compare double-s
Fraction::Fraction(double num)
{
    int len = 0; // number of numerals after comma
    while(num * 10 - static_cast<int>(num) * 10 > eps)
    {
        num *= 10;
        ++len;
    }
    m = num;
    n = 1;
    for(int i = 0; i < len; ++i)
        n *= 10;
    this->Reduce();
}

 //!@return integer part of fraction
int Fraction::Integer() const
{
    assert(n != 0);
    return m / n;
}

//!@return decimal representation
double Fraction::Decimal() const
{
    assert(n != 0);
    return static_cast<double> (m) / n;
}

void Fraction::Set(int m_, int n_)
{
    assert(this->n != 0);
    assert(n_ != 0);
    m = m_;
    n = n_;
    this->Reduce();
}

int Fraction::Get_m() const
{
    assert(n != 0);
    return this->m;
}

int Fraction::Get_n() const
{
    assert(n != 0);
    return this->n;
}

/// reduce the fraction
void Fraction::Reduce()
{
    assert(n != 0);
    bool zf = false;
    if(m * n < 0)
        zf = true;
    int nod = NOD(abs(m), abs(n));
    m /= nod;
    n /= nod;
    if(zf)
    {
        n = abs(n);
        m = - abs(m);
    }
    else
    {
        n = abs(n);
        m = abs(m);
    }
}

Fraction operator + (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res{frac1.m * frac2.n + frac2.m * frac1.n, frac1.n * frac2.n};
    res.Reduce();
    return res;
}

Fraction operator - (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res{frac1.m * frac2.n - frac2.m * frac1.n, frac1.n * frac2.n};
    res.Reduce();
    return res;
}

Fraction operator * (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res{frac1.m * frac2.m, frac1.n * frac2.n};
    res.Reduce();
    return res;
}

Fraction operator / (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res{frac1.m * frac2.n, frac1.n * frac2.m};
    res.Reduce();
    return res;
}

Fraction operator + (const Fraction &frac)
{
    assert(frac.n != 0);
    Fraction res{frac.m, frac.n};
    res.Reduce();
    return res;
}

Fraction operator - (const Fraction &frac)
{
    assert(frac.n != 0);
    Fraction res{-frac.m, frac.n};
    res.Reduce();
    return res;
}

/// postfix - return old version
Fraction operator ++ (Fraction &frac, int)
{
    assert(frac.n != 0);
    Fraction res{frac.m, frac.n};
    frac.m += frac.n;
    frac.Reduce();
    return res;
}

/// prefix - return reference to transformed version
Fraction& operator ++(Fraction &frac)
{
    assert(frac.n != 0);
    frac.m += frac.n;
    frac.Reduce();
    return frac;
}

/// postfix - return old version
Fraction operator -- (Fraction &frac, int)
{
    assert(frac.n != 0);
    Fraction res{frac.m, frac.n};
    frac.m -= frac.n;
    frac.Reduce();
    return res;
}

/// prefix - return reference to transformed version
Fraction& operator -- (Fraction &frac)
{
    assert(frac.n != 0);
    frac.m -= frac.n;
    frac.Reduce();
    return frac;
}

Fraction& Fraction::operator = (const Fraction &frac)
{
    assert(this->n != 0);
    assert(frac.n != 0);
    this->m = frac.m;
    this->n = frac.n;
    this->Reduce();
    return *this;
}

Fraction& Fraction::operator = (const int &num)
{
    assert(this->n != 0);
    this->m = num;
    this->n = 1;
    this->Reduce();
    return *this;
}

Fraction& Fraction::operator = (const double &num)
{
    assert(this->n != 0);
    Fraction res{num};
    *this = res;
    this->Reduce();
    return *this;
}

Fraction& operator += (Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    frac1.m = frac1.m * frac2.n + frac2.m * frac1.n;
    frac1.n *= frac2.n;
    frac1.Reduce();
    return frac1;
}

Fraction& operator -= (Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    frac1.m = frac1.m * frac2.n - frac2.m * frac1.n;
    frac1.n *= frac2.n;
    frac1.Reduce();
    return frac1;
}

Fraction& operator *= (Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    frac1.m *= frac2.m;
    frac1.n *= frac2.n;
    frac1.Reduce();
    return frac1;
}

Fraction& operator /= (Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    frac1.m *= frac2.n;
    frac1.n *= frac2.m;
    frac1.Reduce();
    return frac1;
}

bool operator == (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    return (frac1.m == frac2.m && frac1.n == frac2.n);
}

bool operator != (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    return (frac1.m != frac2.m || frac1.n != frac2.n);
}

bool operator > (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res = frac1 - frac2;
    res.Reduce();
    assert(res.n != 0);
    return res.m > 0;
}

bool operator < (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res = frac1 - frac2;
    res.Reduce();
    assert(res.n != 0);
    return res.m < 0;
}

bool operator >= (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res = frac1 - frac2;
    res.Reduce();
    assert(res.n != 0);
    return res.m >= 0;
}

bool operator <= (const Fraction &frac1, const Fraction &frac2)
{
    assert(frac1.n != 0);
    assert(frac2.n != 0);
    Fraction res = frac1 - frac2;
    res.Reduce();
    assert(res.n != 0);
    return res.m <= 0;
}

std::ostream& operator << (std::ostream &out, const Fraction &frac)
{
    assert(frac.n != 0);
    out << frac.m << "/" << frac.n << std::endl;
    return out;
}

std::istream& operator >> (std::istream &in, Fraction &frac)
{
    in >> frac.m >> frac.n;
    assert(frac.n != 0);
    frac.Reduce();
    return in;
}
