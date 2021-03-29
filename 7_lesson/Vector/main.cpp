#include<iostream>
#include"vector.h"

#define EXCEPTION
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

    vector<int> g_vec = {1, 0, 1};
    vector<int> h_vec = {2, 2, 3};
    Vector<int, 3> g{g_vec};
    Vector<int, 3> h{h_vec};
    try
    {
        Vector<int, 3> vec = g ^ h;
        std::cout << "vector mult = " << vec;
        #ifdef EXCEPTION
        Vector<double, 2> bad_vec = a ^ b;
        #endif
    }
    catch(Exception ex)
    {
        std::cout << ex.what() << std::endl;
    }

    double sc = a * b;
    std::cout << "scalar a*b = " << sc << std::endl;

    return 0;
}
