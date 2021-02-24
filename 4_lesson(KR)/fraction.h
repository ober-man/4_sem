#include<iostream>

/// model of rational fraction {m/n}
class Fraction
{
    private:
        int m;
        int n;

    public:
        Fraction();
        Fraction(int m_, int n_);
        Fraction(double num);

        int Integer() const;
        double Decimal() const;
        void Set(int m_, int n_);
        int Get_m() const;
        int Get_n() const;
        void Reduce();

        friend Fraction operator + (const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator - (const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator * (const Fraction &frac1, const Fraction &frac2);
        friend Fraction operator / (const Fraction &frac1, const Fraction &frac2);

        friend Fraction operator + (const Fraction &frac);
        friend Fraction operator - (const Fraction &frac);

        friend Fraction operator ++ (Fraction &frac, int); /// postfix - return old version
        friend Fraction& operator ++ (Fraction &frac); /// prefix - return reference to transformed version
        friend Fraction operator -- (Fraction &frac, int); /// postfix
        friend Fraction& operator -- (Fraction &frac); /// prefix

        Fraction& operator = (const Fraction &frac); // can't be friend because of interface
        Fraction& operator = (const int &num);
        Fraction& operator = (const double &num);
        friend Fraction& operator += (Fraction &frac1, const Fraction &frac2);
        friend Fraction& operator -= (Fraction &frac1, const Fraction &frac2);
        friend Fraction& operator *= (Fraction &frac1, const Fraction &frac2);
        friend Fraction& operator /= (Fraction &frac1, const Fraction &frac2);

        friend bool operator == (const Fraction &frac1, const Fraction &frac2);
        friend bool operator != (const Fraction &frac1, const Fraction &frac2);
        friend bool operator > (const Fraction &frac1, const Fraction &frac2);
        friend bool operator < (const Fraction &frac1, const Fraction &frac2);
        friend bool operator >= (const Fraction &frac1, const Fraction &frac2);
        friend bool operator <= (const Fraction &frac1, const Fraction &frac2);

        friend std::ostream& operator << (std::ostream &out, const Fraction &frac);
        friend std::istream& operator >> (std::istream &in, Fraction &frac);
};

int NOD(int a, int b);
const double eps = 1e-15;
