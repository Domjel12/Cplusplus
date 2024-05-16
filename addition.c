#include <stdio.h>

int main()
{
  float x = 3.14;
  float y = 0.0000001;
  float z = 0.0000002;
  float res1, res2, res3, res4;

  res1  = x + y;
  res1 += z; 
  res2  = z + x;
  res2 += y;

  res3 = x + y;
  res4 = x + z;

  printf("res1 = %.10f - res2 = %.10f \n",res1,res2);
  printf("res3 = %.10f - res4 = %.10f \n",res3,res4);

}
