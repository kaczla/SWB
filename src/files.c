#include "files.h"

size_t count_files(char* path)
{
  size_t counter = 0;
  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      ++counter;
    }
    closedir(d);
  }
  return counter;
}

void get_files_list(char* path, size_t x, size_t y, char list[x][y])
{
  size_t counter = 0;
  DIR *d;
  struct dirent *dir;
  d = opendir(path);
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
      if (counter >= x)
      {
        break;
      }
      strcpy(list[counter], dir->d_name);
      ++counter;
    }
    closedir(d);
  }
}

void convert_path_to_realpath(char path[PATH_MAX])
{
  char resolved_path[PATH_MAX];
  realpath(path, resolved_path);
  strcpy(path, resolved_path);
}
