#include <iostream>
#include <stdio.h>
#include <iomanip>

template<typename T, int N = 100000000>
T SquareRoot(T t)
{
    auto a = t;
    auto b = 1.;
    auto p = 1./N; //precision

    while(std::abs(a-b) > 0.0001){
        a = t / b;
        b = (a+b)/2.;
    }
    return a;
}

int main() //Test Treiber
{
    auto f = 0.0;
    auto d = 0.0L; //L = long

    std::cout << "Bitte Zahl eingeben:" << std::endl;
    std::cin >> f;

    std::cout << "Wurzel von " << d << " = " << std::setprecision(10) << SquareRoot(d)<< std::endl;


    // printf("%.8d \n",SquareRoot(f));

    return 0;
}