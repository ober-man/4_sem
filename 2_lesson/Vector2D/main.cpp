#include<iostream>
#include"vector.h"

int main()
{
    Vector2D* a = new Vector2D(2);
    std::cout << "a (" << a->Get_x() << "," << a->Get_y() << ")" << std::endl;

    Vector2D* b = new Vector2D(1, 1);
    std::cout << "b (" << b->Get_x() << "," << b->Get_y() << ")" << std::endl;

    Vector2D d = *a + *b;
    std::cout << "sum (" << d.Get_x() << "," << d.Get_y() << ")" << std::endl;

    Vector2D e = *a - *b;
    std::cout << "difference (" << e.Get_x() << "," << e.Get_y() << ")" << std::endl;

    Vector2D f = *a * 5;
    std::cout << "5a (" << f.Get_x() << "," << f.Get_y() << ")" << std::endl;

    double sc = *a * *b;
    std::cout << "scalar a*b = " << sc << std::endl;

    delete a;
    delete b;
    return 0;
}
