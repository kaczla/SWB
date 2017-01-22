#ifndef UPDATE_H
#define UPDATE_H

#include <stdio.h>
#include "const.h"
#include "const_key.h"
#include "command/command.h"
#include "terminal/terminal.h"
#include "sort_string_list.h"
#include "files.h"


char path[PATH_MAX];
unsigned short terminal_row;
unsigned short terminal_col;
char refresh;
char refresh_files;
char runned;
char files_list[MAX_SIZE][MAX_LENGTH];
size_t files_list_size;
struct termios term_attr;
struct termios term_attr_new;
int key;

void init(int argc, char **argv);

void clean();

void update();

void update_files_list();

#endif
