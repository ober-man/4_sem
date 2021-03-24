#pragma once
#include<iostream>

class Time // hh:mm
{
    protected:
        int hour; // non-limited
        int minute; // 1..60

    private:
        virtual void Cut();

    public:
        Time();
        Time(int h, int m);
        int Get_hour() const;
        int Get_min() const;
        void Set(int h, int m);
        friend Time operator + (const Time& t1, const Time& t2);
        friend Time operator - (const Time& t1, const Time& t2);
        friend std::ostream& operator << (std::ostream &out, const Time& t);
};

class BigTime final : public Time
{
    private:
        int second; // 1..60
        void Cut();

    public:
        BigTime() : Time(), second(0) {};
        BigTime(int h, int m, int s) : Time{h, m}, second(s) {};
        int Get_sec();
        void Set(int h, int m, int s);
        friend BigTime operator + (const BigTime& t1, const BigTime& t2);
        friend BigTime operator - (const BigTime& t1, const BigTime& t2);
        friend std::ostream& operator << (std::ostream &out, const BigTime& t);
};
