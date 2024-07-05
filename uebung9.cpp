#include <iostream>

class Test{
public:
    Test() {std::cout << "Erzeugt" << std::endl;}; //Konstruktor //Test() = default; geht auch
    ~Test() {std::cout << "Zerstört" << std::endl;}; //Destruktor
    Test(const Test& T) {}; //Copy Konstruktor
    Test(Test&& T) {}; // Move Konstruktor
private:
    int n;
    std::string s;
};

int main()
{
    Test T; //erzeuge objekt

    return 0;
}