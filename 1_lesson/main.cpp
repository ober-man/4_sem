#include"complex.h"
#include<iostream>
using namespace math;

int main()
{
    math::Complex* z1 = new math::Complex(1);
    std::cout << "z1 = ";
    z1->Print();

    math::Complex* z2 = new math::Complex(1, 2);
    std::cout << "z2 = ";
    z2->Print();

    math::Complex* z3 = z1->plus(*z2);
    std::cout << "Sum: z3 = z1 + z2 = ";
    z3->Print();

    math::Complex* z4 = z1->minus(*z2);
    std::cout << "Difference: z4 = z1 - z2 = ";
    z4->Print();

    math::Complex* z5 = z1->comp_mult(*z2);
    std::cout << "Complex composition: z5 = z1 * z2 = ";
    z5->Print();

    math::Complex* z6 = z1->scal_mult(5);
    std::cout << "Scalar composition: z6 = 5z1 = ";
    z6->Print();

    math::Complex* z7 = z1->conjugate();
    std::cout << "Conjugate: z7 = z1* = ";
    z7->Print();

    double modul = z1->abs();
    std::cout << "Module: |z1| = " << modul;

    delete z1;
    delete z2;
    delete z3;
    delete z4;
    delete z5;
    delete z6;
    delete z7;
    return 0;
}
