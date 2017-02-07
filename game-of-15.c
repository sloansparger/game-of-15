#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[0])
{
  int size;

  if (argc < 2) {
    printf("Please provide a single number value.\n");
  } else if (argc > 2) {
    printf("Please provide only a single number.\n");
  } else {
    size = atoi(argv[1]);

    if (size < 3 || size > 8) {
      printf("Please provide a value between 3 and 8\n");
    } else {
      printf("Woooohooo, you inputed: %2d\n", size);
    }
  }
}
