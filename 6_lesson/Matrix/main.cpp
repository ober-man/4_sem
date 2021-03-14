#include"matrix.h"

int main()
{
    double elems1[2][3] = {1, 1, 1, 1, 1};
    double elems2[2][3] = {2, 2, 2, 2, 2};

    Matrix<double, 2, 3> m1{elems1};
    Matrix<double, 2, 3> m2{elems2};
    std::cout << "Matrix 1\n" << m1;
    std::cout << "Matrix 2\n" << m2;

    Matrix<double, 2, 3> m2_5 = m2;
    std::cout << "Matrix 2.5\n" << m2_5;

    Matrix<double, 2, 3> m3 = m1 + m2;
    std::cout << "Sum\n" << m3;

    Matrix<double, 2, 3> m4 = m1 - m2;
    std::cout << "Difference\n" << m4;

    Matrix<double, 3, 2> m2_t = m2.Transpose();
    std::cout << "Transpose m2\n" << m2_t;

    Matrix<double, 2, 2> m5 = m1 * m2_t;
    std::cout << "Composition\n" << m5;

    Matrix<double, 2, 3> m6 = m1 * 10;
    std::cout << "10*Matrix 1\n" << m6;

    return 0;
}

