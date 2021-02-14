#include<iostream>
#include"matrix.h"

int main()
{
    double elems1[4] = {1, 1, 1, 1};
    double elems2[4] = {2, 2, 2, 2};

    Matrix* m1 = new Matrix{elems1};
    Matrix* m2 = new Matrix{elems2};
    std::cout << "Matrix 1" << std::endl;
    m1->print();
    std::cout << "Matrix 2" << std::endl;
    m2->print();

    Matrix m3 = *m1 + *m2;
    std::cout << "Sum" << std::endl;
    m3.print();

    Matrix m4 = *m1 - *m2;
    std::cout << "Difference" << std::endl;
    m4.print();

    Matrix m5 = *m1 * *m2;
    std::cout << "Composition" << std::endl;
    m5.print();

    Matrix m6 = *m1 * 10;
    std::cout << "10*Matrix 1" << std::endl;
    m6.print();

    double det = m1->determinant();
    std::cout << "det(m1) = " << det << std::endl;

    delete m1;
    delete m2;
    return 0;
}
