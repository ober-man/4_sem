#include<iostream>

class Vector2D
{
    private:
        double x,y;

    public:
        Vector2D();
        Vector2D(double x_);
        Vector2D(double x_, double y_);

        void Set(double x_, double y_);
        double Get_x();
        double Get_y();

        friend Vector2D operator + (const Vector2D &vec1, const Vector2D &vec2);
        friend Vector2D operator - (const Vector2D &vec1, const Vector2D &vec2);
        friend Vector2D operator * (const Vector2D &vec, double num);
        friend Vector2D operator * (double num, const Vector2D &vec);
        friend double operator * (const Vector2D &vec1, const Vector2D &vec2);

        friend Vector2D operator + (const Vector2D &vec);
        friend Vector2D operator - (const Vector2D &vec);

        friend Vector2D operator ++ (Vector2D &vec, int); /// postfix - return old version
        friend Vector2D& operator ++ (Vector2D &vec); /// prefix - return reference to transformed version
        friend Vector2D operator -- (Vector2D &vec, int); /// postfix
        friend Vector2D& operator -- (Vector2D &vec); /// prefix

        Vector2D& operator = (const Vector2D &vec); // can't be friend because of interface
        friend Vector2D& operator += (Vector2D &vec1, const Vector2D &vec2);
        friend Vector2D& operator -= (Vector2D &vec1, const Vector2D &vec2);
        friend Vector2D& operator *= (Vector2D &vec, double num);
        friend Vector2D& operator *= (double num, Vector2D &vec);

        friend bool operator == (const Vector2D &vec1, const Vector2D &vec2);
        friend bool operator != (const Vector2D &vec1, const Vector2D &vec2);
        friend bool operator > (const Vector2D &vec1, const Vector2D &vec2);
        friend bool operator < (const Vector2D &vec1, const Vector2D &vec2);
        friend bool operator >= (const Vector2D &vec1, const Vector2D &vec2);
        friend bool operator <= (const Vector2D &vec1, const Vector2D &vec2);

        friend bool operator ! (const Vector2D &vec);
        friend bool operator && (const Vector2D &vec1, const Vector2D &vec2);
        friend bool operator || (const Vector2D &vec1, const Vector2D &vec2);

        friend std::ostream& operator << (std::ostream &out, const Vector2D &vec);
        friend std::istream& operator >> (std::istream &in, const Vector2D &vec);
};
