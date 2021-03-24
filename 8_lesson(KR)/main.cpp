#include"time.h"
#include"lesson.h"

#define EXCEPTION

using namespace std;

int main()
{
    Time t1;
    Time t2{-2, -20};
    std::cout << "t1 is empty " << t1;
    std::cout << "t2 is " << t2;
    t1.Set(4, 40);
    std::cout << "Now t1 is " << t1;
    Time t3 = t1 + t2;
    Time t4 = t1 - t2;
    std::cout << "Sum is " << t3;
    std::cout << "Difference is " << t4 << std::endl;

    BigTime T1;
    BigTime T2{3, 40, 23};
    std::cout << "T1 is " << T1;
    std::cout << "T2 is " << T2;
    T1.Set(-4, 40, 45);
    std::cout << "Now T1 is " << T1;
    BigTime T3 = T1 + T2;
    BigTime T4 = T1 - T2;
    std::cout << "Sum is " << T3;
    std::cout << "Difference is " << T4 << std::endl;

    try
    {
        Lesson<Time> l1{t1};
        Lesson<BigTime> l2{T1};
        std::cout << "Lesson1:\n" << l1;
        std::cout << "Lesson2:\n" << l2;
        l1.Add("Ivan");
        #ifndef EXCEPTION
        l1.Add("very-very-very-long-name");
        #endif
        std::cout << "Now lesson1:\n" << l1;
        Lesson<Time> l3 = t1 + t2;
        Lesson<Time> l4 = t1 - t2;
        Lesson<Time> l5 = l1 + l3;
        std::cout << "Lesson3:\n" << l3;
        std::cout << "Lesson4:\n" << l4;
        std::cout << "Lesson5:\n" << l5;
    }
    catch(Exception ex)
    {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}
