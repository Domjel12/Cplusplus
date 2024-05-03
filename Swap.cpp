include <iostream>


void Swap(int& i, int& j, bool doit)
{
  int h = i;
  
  if (doit) {
    i = j;
    j = h;
  }
}

int main()
{
  int a = 3;
  int b = 42;

  bool maches = (a > 0 && > 0 ? true : false;

  std::cout << "a = " << a << " ," << " b = " << b << std::endl;

  Swap (a,b,maches);

  std::cout << "Ergebnis a = " << a << " ," << " b = " << b << std::endl;

  return 0;
}
