#include"time.h"

Time::Time()
{
    hour = minute = 0;
}

Time::Time(int h, int m)
{
    hour = h;
    minute = m;
    Cut();
}

void Time::Cut()
{
    if(minute < 0)
    {
        int counter = 0;
        while(minute < 0)
        {
            minute += 60;
            ++counter;
        }
        hour -= counter;
    }
    else
    {
        // this code does nothing if data is correct
        hour += (minute / 60);
        minute %= 60;
    }
}

int Time::Get_hour() const
{
    return hour;
}

int Time::Get_min() const
{
    return minute;
}

void Time::Set(int h, int m)
{
    hour = h;
    minute = m;
    Cut();
}

Time operator + (const Time& t1, const Time& t2)
{
    Time res{t1.hour + t2.hour, t1.minute + t2.minute};
    res.Cut();
    return res;
}

Time operator - (const Time& t1, const Time& t2)
{
    Time res{t1.hour - t2.hour, t1.minute - t2.minute};
    res.Cut();
    return res;
}

std::ostream& operator << (std::ostream &out, const Time &t)
{
    if(t.minute < 10 || t.hour < 10)
    {
        if(t.hour < 0)
            out << "-0" << -t.hour;
        else if(t.hour < 10)
            out << "0" << t.hour;
        else
            out << t.hour;

        if(t.minute < 10)
            out << ":0" << t.minute << std::endl;
        else
            out << ":" << t.minute << std::endl;
    }
    else
        out << t.hour << ":" << t.minute << std::endl;
    return out;
}

//////////////////BigTime//////////////////
void BigTime::Cut()
{
    if(second < 0)
    {
        int counter = 0;
        while(second < 0)
        {
            second += 60;
            ++counter;
        }
        second -= counter;
    }
    if(minute < 0)
    {
        int counter = 0;
        while(minute < 0)
        {
            minute += 60;
            ++counter;
        }
        hour -= counter;
    }
    else
    {
        // this code does nothing if data is correct
        minute += second / 60;
        second %= 60;
        hour += minute / 60;
        minute %= 60;
    }

}

int BigTime::Get_sec()
{
    return second;
}

void BigTime::Set(int h, int m, int s)
{
    hour = h;
    minute = m;
    second = s;
    Cut();
}

BigTime operator + (const BigTime& t1, const BigTime& t2)
{
    BigTime res{t1.hour + t2.hour, t1.minute + t2.minute, t1.second + t2.second};
    res.Cut();
    return res;
}

BigTime operator - (const BigTime& t1, const BigTime& t2)
{
    BigTime res{t1.hour - t2.hour, t1.minute - t2.minute, t1.second - t2.second};
    res.Cut();
    return res;
}

std::ostream& operator << (std::ostream &out, const BigTime& t)
{
    if(t.minute < 10 || t.hour < 10 || t.second < 10)
    {
        if(t.hour < 0)
            out << "-0" << -t.hour;
        else if(t.hour < 10)
            out << "0" << t.hour;
        else
            out << t.hour;

        if(t.minute < 10)
            out << ":0" << t.minute;
        else
            out << ":" << t.minute;

        if(t.second < 10)
            out << ":0" << t.second << std::endl;
        else
            out << ":" << t.second << std::endl;
    }
    else
        out << t.hour << ":" << t.minute << ":" << t.second << std::endl;
    return out;
}
