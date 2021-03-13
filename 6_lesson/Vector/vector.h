#include<iostream>

template<typename T, int n>
class Vector
{
    private:
        T x[n];

    public:
        Vector();
        Vector(T x_);
        Vector(T x_[]);

        void Set(T x_[]);
        T* Get();

        template<typename U, int m> friend Vector<U, m> operator + (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend Vector<U, m> operator - (const Vector<U, m> &vec1, const Vector<U, m> &vec2);

        template<typename U, int m> friend Vector<U, m> operator * (const Vector<U, m> &vec, double num);
        template<typename U, int m> friend Vector<U, m> operator * (double num, const Vector<U, m> &vec);
        template<typename U, int m> friend double operator * (const Vector<U, m> &vec1, const Vector<U, m> &vec2); /// scalar
        template<typename U, int m> friend Vector<U, m> operator ^ (const Vector<U, m> &vec1, const Vector<U, m> &vec2); /// vector

        template<typename U, int m> friend Vector<U, m> operator + (const Vector<U, m> &vec);
        template<typename U, int m> friend Vector<U, m> operator - (const Vector<U, m> &vec);

        template<typename U, int m> friend Vector<U, m> operator ++ (Vector<U, m> &vec, int); /// postfix - return old version
        template<typename U, int m> friend Vector<U, m>& operator ++ (Vector<U, m> &vec); /// prefix - return reference to transformed version
        template<typename U, int m> friend Vector<U, m> operator -- (Vector<U, m> &vec, int); /// postfix
        template<typename U, int m> friend Vector<U, m>& operator -- (Vector<U, m> &vec); /// prefix

        Vector<T, n>& operator = (const Vector<T, n> &vec); // can't be friend because of interface
        template<typename U, int m> friend Vector<U, m>& operator += (Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend Vector<U, m>& operator -= (Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend Vector<U, m>& operator *= (Vector<U, m> &vec, double num);
        template<typename U, int m> friend Vector<U, m>& operator *= (double num, Vector<U, m> &vec);

        template<typename U, int m> friend bool operator == (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend bool operator != (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend bool operator > (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend bool operator < (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend bool operator >= (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend bool operator <= (const Vector<U, m> &vec1, const Vector<U, m> &vec2);

        template<typename U, int m> friend bool operator ! (const Vector<U, m> &vec);
        template<typename U, int m> friend bool operator && (const Vector<U, m> &vec1, const Vector<U, m> &vec2);
        template<typename U, int m> friend bool operator || (const Vector<U, m> &vec1, const Vector<U, m> &vec2);

        template<typename U, int m> friend std::ostream& operator << (std::ostream &out, const Vector<U, m> &vec);
        template<typename U, int m> friend std::istream& operator >> (std::istream &in, const Vector<U, m> &vec);
};

template<typename T, int n>
Vector<T, n>::Vector()
{
    for(int i = 0; i < n; ++i)
        x[i] = 0;
}

template<typename T, int n>
Vector<T, n>::Vector(T x_)
{
    for(int i = 0; i < n; ++i)
        x[i] = x_;
}

template<typename T, int n>
Vector<T, n>::Vector(T x_[])
{
    for(int i = 0; i < n; ++i)
        x[i] = x_[i];
}

template<typename T, int n>
void Vector<T, n>::Set(T x_[])
{
    for(int i = 0; i < n; ++i)
        x[i] = x_[i];
}

template<typename T, int n>
T* Vector<T, n>::Get()
{
    return x;
}

template<typename U, int m>
Vector<U, m> operator + (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    U arr[m] = {};
    for(int i = 0; i < m; ++i)
        arr[i] = vec1.x[i] + vec2.x[i];
    return Vector<U, m>{arr};
}

template<typename U, int m>
Vector<U, m> operator - (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    U arr[m] = {};
    for(int i = 0; i < m; ++i)
        arr[i] = vec1.x[i] - vec2.x[i];
    return Vector<U, m>{arr};
}

template<typename U, int m>
Vector<U, m> operator * (const Vector<U, m> &vec, double num)
{
    U arr[m] = {};
    for(int i = 0; i < m; ++i)
        arr[i] = vec.x[i] * num;
    return Vector<U, m>{arr};
}

template<typename U, int m>
Vector<U, m> operator * (double num, const Vector<U, m> &vec)
{
    U arr[m] = {};
    for(int i = 0; i < m; ++i)
        arr[i] = vec.x[i] * num;
    return Vector<U, m>{arr};
}

template<typename U, int m>
/// scalar multiplication
double operator * (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    int sum = 0;
    for(int i = 0; i < m; ++i)
        sum += vec1.x[i] * vec2.x[i];
    return sum;
}

template<typename U, int m>
/// vector multiplication
Vector<U, m> operator ^ (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    if(m != 3)
        return Vector<U, m>{};
    U x = vec1.x[1] * vec2.x[2] - vec1.x[2] * vec2.x[1];
    U y = - vec1.x[0] * vec2.x[2] + vec1.x[2] * vec2.x[0];
    U z = vec1.x[0] * vec2.x[1] - vec1.x[1] * vec2.x[0];
    U arr[3] = {x, y, z};
    return Vector<U, m>{arr};
}

template<typename U, int m>
Vector<U, m> operator + (const Vector<U, m> &vec)
{
    U arr[m] = {};
    for(int i = 0; i < m; ++i)
        arr[i] = vec.x[i];
    return Vector<U, m>{arr};
}

template<typename U, int m>
Vector<U, m> operator - (const Vector<U, m> &vec)
{
    U arr[m] = {};
    for(int i = 0; i < m; ++i)
        arr[i] = -vec.x[i];
    return Vector<U, m>{arr};
}

/// postfix - return old version
template<typename U, int m>
Vector<U, m> operator ++ (Vector<U, m> &vec, int)
{
    Vector<U, m> res = vec;
    for(int i = 0; i < m; ++i)
        ++vec.x[i];
    return res;
}

/// prefix - return reference to transformed version
template<typename U, int m>
Vector<U, m>& operator ++(Vector<U, m> &vec)
{
    for(int i = 0; i < m; ++i)
        ++vec.x[i];
    return vec;
}

/// postfix - return old version
template<typename U, int m>
Vector<U, m> operator -- (Vector<U, m> &vec, int)
{
    Vector<U, m> res = vec;
    for(int i = 0; i < m; ++i)
        --vec.x[i];
    return res;
}

/// prefix - return reference to transformed version
template<typename U, int m>
Vector<U, m>& operator -- (Vector<U, m> &vec)
{
    for(int i = 0; i < m; ++i)
        --vec.x[i];
    return vec;
}

template<typename T, int n>
Vector<T, n>& Vector<T, n>::operator = (const Vector<T, n> &vec)
{
    for(int i = 0; i < n; ++i)
        this->x[i] = vec.x[i];
    return *this;
}

template<typename U, int m>
Vector<U, m>& operator += (Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    vec1 = vec1 + vec2;
    return vec1;
}

template<typename U, int m>
Vector<U, m>& operator -= (Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    vec1 = vec1 - vec2;
    return vec1;
}

template<typename U, int m>
Vector<U, m>& operator *= (Vector<U, m> &vec, double num)
{
    vec = vec * num;
    return vec;
}

template<typename U, int m>
Vector<U, m>& operator *= (double num, Vector<U, m> &vec)
{
    vec = num * vec;
    return vec;
}

template<typename U, int m>
bool operator == (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    for(int i = 0; i < m; ++i)
        if(vec1.x[i] != vec2.x[i])
            return false;
    return true;
}

template<typename U, int m>
bool operator != (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    for(int i = 0; i < m; ++i)
        if(vec1.x[i] != vec2.x[i])
            return true;
    return false;
}

template<typename U, int m>
bool operator > (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    U len1 = 0, len2 = 0;
    for(int i = 0; i < m; ++i)
    {
        len1 += vec1.x[i] * vec1.x[i];
        len2 += vec2.x[i] * vec2.x[i];
    }
    return len1 > len2;
}

template<typename U, int m>
bool operator < (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    U len1 = 0, len2 = 0;
    for(int i = 0; i < m; ++i)
    {
        len1 += vec1.x[i] * vec1.x[i];
        len2 += vec2.x[i] * vec2.x[i];
    }
    return len1 < len2;
}

template<typename U, int m>
bool operator >= (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    U len1 = 0, len2 = 0;
    for(int i = 0; i < m; ++i)
    {
        len1 += vec1.x[i] * vec1.x[i];
        len2 += vec2.x[i] * vec2.x[i];
    }
    return len1 >= len2;
}

template<typename U, int m>
bool operator <= (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    U len1 = 0, len2 = 0;
    for(int i = 0; i < m; ++i)
    {
        len1 += vec1.x[i] * vec1.x[i];
        len2 += vec2.x[i] * vec2.x[i];
    }
    return len1 <= len2;
}

//! @return 1, if x[0] = ... = x[m-1] = 0
//!         0, else
template<typename U, int m>
bool operator ! (const Vector<U, m> &vec)
{
    for(int i = 0; i < m; ++i)
        if(vec.x[i] != 0)
            return false;
    return true;
}

//! @return 0, if in each pair exist 0
//!         1, else
template<typename U, int m>
bool operator && (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    for(int i = 0; i < m; ++i)
        if(vec1.x[i] && vec2.x[i])
            return true;
    return false;
}

//! @return 1, if some element != 0
//!         0, else
template<typename U, int m>
bool operator || (const Vector<U, m> &vec1, const Vector<U, m> &vec2)
{
    for(int i = 0; i < m; ++i)
        if(vec1.x[i] || vec2.x[i])
            return true;
    return false;
}

template<typename U, int m>
std::ostream& operator << (std::ostream &out, const Vector<U, m> &vec)
{
    out << "(";
    for(int i = 0; i < m; ++i)
        if(i == m-1)
            out << vec.x[i];
        else
            out << vec.x[i] << " ";
    out << ")" << std::endl;
    return out;
}

template<typename U, int m>
std::istream& operator >> (std::istream &in, const Vector<U, m> &vec)
{
    for(int i = 0; i < m; ++i)
        in >> vec.x[i];
    return in;
}
