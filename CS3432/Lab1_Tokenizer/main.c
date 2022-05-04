#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


int main()
{
  char input[] = "Hello,World,This,is,Jay,Park";
  char *pinput = input;
  char deli = ',';

  //char *x = word_start(pinput, deli);
  char *x;
  x = pinput;
  printf("The first letter is: %c\n", *x);

  //   x = end-word(pinput, deli);
  x = &(pinput[27]);
  printf("The delimeter is: %c\n", *x);

  printf("Prgram finished");
  return 0;
}
