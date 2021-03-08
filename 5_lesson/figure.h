#include<iostream>
#include<math.h>
const double PI = 3.14;

class Point final
{
    private:
        double x;
        double y;

    public:
        Point() : x(0), y(0) {};
        Point(double val) : x(val), y(val) {};
        Point(double x_, double y_) : x(x_), y(y_) {};
        void Set(double x_, double y_);
        double Get_x() const;
        double Get_y() const;
        friend std::ostream& operator << (std::ostream &out, const Point& dot);
};

class Figure
{
    protected:
        int num;
        Point* vertex;

    public:
        Figure() : num(0) {};
        Figure(int num_);
        Figure(int num_, Point* vertex_);
        Point* Get_Points();
        void Set_Points(Point* vertex_);
        virtual double Perimeter() const = 0;
        virtual double Area() const = 0;
        virtual ~Figure() {delete [] vertex;}
};

class Circle final : public Figure
{
    private:
        double rad;

    public:
        Circle(): Figure{1}, rad(1) {};
        Circle(Point* centre_, double rad_) : Figure{1, centre_}, rad(rad_) {};
        double Get_rad() const;
        void Set_rad(double rad_);
        double Perimeter() const override {return 2 * PI * rad;}
        double Area() const override {return PI * rad * rad;}
};

class Triangle final : public Figure
{
    private:
        double a;
        double b;
        double c;

    public:
        Triangle() : Figure{3}, a(0), b(0), c(0) {};
        Triangle(Point vertex_[3]);
        double Perimeter() const override {return a + b + c;}
        double Area() const override
        {
            double p = Perimeter() / 2;
            return sqrt(p*(p - a)*(p - b)*(p - c));
        }
};

class Quadrangle : public Figure
{
    protected:
        double a;
        double b;
        double c;
        double d;

    public:
        Quadrangle() : Figure{4}, a(0), b(0), c(0), d(0) {};
        Quadrangle(Point vertex_[4]);
        virtual double Perimeter() const override {return a + b + c + d;}

        /// accepting that quadrangle can be inscribed in a circle
        virtual double Area() const override
        {
            double p = Perimeter() / 2;
            return sqrt((p - a)*(p - b)*(p - c)*(p - d));
        }
};

class Rectangle : public Quadrangle
{
    public:
        Rectangle() : Quadrangle() {};
        Rectangle(Point vertex_[2]);
        double Perimeter() const override {return 2*(a + b);}

        /// accepting that quadrangle can be inscribed in a circle
        double Area() const override {return a * b;}
};

class Square final : public Rectangle
{
    public:
        Square() : Rectangle() {};
        Square(Point vertex_[2]);
        double Perimeter() const override {return 4 * a;}

        /// accepting that quadrangle can be inscribed in a circle
        double Area() const override {return a * a;}
};
