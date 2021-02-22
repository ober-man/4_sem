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

Vector2D operator + (const Vector2D &vec1, const Vector2D &vec2)
{
    return Vector2D{vec1.x + vec2.x, vec1.y + vec2.y};
}

Vector2D operator - (const Vector2D &vec1, const Vector2D &vec2)
{
    return Vector2D{vec1.x - vec2.x, vec1.y - vec2.y};
}

Vector2D operator * (const Vector2D &vec, double num)
{
    return Vector2D{vec.x * num, vec.y * num};
}

Vector2D operator * (double num, const Vector2D &vec)
{
    return Vector2D{vec.x * num, vec.y * num};
}

double operator * (const Vector2D &vec1, const Vector2D &vec2)
{
    return vec1.x * vec2.x + vec1.y * vec2.y;
}

Vector2D operator + (const Vector2D &vec)
{
    return Vector2D{vec.x, vec.y};
}

Vector2D operator - (const Vector2D &vec)
{
    return Vector2D{-vec.x, -vec.y};
}

/// postfix - return old version
Vector2D operator ++ (Vector2D &vec, int)
{
    Vector2D res{vec.x, vec.y};
    vec.x++;
    vec.y++;
    return res;
}

/// prefix - return reference to transformed version
Vector2D& operator ++(Vector2D &vec)
{
    ++vec.x;
    ++vec.y;
    return vec;
}

/// postfix - return old version
Vector2D operator -- (Vector2D &vec, int)
{
    Vector2D res{vec.x, vec.y};
    vec.x--;
    vec.y--;
    return res;
}

/// prefix - return reference to transformed version
Vector2D& operator -- (Vector2D &vec)
{
    --vec.x;
    --vec.y;
    return vec;
}

Vector2D& Vector2D::operator = (const Vector2D &vec)
{
    this->x = vec.x;
    this->y = vec.y;
    return *this;
}

Vector2D& operator += (Vector2D &vec1, const Vector2D &vec2)
{
    vec1.x += vec2.x;
    vec1.y += vec2.y;
    return vec1;
}

Vector2D& operator -= (Vector2D &vec1, const Vector2D &vec2)
{
    vec1.x -= vec2.x;
    vec1.y -= vec2.y;
    return vec1;
}

Vector2D& operator *= (Vector2D &vec, double num)
{
    vec.x *= num;
    vec.y *= num;
    return vec;
}

Vector2D& operator *= (double num, Vector2D &vec)
{
    vec.x *= num;
    vec.y *= num;
    return vec;
}

bool operator == (const Vector2D &vec1, const Vector2D &vec2)
{
    return (vec1.x == vec2.x && vec1.y == vec2.y);
}

bool operator != (const Vector2D &vec1, const Vector2D &vec2)
{
    return (vec1.x != vec2.x || vec1.y != vec2.y);
}

bool operator > (const Vector2D &vec1, const Vector2D &vec2)
{
    return vec1.x * vec1.x + vec1.y * vec1.y > vec2.x * vec2.x + vec2.y * vec2.y;
}

bool operator < (const Vector2D &vec1, const Vector2D &vec2)
{
    return vec1.x * vec1.x + vec1.y * vec1.y < vec2.x * vec2.x + vec2.y * vec2.y;
}

bool operator >= (const Vector2D &vec1, const Vector2D &vec2)
{
    return vec1.x * vec1.x + vec1.y * vec1.y >= vec2.x * vec2.x + vec2.y * vec2.y;
}

bool operator <= (const Vector2D &vec1, const Vector2D &vec2)
{
    return vec1.x * vec1.x + vec1.y * vec1.y <= vec2.x * vec2.x + vec2.y * vec2.y;
}

//! @return 1, if x = y = 0
//!         0, else
bool operator ! (const Vector2D &vec)
{
    return (vec.x == 0 && vec.y == 0);
}

//! @return 0, if in each pair exist 0
//!         1, else
bool operator && (const Vector2D &vec1, const Vector2D &vec2)
{
    return ((vec1.x == 0 || vec2.x == 0) && (vec1.y == 0 || vec2.y == 0));
}

//! @return 1, if x1 or x2 or y1 or y2 != 0
//!         0, else
bool operator || (const Vector2D &vec1, const Vector2D &vec2)
{
    return (vec1.x != 0 || vec1.y != 0 || vec2.x != 0 || vec2.y != 0);
}

std::ostream& operator << (std::ostream &out, const Vector2D &vec)
{
    out << "(" << vec.x << " " << vec.y << ")" << std::endl;
    return out;
}

std::istream& operator >> (std::istream &in, const Vector2D &vec)
{
    in >> vec.x >> vec.y;
    return in;
}
