#include<iostream>
#include"matrix.h"

int main()
{
    double elems1[4] = {1, 1, 1, 1};
    double elems2[4] = {2, 2, 2, 2};

    Matrix m1{elems1};
    Matrix m2{elems2};
    std::cout << "Matrix 1\n" << m1;
    std::cout << "Matrix 2\n" << m2;

    Matrix m2_5 = m2;
    std::cout << "Matrix 2.5\n" << m2_5;

    Matrix m3 = m1 + m2;
    std::cout << "Sum\n" << m3;

    Matrix m4 = m1 - m2;
    std::cout << "Difference\n" << m4;

    Matrix m5 = m1 * m2;
    std::cout << "Composition\n" << m5;

    Matrix m6 = m1 * 10;
    std::cout << "10*Matrix 1\n" << m6;

    double det = m1.determinant();
    std::cout << "det(m1) = " << det << std::endl;

    return 0;
}
