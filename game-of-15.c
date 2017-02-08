#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

void init(int size, int board[][size]);
void draw(int size, int board[][size]);
int win(int size, int board[][size]);

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
      int board[size][size];

      for (int i = 0; i < size; i++)
      {
        for (int j = 0; j < size; j++)
        {
          board[i][j] = 0;
        }
      }

      init(size, board);
      draw(size, board);

      do {
        if (getchar() == '\033')
        {
          getchar();
          switch(getchar())
          {
            case 'A':
              printf("UP\n");
              break;
            case 'B':
              printf("DOWN\n");
              break;
            case 'C':
              printf("RIGHT\n");
              break;
            case 'D':
              printf("LEFT\n");
              break;
          }
        }
      } while (!win(size, board));
    }
  }
}

void init (int size, int board[][size])
{
  // TODO: randomize numbers in the future.

  int max = (size * size) - 1;

  // for (int i = max, j = 0; i > 2; i--, j++)
  //   board[j] = i;

  for (int i = 0; i < size; i++)
  {
    for (int k = 0; k < size; k++)
    {
      board[i][k] = max - ((i * size) + k);
    }
  }

  if (size % 2 == 0)
  {
    board[size - 1][size - 3] = 1;
    board[size - 1][size - 2] = 2;
  } else {
    board[size - 1][size - 3] = 2;
    board[size - 1][size - 2] = 1;
  }

  board[size - 1][size - 1] = 0;
}

void draw(int size, int board[][size])
{
  for (int i = 0; i < size; i++)
  {
    printf("  ");
    for (int j = 0; j < size; j++)
    {
      if (board[i][j] != 0)
      {
        printf("%2d", board[i][j]);
      } else {
        if (size == 3) {
          printf(" _");
        } else {
          printf("__");
        }
      }
      printf("  ");
    }
    printf("\n");
  }
}

int win(int size, int board[][size])
{
  return false;
}


