#include<iostream>
#include"vector.h"

int main()
{
    Vector<double, 2> a{2};
    std::cout << "a" << a;

    Vector<double, 2> b{1};
    std::cout << "b" << b;

    Vector<double, 2> c = b;
    std::cout << "c" << c;

    Vector<double, 2> d = a + b;
    std::cout << "sum " << d;

    Vector<double, 2> e = a - b;
    std::cout << "difference " << e;

    Vector<double, 2> f = a * 5;
    std::cout << "5a " << f;

    double g_arr[] = {1, 0, 1};
    double h_arr[] = {2, 2, 3};
    Vector<double, 3> g{g_arr};
    Vector<double, 3> h{h_arr};
    Vector<double, 3> vec = g ^ h;
    std::cout << "vector mult = " << vec;

    double sc = a * b;
    std::cout << "scalar a*b = " << sc << std::endl;

    return 0;
}
