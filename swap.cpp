#include <iostream>

void swap(int& i, int& j){
    int h;

    h = j;
    i = j;
    j = h;
}

int main(){
    int a = -3;
    int b = 42;

    std::cout << "Input: " << a << " , " << b << std::endl;

    swap(a,b);

    std::cout << "Output: " << a << " , " << b << std::endl;

    return 0;
}