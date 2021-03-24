#pragma once
#include<iostream>
#include<vector>
#include"time.h"
#include"exception.h"

using std::vector;
using std::string;

template<typename T>
class Lesson
{
    private:
        T time;
        vector<string> names;

    public:
        Lesson(T t) : time(t) {};
        Lesson(T t, vector<string> vec);
        T Get_time() const;
        vector<string> Get_names() const;
        void Set(T t);
        void Add(string name);
        template<typename U> friend Lesson<U> operator + (const U& t1, const U& t2);
        template<typename U> friend Lesson<U> operator + (const Lesson<U>& t1, const Lesson<U>& t2);
        template<typename U> friend Lesson<U> operator - (const U& t1, const U& t2);
        template<typename U> friend Lesson<U> operator - (const Lesson<U>& t1, const Lesson<U>& t2);
        template<typename U> friend std::ostream& operator << (std::ostream &out, const Lesson<U>& t);
};

template<typename T>
Lesson<T>::Lesson(T t, vector<string> vec)
{
    time = t;
    size_t len = vec.size();
    for(size_t i = 0; i < len; ++i)
        names.push_back(vec[i]);
}

template<typename T>
T Lesson<T>::Get_time() const
{
    return time;
}

template<typename T>
vector<string> Lesson<T>::Get_names() const
{
    return names;
}

template<typename T>
void Lesson<T>::Set(T t)
{
    time = t;
}

template<typename T>
void Lesson<T>::Add(string name)
{
    if(name.size() > 20)
        throw Exception{"Error: name must be shorter than 20 symbols!"};
    names.push_back(name);
}

template<typename U>
Lesson<U> operator + (const U& t1, const U& t2)
{
    return Lesson<U>{t1 + t2};
}

template<typename U>
Lesson<U> operator + (const Lesson<U>& t1, const Lesson<U>& t2)
{
    Lesson<U> res{t1.time + t2.time};
    size_t len1 = t1.names.size();
    for(size_t i = 0; i < len1; ++i)
        res.names.push_back(t1.names[i]);

    size_t len2 = t2.names.size();
    for(size_t i = 0; i < len2; ++i)
        res.names.push_back(t2.names[i]);
    return res;
}

template<typename U>
Lesson<U> operator - (const U& t1, const U& t2)
{
    return Lesson<U>{t1 - t2};
}

template<typename U>
Lesson<U> operator - (const Lesson<U>& t1, const Lesson<U>& t2)
{
    Lesson<U> res{t1.time - t2.time};
    size_t len1 = t1.names.size();
    for(size_t i = 0; i < len1; ++i)
        res.names.push_back(t1.names[i]);

    size_t len2 = t2.names.size();
    for(size_t i = 0; i < len2; ++i)
        res.names.push_back(t2.names[i]);
    return res;
}

template<typename U>
std::ostream& operator << (std::ostream &out, const Lesson<U>& t)
{
    out << "Time is " << t.time;
    out << "List of students:" << std::endl;
    size_t len = t.names.size();
    if(len == 0)
        out << "Empty" << std::endl;
    for(size_t i = 0; i < len; ++i)
        out << t.names[i] << std::endl;
    return out;
}
