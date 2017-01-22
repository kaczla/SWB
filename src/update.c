#include "update.h"

void init(int argc, char **argv)
{
  strcpy(path, command(argc, argv));
  if( path[0] == '\0' )
  {
  	strcpy(path, ".");
  }
  convert_path_to_realpath(path);
  struct winsize terminal;
  terminal = get_terminal_size();
  terminal_row = terminal.ws_row;
  terminal_col = terminal.ws_col;
  term_attr = get_terminal_attributes();
  memcpy(&term_attr_new, &term_attr, sizeof(struct termios));
  term_attr_new.c_lflag &= ~(ECHO|ICANON);
  term_attr_new.c_cc[VTIME] = 0;
  term_attr_new.c_cc[VMIN] = 0;
  set_terminal_attributes(term_attr_new);
  runned = 1;
  refresh_files = 1;
  refresh = 1;
  update_files_list();
}

void clean()
{
  set_terminal_attributes(term_attr);
}

void get_key()
{
  // key
  key = get_char();
  switch (key) {
    case EOT:
    case ESC:
      key = get_char();
      switch (key) {
        case CSI:
          key = get_char();
          switch (key) {
            case KEY_UP:
              break;
            case KEY_DOWN:
              break;
            case KEY_LEFT:
              break;
            case KEY_RIGHT:
              break;
            default:
              break;
          }
          break;
        case EOF:
          runned = 0;
          break;
        default:
          break;
      }
      break;
    default:
      break;
  }
}

void update()
{
	struct winsize terminal;
	terminal = get_terminal_size();
  if (terminal_row != terminal.ws_row || terminal_col != terminal.ws_col)
  {
    terminal_row = terminal.ws_row;
    terminal_col = terminal.ws_col;
    refresh = 1;
  }
  else
  {
    refresh = 0;
  }
  get_key();
  if (refresh_files)
  {
    update_files_list();
  }
}

void clear_files_list()
{
  size_t i;
  for(i = 0; i < MAX_SIZE; ++i)
  {
    if (files_list[0][0] == '\0')
    {
      break;
    }
    else
    {
      files_list[0][0] = '\0';
    }
  }
}

void update_files_list()
{
  clear_files_list();
  files_list_size = count_files(path);
  get_files_list(path, MAX_SIZE, MAX_LENGTH, files_list);
  sort_list(files_list_size, MAX_LENGTH, files_list);
  refresh_files = 0;
}
