#include<iostream>

template<typename T, int m, int n>
class Matrix
{
    private:
        T elems[m][n];

    public:
        Matrix();
        Matrix(T arr[m][n]);
        T ElementSum() const;
        T Get(int a, int b) const;
        T** Get() const;
        void Set(T elem, int a, int b);
        void Set(T arr[m][n]);
        Matrix<T, n, m> Transpose();

        template<typename U, int a, int b> friend Matrix<U, a, b> operator + (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend Matrix<U, a, b> operator - (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend Matrix<U, a, b> operator * (const Matrix<U, a, b> &m1, double num);
        template<typename U, int a, int b> friend Matrix<U, a, b> operator * (double num, const Matrix<U, a, b> &m1);
        template<typename U, int a, int b, int c> friend Matrix<U, a, b> operator * (const Matrix<U, a, c> &m1, const Matrix<U, c, b> &m2);
        #ifdef __VECTOR__
        template<typename U, int a, int b> friend Vector2D operator * (const Vector2D &vec, const Matrix<U, a, b> &m1);
        #endif // __VECTOR__

        template<typename U, int a, int b> friend Matrix<U, a, b> operator + (const Matrix<U, a, b> &m1);
        template<typename U, int a, int b> friend Matrix<U, a, b> operator - (const Matrix<U, a, b> &m1);

        template<typename U, int a, int b> friend Matrix<U, a, b> operator ++ (Matrix<U, a, b> &m1, int); /// postfix - return old version
        template<typename U, int a, int b> friend Matrix<U, a, b>& operator ++ (Matrix<U, a, b> &m1); /// prefix - return reference to transformed version
        template<typename U, int a, int b> friend Matrix<U, a, b> operator -- (Matrix<U, a, b> &m1, int); /// postfix
        template<typename U, int a, int b> friend Matrix<U, a, b>& operator -- (Matrix<U, a, b> &m1); /// prefix

        Matrix<T, m, n>& operator = (const Matrix<T, m, n> &m1); // can't be friend because of interface
        template<typename U, int a, int b> friend Matrix<U, a, b>& operator += (Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend Matrix<U, a, b>& operator -= (Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend Matrix<U, a, b>& operator *= (Matrix<U, a, b> &m1, double num);
        template<typename U, int a, int b> friend Matrix<U, a, b>& operator *= (double num, Matrix<U, a, b> &m1);
        template<typename U, int a, int b, int c> friend Matrix<U, a, b>& operator *= (Matrix<U, a, c> &m1, const Matrix<U, c, b> &m2);
        #ifdef __VECTOR__
        template<typename U, int a, int b> friend Vector2D& operator *= (Vector2D &vec, const Matrix<U, a, b> &m1);
        #endif // __VECTOR__

        template<typename U, int a, int b> friend bool operator == (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend bool operator != (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend bool operator > (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend bool operator < (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend bool operator >= (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend bool operator <= (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);

        template<typename U, int a, int b> friend bool operator ! (const Matrix<U, a, b> &m1);
        template<typename U, int a, int b> friend bool operator && (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);
        template<typename U, int a, int b> friend bool operator || (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2);

        template<typename U, int a, int b> friend std::ostream& operator << (std::ostream &out, const Matrix<U, a, b> &m1);
        template<typename U, int a, int b> friend std::istream& operator >> (std::istream &in, const Matrix<U, a, b> &m1);
};

template<typename T, int m, int n>
Matrix<T, m, n>::Matrix()
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            elems[i][j] = 0;
}

template<typename T, int m, int n>
Matrix<T, m, n>::Matrix(T arr[m][n])
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            this->elems[i][j] = arr[i][j];
}

template<typename T, int m, int n>
T Matrix<T, m, n>::ElementSum() const
{
    T sum = 0;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            sum += elems[i][j];
    return sum;
}

template<typename T, int m, int n>
T Matrix<T, m, n>::Get(int a, int b) const
{
    return elems[a][b];
}

template<typename T, int m, int n>
T** Matrix<T, m, n>::Get() const
{
    return elems;
}

template<typename T, int m, int n>
void Matrix<T, m, n>::Set(T elem, int a, int b)
{
    elems[a][b] = elem;
}

template<typename T, int m, int n>
void Matrix<T, m, n>::Set(T arr[m][n])
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            this->elems[i][j] = arr[i][j];
}

template<typename T, int m, int n>
Matrix<T, n, m> Matrix<T, m, n>::Transpose()
{
    Matrix<T, n, m> res;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            res.Set(elems[j][i], i, j);
    return res;
}

template<typename U, int a, int b>
Matrix<U, a, b> operator + (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    Matrix<U, a, b> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            res.elems[i][j] = m1.elems[i][j] + m2.elems[i][j];
    return res;
}

template<typename U, int a, int b>
Matrix<U, a, b> operator - (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    Matrix<U, a, b> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            res.elems[i][j] = m1.elems[i][j] - m2.elems[i][j];
    return res;
}

template<typename U, int a, int b>
Matrix<U, a, b> operator * (const Matrix<U, a, b> &m1, double num)
{
    Matrix<U, a, b> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            res.elems[i][j] = m1.elems[i][j] * num;
    return res;
}

template<typename U, int a, int b>
Matrix<U, a, b> operator * (double num, const Matrix<U, a, b> &m1)
{
    Matrix<U, a, b> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            res.elems[i][j] = num * m1.elems[i][j];
    return res;
}

template<typename U, int a, int b, int c>
Matrix<U, a, b> operator * (const Matrix<U, a, c> &m1, const Matrix<U, c, b> &m2)
{
    Matrix<U, a, b> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            for(int k = 0; k < c; ++k)
                res.elems[i][j] += m1.elems[i][k] * m2.elems[k][j];
    return res;
}

#ifdef __VECTOR__
template<typename U, int a, int b, typename T>
Vector operator * (const Vector<T, b> &vec, const Matrix<U, a, b> &m1)
{
    Vector<T, a> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            res[i] += m1.elems[i][j] * vec.x[j];
    return res;
}
#endif // __VECTOR__

template<typename U, int a, int b>
Matrix<U, a, b> operator + (const Matrix<U, a, b> &m1)
{
    return Matrix<U, a, b>{m1.elems};
}

template<typename U, int a, int b>
Matrix<U, a, b> operator - (const Matrix<U, a, b> &m1)
{
    return Matrix<U, a, b>{-m1.elems};
}

/// postfix - return old version
template<typename U, int a, int b>
Matrix<U, a, b> operator ++ (Matrix<U, a, b> &m1, int)
{
    Matrix<U, a, b> res{m1.elems};
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            m1.elems[i][j]++;
    return res;
}

/// prefix - return reference to transformed version
template<typename U, int a, int b>
Matrix<U, a, b>& operator ++(Matrix<U, a, b> &m1)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            ++m1.elems[i][j];
    return m1;
}

/// postfix - return old version
template<typename U, int a, int b>
Matrix<U, a, b> operator -- (Matrix<U, a, b> &m1, int)
{
    Matrix<U, a, b> res{m1.elems};
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            m1.elems[i][j]--;
    return res;
}

/// prefix - return reference to transformed version
template<typename U, int a, int b>
Matrix<U, a, b>& operator -- (Matrix<U, a, b> &m1)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            --m1.elems[i][j];
    return m1;
}

template<typename T, int m, int n>
Matrix<T, m, n>& Matrix<T, m, n>::operator = (const Matrix<T, m, n> &m1)
{
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            this->elems[i][j] = m1.elems[i][j];
    return *this;
}

template<typename U, int a, int b>
Matrix<U, a, b>& operator += (Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            m1.elems[i][j] += m1.elems[i][j];
    return m1;
}

template<typename U, int a, int b>
Matrix<U, a, b>& operator -= (Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            m1.elems[i][j] -= m1.elems[i][j];
    return m1;
}

template<typename U, int a, int b>
Matrix<U, a, b>& operator *= (Matrix<U, a, b> &m1, double num)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            m1.elems[i][j] *= num;
    return m1;
}

template<typename U, int a, int b>
Matrix<U, a, b>& operator *= (double num, Matrix<U, a, b> &m1)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            m1.elems[i][j] *= num;
    return m1;
}

template<typename U, int a, int b, int c>
Matrix<U, a, b>& operator *= (Matrix<U, a, c> &m1, const Matrix<U, c, b> &m2)
{
    Matrix<U, a, b> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            for(int k = 0; k < c; ++k)
                res.elems[i][j] += m1.elems[i][k] * m2.elems[k][j];
    m1 = res;
    return m1;
}

#ifdef __VECTOR__
template<typename U, int a, int b, typename T>
Vector2D& operator *= (Vector<T, b> &vec, const Matrix<U, a, b> &m1)
{
    Vector<T, a> res;
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            res[i] += m1.elems[i][j] * vec.x[j];
    vec = res;
    return vec;
}
#endif // __VECTOR__

template<typename U, int a, int b>
bool operator == (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            if(m1.elems[i][j] != m2.elems[i][j])
                return false;
    return true;
}

template<typename U, int a, int b>
bool operator != (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            if(m1.elems[i][j] != m2.elems[i][j])
                return true;
    return false;
}

template<typename U, int a, int b>
bool operator > (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    return m1.ElementSum() < m2.ElementSum();
}

template<typename U, int a, int b>
bool operator < (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    return m1.ElementSum() > m2.ElementSum();
}

template<typename U, int a, int b>
bool operator >= (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    return m1.ElementSum() >= m2.ElementSum();
}

template<typename U, int a, int b>
bool operator <= (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    return m1.ElementSum() <= m2.ElementSum();
}

//! @return 1, if all elements = 0
//!         0, else
template<typename U, int a, int b>
bool operator ! (const Matrix<U, a, b> &m1)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            if(m1.elems[i][j] != 0)
                return false;
    return true;
}

//! @return 0, if in each pair exist 0
//!         1, else
template<typename U, int a, int b>
bool operator && (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            if(m1.elems[i][j] && m2.elems[i][j])
                return true;
    return true;
}

//! @return 1, if exist non-zero element
//!         0, else
template<typename U, int a, int b>
bool operator || (const Matrix<U, a, b> &m1, const Matrix<U, a, b> &m2)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            if(m1.elems[i][j] || m2.elems[i][j])
                return true;
    return false;
}

template<typename U, int a, int b>
std::ostream& operator << (std::ostream &out, const Matrix<U, a, b> &m1)
{
    for(int i = 0; i < a; ++i)
    {
        for(int j = 0; j < b; ++j)
            out << m1.elems[i][j] << " ";
        out << "\n";
    }
    return out;
}

template<typename U, int a, int b>
std::istream& operator >> (std::istream &in, const Matrix<U, a, b> &m1)
{
    for(int i = 0; i < a; ++i)
        for(int j = 0; j < b; ++j)
            in >> m1.elems[i][j];
    return in;
}
