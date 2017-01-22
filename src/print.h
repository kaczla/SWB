#ifndef PRINT_H
#define PRINT_H

#include <stdio.h>
#include <stdlib.h>
#include "const.h"

extern char* path;
extern unsigned short terminal_row;
extern unsigned short terminal_col;
extern char files_list[MAX_SIZE][MAX_LENGTH];
size_t files_list_size;

void print();

#endif
