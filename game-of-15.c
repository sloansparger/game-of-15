#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curses.h>

#define UP    1
#define RIGHT 3
#define DOWN  2
#define LEFT  4

void init(int size, int board[][size]);
void draw(int size, int board[][size]);
void move_piece(int size, int board[][size], int direction);
bool win(int size, int board[][size]);
void swap(int *a, int *b);
void clear_screen();

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
      clear_screen();
      draw(size, board);

      do {
        if (getchar() == '\033')
        {
          getchar();
          switch(getchar())
          {
            case 'A':
              move_piece(size, board, UP);
              break;
            case 'B':
              move_piece(size, board, DOWN);
              break;
            case 'C':
              move_piece(size, board, RIGHT);
              break;
            case 'D':
              move_piece(size, board, LEFT);
              break;
            default:
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

void move_piece(int size, int board[][size], int direction)
{
  bool stop = false;
  int x, y;

  clear_screen();
  for (int i = 0; i < size && !stop; i++)
  {
    for (int j = 0; j < size && !stop; j++)
    {
      if (board[i][j] == 0)
      {
        y = i;
        x = j;
        stop = true;
      }
    }
  }

  if (direction == DOWN) {
    if (y == 0) {
      // invalid move
    } else {
      swap(&board[y][x], &board[y - 1][x]);
    }
  } else if (direction == UP) {
    if (y + 1 == size) {
      // invalid move
    } else {
      swap(&board[y][x], &board[y + 1][x]);
    }
  } else if (direction == LEFT) {
    if (x + 1 == size) {
      // invalid move
    } else {
      swap(&board[y][x], &board[y][x + 1]);
    }
  } else {
    if (x == 0) {
      // invalid move
    } else {
      swap(&board[y][x], &board[y][x - 1]);
    }
  }   

  draw(size, board);
}

bool win(int size, int board[][size])
{
  // TODO: all that is needed to complete the game it to make sure that the user has one. if they have won,
  // clear the board and show message that they have won.

  bool winning = true;

  for (int i = 0; i < size && winning; i++)
  {
    for (int j = 0; j < size && winning; j++)
    {
      if (board[i][j] != (j + 1) + (i * size))
      {
        printf("board[%d][%d] = %d. Should be: %d.\n", i, j, board[i][j], (j + 1) + (i * size));
        winning = false;
      }

      printf("i = %d, size = %d, j = %d, board[size - 1][size - 1] = %d\n", i, size, j, board[size - 1][size - 1]);
      if (i == size - 1 && j == size - 1 && board[i][j] == 0)
      {
        clear_screen();
        printf("YOU WON!!!!.\n");
        winning = true;
      }

    }
  }

  return winning;
}

void clear_screen()
{
  printf("\e[1;1H\e[2J");
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}
