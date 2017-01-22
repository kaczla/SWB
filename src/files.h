#ifndef FILES_H
#define FILES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

size_t count_files(char* path);

void get_files_list(char* path, size_t x, size_t y, char list[x][y]);

void convert_path_to_realpath(char path[PATH_MAX]);

#endif
