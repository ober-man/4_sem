#include<iostream>
#include"matrix.h"

Matrix::Matrix()
{
    elems = new double(4);
}

Matrix::Matrix(double arr[])
{
    elems = new double(4);
    for(int i = 0; i < 4; ++i)
        this->elems[i] = arr[i];
}

Matrix::Matrix(double el0, double el1, double el2, double el3)
{
    elems = new double(4);
    elems[0] = el0;
    elems[1] = el1;
    elems[2] = el2;
    elems[3] = el3;
}

Matrix::~Matrix()
{
    delete [] elems;
}

double Matrix::determinant() const
{
    return this->elems[0] * this->elems[3] - this->elems[1] * this->elems[2];
}

#include"matrix.h"

Matrix operator + (const Matrix &m1, const Matrix &m2)
{
    Matrix res;
    for(int i = 0; i < 4; ++i)
        res.elems[i] = m1.elems[i] + m2.elems[i];
    return res;
}

Matrix operator - (const Matrix &m1, const Matrix &m2)
{
    Matrix res;
    for(int i = 0; i < 4; ++i)
        res.elems[i] = m1.elems[i] - m2.elems[i];
    return res;
}

Matrix operator * (const Matrix &m, double num)
{
    Matrix res;
    for(int i = 0; i < 4; ++i)
        res.elems[i] = m.elems[i] * num;
    return res;
}

Matrix operator * (double num, const Matrix &m)
{
    Matrix res;
    for(int i = 0; i < 4; ++i)
        res.elems[i] = m.elems[i] * num;
    return res;
}

Matrix operator * (const Matrix &m1, const Matrix &m2)
{
    Matrix res;
    res.elems[0] = m1.elems[0] * m2.elems[0] + m1.elems[1] * m2.elems[2];
    res.elems[1] = m1.elems[0] * m2.elems[1] + m1.elems[1] * m2.elems[3];
    res.elems[2] = m1.elems[2] * m2.elems[0] + m1.elems[3] * m2.elems[2];
    res.elems[3] = m1.elems[2] * m2.elems[1] + m1.elems[3] * m2.elems[3];
    return res;
}

#ifdef __VECTOR__
Vector2D operator * (const Vector2D &vec, const Matrix &m)
{
    Vector2D res;
    res.x = vec.x * m.elems[0] + vec.y * m.elems[2];
    res.y = vec.x * m2.elems[1] + vec.y * m2.elems[3];
    return res;
}
#endif // __VECTOR__

Matrix operator + (const Matrix &m)
{
    return Matrix{m.elems};
}

Matrix operator - (const Matrix &m)
{
    return Matrix{-m.elems};
}

// postfix - return old version
Matrix operator ++ (Matrix &m, int)
{
    Matrix res{m.elems};
    for(int i = 0; i < 4; ++i)
        m.elems[i]++;
    return res;
}

// prefix - return reference to transformed version
Matrix& operator ++(Matrix &m)
{
    for(int i = 0; i < 4; ++i)
        m.elems[i]++;
    return m;
}

// postfix - return old version
Matrix operator -- (Matrix &m, int)
{
    Matrix res{m.elems};
    for(int i = 0; i < 4; ++i)
        m.elems[i]--;
    return res;
}

// prefix - return reference to transformed version
Matrix& operator -- (Matrix &m)
{
    for(int i = 0; i < 4; ++i)
        m.elems[i]--;
    return m;
}

Matrix& Matrix::operator = (const Matrix &m)
{
    for(int i = 0; i < 4; ++i)
        this->elems[i] = m.elems[i];
    return *this;
}

Matrix& operator += (Matrix &m1, const Matrix &m2)
{
    for(int i = 0; i < 4; ++i)
        m1.elems[i] += m2.elems[i];
    return m1;
}

Matrix& operator -= (Matrix &m1, const Matrix &m2)
{
    for(int i = 0; i < 4; ++i)
        m1.elems[i] -= m2.elems[i];
    return m1;
}

Matrix& operator *= (Matrix &m, double num)
{
    for(int i = 0; i < 4; ++i)
        m.elems[i] *= num;
    return m;
}

Matrix& operator *= (double num, Matrix &m)
{
    for(int i = 0; i < 4; ++i)
        m.elems[i] *= num;
    return m;
}

Matrix& operator *= (Matrix &m1, const Matrix &m2)
{
    Matrix res;
    res.elems[0] = m1.elems[0] * m2.elems[0] + m1.elems[1] * m2.elems[2];
    res.elems[1] = m1.elems[0] * m2.elems[1] + m1.elems[1] * m2.elems[3];
    res.elems[2] = m1.elems[2] * m2.elems[0] + m1.elems[3] * m2.elems[2];
    res.elems[3] = m1.elems[2] * m2.elems[1] + m1.elems[3] * m2.elems[3];
    m1 = res;
    return m1;
}

#ifdef __VECTOR__
Vector2D& operator *= (Vector2D &vec, const Matrix &m)
{
    Vector2D res;
    res.x = vec.x * m.elems[0] + vec.y * m.elems[2];
    res.y = vec.x * m2.elems[1] + vec.y * m2.elems[3];
    vec = res;
    return vec;
}
#endif // __VECTOR__

bool operator == (const Matrix &m1, const Matrix &m2)
{
    for(int i = 0; i < 4; ++i)
        if(m1.elems[i] != m2.elems[i])
            return false;
    return true;
}

bool operator != (const Matrix &m1, const Matrix &m2)
{
    for(int i = 0; i < 4; ++i)
        if(m1.elems[i] != m2.elems[i])
            return true;
    return false;
}

bool operator > (const Matrix &m1, const Matrix &m2)
{
    return m1.determinant() < m2.determinant();
}

bool operator < (const Matrix &m1, const Matrix &m2)
{
    return m1.determinant() > m2.determinant();
}

bool operator >= (const Matrix &m1, const Matrix &m2)
{
    return m1.determinant() >= m2.determinant();
}

bool operator <= (const Matrix &m1, const Matrix &m2)
{
    return m1.determinant() <= m2.determinant();
}

//! @return 1, if all elements = 0
//!         0, else
bool operator ! (const Matrix &m)
{
    for(int i = 0; i < 4; ++i)
        if(m.elems[i] != 0)
            return false;
    return true;
}

//! @return 0, if in each pair exist 0
//!         1, else
bool operator && (const Matrix &m1, const Matrix &m2)
{
    for(int i = 0; i < 4; ++i)
        if(!(m1.elems[i] == 0 || m2.elems[i] == 0))
            return true;
    return false;
}

//! @return 1, if exist non-zero element
//!         0, else
bool operator || (const Matrix &m1, const Matrix &m2)
{
    for(int i = 0; i < 4; ++i)
        if(m1.elems[i] != 0 || m2.elems[i] != 0)
            return true;
    return false;
}

std::ostream& operator << (std::ostream &out, const Matrix &m)
{
    out << m.elems[0] << " " << m.elems[1] << "\n" << m.elems[2] << " " << m.elems[3] << std::endl;
    return out;
}

std::istream& operator >> (std::istream &in, const Matrix &m)
{
    in >> m.elems[0] >> m.elems[1] >> m.elems[2] >> m.elems[3];
    return in;
}
