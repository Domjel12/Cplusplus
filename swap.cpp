#include <iostream>

void swap(int& i, int& j){
    int h;

    h = i;
    i = j;
    j = h;
}

void swap(float& i, float& j){
    float h;

    h = i;
    i = j;
    j = h;
}


int main(){
    int a = -3;
    int b = 42;
    float x = 1.3;
    float y = -3.4;

    std::cout << "Input: " << a << " , " << b << std::endl;

    swap(a,b);

    std::cout << "Output: " << a << " , " << b << std::endl;

    std::cout << "Input: " << x << " , " << y << std::endl;

    swap(x,y);

    std::cout << "Output: " << x << " , " << y << std::endl;

    return 0;
}