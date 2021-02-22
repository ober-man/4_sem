#include<iostream>

class Matrix
{
    private:
        double* elems;

    public:
        Matrix();
        Matrix(double arr[]);
        Matrix(double el0, double el1, double el2, double el3);
        ~Matrix();
        
        double determinant() const;

        friend Matrix operator + (const Matrix &m1, const Matrix &m2);
        friend Matrix operator - (const Matrix &m1, const Matrix &m2);
        friend Matrix operator * (const Matrix &m, double num);
        friend Matrix operator * (double num, const Matrix &m);
        friend Matrix operator * (const Matrix &m1, const Matrix &m2);
        
        #ifdef __VECTOR__
        friend Vector2D operator * (const Vector2D &vec, const Matrix &m);
        #endif // __VECTOR__

        friend Matrix operator + (const Matrix &m);
        friend Matrix operator - (const Matrix &m);

        friend Matrix operator ++ (Matrix &m, int); // postfix - return old version
        friend Matrix& operator ++ (Matrix &m); // prefix - return reference to transformed version
        friend Matrix operator -- (Matrix &m, int); // postfix
        friend Matrix& operator -- (Matrix &m); // prefix

        Matrix& operator = (const Matrix &m); // can't be friend because of interface
        friend Matrix& operator += (Matrix &m1, const Matrix &m2);
        friend Matrix& operator -= (Matrix &m1, const Matrix &m2);
        friend Matrix& operator *= (Matrix &m, double num);
        friend Matrix& operator *= (double num, Matrix &m);
        friend Matrix& operator *= (Matrix &m1, const Matrix &m2);
        
        #ifdef __VECTOR__
        friend Vector2D& operator *= (Vector2D &vec, const Matrix &m);
        #endif // __VECTOR__

        friend bool operator == (const Matrix &m1, const Matrix &m2);
        friend bool operator != (const Matrix &m1, const Matrix &m2);
        friend bool operator > (const Matrix &m1, const Matrix &m2);
        friend bool operator < (const Matrix &m1, const Matrix &m2);
        friend bool operator >= (const Matrix &m1, const Matrix &m2);
        friend bool operator <= (const Matrix &m1, const Matrix &m2);

        friend bool operator ! (const Matrix &m);
        friend bool operator && (const Matrix &m1, const Matrix &m2);
        friend bool operator || (const Matrix &m1, const Matrix &m2);

        friend std::ostream& operator << (std::ostream &out, const Matrix &m);
        friend std::istream& operator >> (std::istream &in, const Matrix &m);
};
