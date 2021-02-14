#include<iostream>
#include<cmath>
#include"complex.h"
using namespace math;

Complex::Complex()
{
    x = y = 0;
}

Complex::Complex(double x_, double y_)
{
    x = x_;
    y = y_;
}

Complex::Complex(double x_)
{
    x = y = x_;

}

void Complex::Print()
{
    std::cout << "(" << x << ") + (" << y << ")i" << std::endl;
}

double Complex::Get_x()
{
    return x;
}

double Complex::Get_y()
{
    return y;
}

void Complex::Set_x(double x_)
{
    x = x_;
}
void Complex::Set_y(double y_)
{
    y = y_;
}
void Complex::Set(double x_, double y_)
{
    x = x_;
    y = y_;
}

Complex* Complex::plus(Complex z)
{
    double x_ = z.Get_x();
    double y_ = z.Get_y();
    return new Complex(this->x + x_, this->y + y_);
}

Complex* Complex::minus(Complex z)
{
    double x_ = z.Get_x();
    double y_ = z.Get_y();
    return new Complex(this->x - x_, this->y - y_);
}

Complex* Complex::comp_mult(Complex z)
{
    double x_ = z.Get_x();
    double y_ = z.Get_y();
    return new Complex(this->x * x_ - this->y * y_, this->x * y_ + this->y * x_);
}

Complex* Complex::scal_mult(double num)
{
    return new Complex(x * num, y * num);
}

double Complex::abs()
{
    return sqrt(x*x + y*y);
}

Complex* Complex::conjugate()
{
    return new Complex(x, -y);
}
