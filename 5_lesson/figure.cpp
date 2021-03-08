#include"Figure.h"

///////////////////Point//////////////////////////////
void Point::Set(double x_, double y_)
{
    x = x_;
    y = y_;
}

double Point::Get_x() const
{
    return x;
}

double Point::Get_y() const
{
    return y;
}

std::ostream& operator << (std::ostream &out, const Point& dot)
{
    out << "(" << dot.Get_x() << "; " << dot.Get_y() << ")" << std::endl;
    return out;
}


///////////////////Figure//////////////////////////////
Figure::Figure(int num_) : num(num_)
{
    vertex = new Point[num_];
    for(int i = 0; i < num; ++i)
        vertex[i].Set(0, 0);
}

Figure::Figure(int num_, Point* vertex_) : num(num_)
{
    vertex = new Point[num_];
    for(int i = 0; i < num; ++i)
        vertex[i].Set(vertex_[i].Get_x(), vertex_[i].Get_y());
}

Point* Figure::Get_Points()
{
    Point* arr = new Point[num];
    for(int i = 0; i < num; ++i)
        arr[i] = vertex[i];
    return arr;
}

void Figure::Set_Points(Point* vertex_)
{
    for(int i = 0; i < num; ++i)
        vertex[i] = vertex_[i];
}


///////////////////Circle//////////////////////////////
double Circle::Get_rad() const
{
    return rad;
}

void Circle::Set_rad(double rad_)
{
    rad = rad_;
}


///////////////////Triangle//////////////////////////////
Triangle::Triangle(Point vertex_[3]) : Figure{3, vertex_}
{
    // hypot is a function returning length of a hypotenuse
    a = hypot(vertex[0].Get_x() - vertex[1].Get_x(), vertex[0].Get_y() - vertex[1].Get_y());
    b = hypot(vertex[1].Get_x() - vertex[2].Get_x(), vertex[1].Get_y() - vertex[2].Get_y());
    c = hypot(vertex[2].Get_x() - vertex[0].Get_x(), vertex[2].Get_y() - vertex[0].Get_y());
}


///////////////////Quadrangle//////////////////////////////
Quadrangle::Quadrangle(Point vertex_[4]) : Figure{4, vertex_}
{
    a = hypot(vertex[0].Get_x() - vertex[1].Get_x(), vertex[0].Get_y() - vertex[1].Get_y());
    b = hypot(vertex[1].Get_x() - vertex[2].Get_x(), vertex[1].Get_y() - vertex[2].Get_y());
    c = hypot(vertex[2].Get_x() - vertex[3].Get_x(), vertex[2].Get_y() - vertex[3].Get_y());
    d = hypot(vertex[3].Get_x() - vertex[0].Get_x(), vertex[3].Get_y() - vertex[0].Get_y());
}


///////////////////Rectangle//////////////////////////////
Rectangle::Rectangle(Point vertex_[2])
{
    Quadrangle();
    Point v3 = {vertex_[0].Get_x(), vertex_[1].Get_y()};
    Point v4 = {vertex_[1].Get_x(), vertex_[0].Get_y()};
    Point new_vertex[4] = {vertex_[0], vertex_[1], v3, v4};
    Set_Points(new_vertex);
    a = abs(vertex[0].Get_y() - vertex[1].Get_y());
    b = abs(vertex[0].Get_x() - vertex[1].Get_x());
    c = a;
    d = b;
}

///////////////////Square//////////////////////////////
Square::Square(Point vertex_[2])
{
    Rectangle();
    Point v3 = {vertex_[0].Get_x(), vertex_[1].Get_y()};
    Point v4 = {vertex_[1].Get_x(), vertex_[0].Get_y()};
    Point new_vertex[4] = {vertex_[0], vertex_[1], v3, v4};
    Set_Points(new_vertex);
    a = abs(vertex[0].Get_x() - vertex[1].Get_x());
    b = a;
    c = a;
    d = b;
}
