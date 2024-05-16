#include <iostream>
#include <stdio.h>


namespace abc {
  int puts(const char* in)
  {
    int n = 0;
    
    return n;
   }
};

int main()
{
  const char* text = "nothing at all";
  
  std::cout << *text << std::endl;
  
  printf("Out: %p \n",text);
  
  abc::puts(text);
  
  return 0;
}

