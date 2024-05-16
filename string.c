#include <stdio.h>

int main()
{
  char s[] = "Hello World!";
  printf("%s \n",s);

  char *ptr_s;
  ptr_s = s;
  printf("%s \n",ptr_s);

  int n = 44;
  int* ptr_n = &n;
  printf("%i \n", *ptr_n);

  float* ptr_fn = &n;
  printf("%f \n",*ptr_fn);
}
