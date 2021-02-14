#include"vector.h"

Vector2D::Vector2D()
{
    x = y = 0;
}

Vector2D::Vector2D(double x_)
{
    x = y = x_;
}

Vector2D::Vector2D(double x_, double y_)
{
    x = x_;
    y = y_;
}

void Vector2D::Set(double x_, double y_)
{
    x = x_;
    y = y_;
}

double Vector2D::Get_x()
{
    return x;
}

double Vector2D::Get_y()
{
    return y;
}

Vector2D Vector2D::times(double a)
{
    this->x *= a;
    this->y *= a;
    return *this;
}

double Vector2D::times(Vector2D a)
{
    return this->x * a.x + this->y * a.y;
}

Vector2D Vector2D::operator + (Vector2D vec)
{
    Vector2D* res = new Vector2D(this->x + vec.x, this->y + vec.y);
    return *res;
}

Vector2D Vector2D::operator - (Vector2D vec)
{
    Vector2D* res = new Vector2D(this->x - vec.x, this->y - vec.y);
    return *res;
}

Vector2D Vector2D::operator * (double num)
{
    Vector2D* res = new Vector2D(this->x * num, this->y * num);
    return *res;
}

double Vector2D::operator * (Vector2D vec)
{
    return this->x * vec.x + this->y * y;
}


Vector2D sum(Vector2D one, Vector2D two)
{
    Vector2D* three = new Vector2D;
    double one_x = one.Get_x();
    double one_y = one.Get_y();
    double two_x = two.Get_x();
    double two_y = two.Get_y();

    three->Set(one_x + two_x, one_y + two_y);
    return *three;
}

double sum(double x, double y)
{
    return x + y;
}
