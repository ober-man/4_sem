namespace math
{
    class Complex
    {
        private:
            double x;
            double y;

        public:
            Complex();
            Complex(double x_, double y_);
            Complex(double x_);

            void Print();
            double Get_x();
            double Get_y();
            void Set_x(double x_);
            void Set_y(double y_);
            void Set(double x_, double y_);

            Complex* plus(Complex z);
            Complex* minus(Complex z);
            Complex* comp_mult(Complex z);
            Complex* scal_mult(double num);
            double abs();
            Complex* conjugate();
    };
}
