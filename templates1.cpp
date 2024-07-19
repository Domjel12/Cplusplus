#include <iostream>

template <typename T, int prec = 1000> 
class Sqrt1{ 
public:
    T sqrt(T input){
        auto a = input;
        auto b = 1.;
        auto p = 1./prec;

        while (std::abs(a - b) > p){
            a = input / b;
            b = (a + b) /2.;
        }
        return a;
    }
};

int main(){
    float f = 10.;
    double d = 625;

    auto g = Sqrt();

    std::cin >> f;
    std::cout << "In f= " << f << " Wurzel= " << Sqrt.sqrt(f) << std::endl;

    return 0;
}