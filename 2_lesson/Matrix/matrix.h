class Matrix
{
    private:
        double* elems;

    public:
        Matrix();
        Matrix(double arr[]);
        Matrix(double el0, double el1, double el2, double el3);
        ~Matrix();

        Matrix operator + (Matrix m);
        Matrix operator - (Matrix m);
        Matrix operator * (Matrix m);
        Matrix operator * (double num);
        double determinant();
        void print();
};
