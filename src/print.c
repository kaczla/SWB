#include "print.h"

#include <sys/ioctl.h>
#include <unistd.h>

static void print_top();

static void print_bottom();

void print()
{
  size_t i, j, k;
  if (terminal_row > 3)
  {
    print_top();
    //files
    for (i = 0; i < terminal_row - 3; ++i)
    {
      if (i < files_list_size)
      {
        if (terminal_col <= 1)
        {
          printf(BOX_DRAWINGS_VERTICAL);
          printf(NEW_LINE);
        }
        else
        {
          printf(BOX_DRAWINGS_VERTICAL);
          for (j = 0; j < terminal_col - 2; ++j)
          {
            if (files_list[i][j] == '\0')
            {
              for (k = 0; k < terminal_col - 2 - j; ++k)
              {
                printf(SPACE);
              }
              break;
            }
            else
            {
              printf("%c", files_list[i][j]);
            }

          }
          printf(BOX_DRAWINGS_VERTICAL);
          printf(NEW_LINE);
        }
      }
      else
      {
        if (terminal_col <= 1)
        {
          printf(BOX_DRAWINGS_VERTICAL);
          printf(NEW_LINE);
        }
        else
        {
          printf(BOX_DRAWINGS_VERTICAL);
          for (j = 0; j < terminal_col - 2; ++j)
          {
            printf(SPACE);
          }
          printf(BOX_DRAWINGS_VERTICAL);
          printf(NEW_LINE);
        }
      }
    }
    print_bottom();
  }
  else
  {
    print_top();
    print_bottom();
  }
}

static inline void print_top()
{
  size_t j;
  //top border
  if (terminal_col <= 1)
  {
    printf(BOX_DRAWINGS_DOWN_AND_RIGHT);
    printf(NEW_LINE);
  }
  else
  {
    printf(BOX_DRAWINGS_DOWN_AND_RIGHT);
    for (j = 0; j < terminal_col - 2; ++j)
    {
      printf(BOX_DRAWINGS_HORIZONTAL);
    }
    printf(BOX_DRAWINGS_DOWN_AND_LEFT);
    printf(NEW_LINE);
  }
}

static inline void print_bottom()
{
  size_t j;
  //bottom border
  if (terminal_col <= 1)
  {
    printf(BOX_DRAWINGS_UP_AND_RIGHT);
    printf(NEW_LINE);
  }
  else
  {
    printf(BOX_DRAWINGS_UP_AND_RIGHT);
    for (j = 0; j < terminal_col - 2; ++j)
    {
      printf(BOX_DRAWINGS_HORIZONTAL);
    }
    printf(BOX_DRAWINGS_UP_AND_LEFT);
    printf(NEW_LINE);
  }
}
