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

        Vector2D times(double a);
        double times(Vector2D a);

        Vector2D operator + (Vector2D vec);
        Vector2D operator - (Vector2D vec);
        Vector2D operator * (double num);
        double operator * (Vector2D vec);

};
