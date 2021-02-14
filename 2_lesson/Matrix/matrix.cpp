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

Matrix Matrix::operator + (Matrix m)
{
    for(int i = 0; i < 4; ++i)
        this->elems[i] += m.elems[i];
    return *this;
}

Matrix Matrix::operator - (Matrix m)
{
    for(int i = 0; i < 4; ++i)
        this->elems[i] -= m.elems[i];
    return *this;
}

Matrix Matrix::operator * (Matrix m)
{
    Matrix* res = new Matrix;
    res->elems[0] = this->elems[0] * m.elems[0] + this->elems[1] * m.elems[2];
    res->elems[1] = this->elems[0] * m.elems[1] + this->elems[1] * m.elems[3];
    res->elems[2] = this->elems[2] * m.elems[0] + this->elems[3] * m.elems[2];
    res->elems[3] = this->elems[2] * m.elems[1] + this->elems[3] * m.elems[3];
    return *res;
}

Matrix Matrix::operator * (double num)
{
    Matrix* res = new Matrix;
    for(int i = 0; i < 4; ++i)
        res->elems[i] = this->elems[i] * num;
    return *res;
}

double Matrix::determinant()
{
    return this->elems[0] * this->elems[3] - this->elems[1] * this->elems[2];
}

void Matrix::print()
{
    std::cout << elems[0] << " " << elems[1] << std::endl;
    std::cout << elems[2] << " " << elems[3] << std::endl;
}
