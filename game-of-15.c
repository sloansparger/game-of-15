#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void init(int size, int board[]);

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
      int board[size * size];

      for (int i = 0; i < (size * size); i++)
        board[i] = 0;

      init(size, board);
      
      for (int k = 0; k < (size * size); k++)
        printf("%d\n", board[k]);
    }
  }
}

void init (int size, int board[])
{
  // TODO: randomize numbers in the future.

  int max = (size * size) - 1;

  for (int i = max, j = 0; i > 2; i--, j++)
    board[j] = i;

  if (size % 2 == 0) {
    board[max - 2] = 1;
    board[max - 1] = 2;
  } else {
    board[max - 2] = 2;
    board[max - 1] = 1;
  }

  board[max] = 0;

  
}

