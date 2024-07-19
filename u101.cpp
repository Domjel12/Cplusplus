#include <iostream>

template<typename T>
T Square(T t) { return (t*t)}

int main()
{
    int i = 4;
    float f = 25.;
    double d = 11.;

    std::cout << Square(i) << std::endl;
    std::cout << Square(f) << std::endl;
    std::cout << Square(d) << std::endl;

    return 0;
}