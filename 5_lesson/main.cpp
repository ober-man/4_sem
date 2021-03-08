#include <iostream>
#include"Figure.h"

int main()
{
    Point dot{0.5, 1.0};
    Figure* c = new Circle{&dot, 10};
    std::cout << "Circle: " << std::endl;
    std::cout << "Area: " << c->Area() << std::endl;
    std::cout << "Perimeter: " << c->Perimeter() << std::endl;
    std::cout << "Center: " << *(c->Get_Points()) << std::endl;
    delete c;

    Point t_arr[3] = {{0,0}, {0,1}, {1,0}};
    Figure* t = new Triangle{t_arr};
    std::cout << "Triangle: " << std::endl;
    std::cout << "Area: " << t->Area() << std::endl;
    std::cout << "Perimeter: " << t->Perimeter() << std::endl;
    std::cout << "\n";
    delete t;

    Point q_arr[4] = {{0,0}, {0,1}, {1,1}, {1,0}};
    Figure* q = new Quadrangle{q_arr};
    std::cout << "Quadrangle: " << std::endl;
    std::cout << "Area: " << q->Area() << std::endl;
    std::cout << "Perimeter: " << q->Perimeter() << std::endl;
    std::cout << "\n";
    delete q;

    Point r_arr[2] = {{0,0}, {1,2}};
    Figure* r = new Rectangle{r_arr};
    std::cout << "Rectangle: " << std::endl;
    std::cout << "Area: " << r->Area() << std::endl;
    std::cout << "Perimeter: " << r->Perimeter() << std::endl;
    std::cout << "\n";
    delete r;

    Point s_arr[2] = {{0,0}, {1,1}};
    Figure* s = new Square{s_arr};
    std::cout << "Square: " << std::endl;
    std::cout << "Area: " << s->Area() << std::endl;
    std::cout << "Perimeter: " << s->Perimeter() << std::endl;
    std::cout << "\n";
    delete s;
    return 0;
}
