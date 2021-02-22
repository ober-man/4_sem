#include<iostream>
#include"vector.h"

int main()
{
    Vector2D a{2};
    std::cout << "a" << a;

    Vector2D b{1, 1};
    std::cout << "b" << b;

    Vector2D c = b;
    std::cout << "c" << c;

    Vector2D d = a + b;
    std::cout << "sum " << d;

    Vector2D e = a - b;
    std::cout << "difference " << e;

    Vector2D f = a * 5;
    std::cout << "5a " << f;

    Vector2D g = a++;
    std::cout << "g " << g;
    std::cout << "a " << a;

    Vector2D h = ++a;
    std::cout << "h " << h;
    std::cout << "a " << a;

    Vector2D i = b--;
    std::cout << "i " << i;
    std::cout << "b " << b;

    Vector2D j = --b;
    std::cout << "j " << j;
    std::cout << "b " << b;

    double sc = a * b;
    std::cout << "scalar a*b = " << sc << std::endl;

    return 0;
}
