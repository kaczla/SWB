#include "sort_string_list.h"

int compare(const void * a, const void * b)
{
  const char *pa = (const char*)a;
  const char *pb = (const char*)b;
  return strcmp(pa, pb);
}

void sort_list(size_t x, size_t y, char list[x][y])
{
  qsort(list, x, y, compare);
}
