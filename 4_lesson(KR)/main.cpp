#include<iostream>
#include"fraction.h"


int main()
{
    Fraction frac0;
    std::cin >> frac0;
    std::cout << "frac0 = " << frac0 << std::endl;

    Fraction frac1{1.5};
    std::cout << "frac1 = " << frac1;
    std::cout << "decimal frac1 = " << frac1.Decimal() << "\n" << std::endl;

    Fraction frac2{20, 120}; // = 1/6
    std::cout << "frac2 = " << frac2;
    std::cout << "(int)frac2 = " << frac2.Integer() << "\n" << std::endl;

    Fraction sum = frac1 + frac2;
    std::cout << "sum = " << sum << std::endl;

    Fraction diff = frac1 - frac2;
    std::cout << "difference = " << diff << std::endl;

    Fraction comp = frac1 * frac2;
    std::cout << "composition = " << comp << std::endl;

    Fraction quot = frac1 / frac2;
    std::cout << "quotient = " << quot << std::endl;

    Fraction pos = + frac1;
    std::cout << "frac1 = " << pos << std::endl;
    Fraction negate = - frac1;
    std::cout << "-frac1 = " << negate << std::endl;

    Fraction frac3 = {3, -6};
    std::cout << "frac3 = " << frac3;
    frac3 += frac1;
    std::cout << "frac3 + frac1 = " << frac3 << std::endl;

    Fraction frac4 = 5;
    std::cout << "frac4 = " << frac4 << std::endl;

    Fraction frac5 = -5;
    std::cout << "frac5 = " << frac5 << std::endl;

    frac5++;
    std::cout << "frac5 + 1 = " << frac5 << std::endl;

    frac4 = frac5++;
    std::cout << "frac4 = " << frac4 << std::endl;
    std::cout << "frac5 + 1 = " << frac5 << std::endl;

    frac5--;
    std::cout << "frac5 - 1 = " << frac5 << std::endl;

    frac4 = frac5--;
    std::cout << "frac4 = " << frac4 << std::endl;
    std::cout << "frac5 - 1 = " << frac5 << std::endl;



    std::cout << "frac1 == frac2 is " << (frac1 == frac2) << std::endl;
    std::cout << "frac1 != frac2 is " << (frac1 != frac2) << std::endl;
    std::cout << "frac1 > frac2 is " << (frac1 > frac2) << std::endl;
    std::cout << "frac1 >= frac2 is " << (frac1 >= frac2) << std::endl;
    std::cout << "frac1 < frac2 is " << (frac1 < frac2) << std::endl;
    std::cout << "frac1 <= frac2 is " << (frac1 <= frac2) << std::endl;
    
    return 0;
}
