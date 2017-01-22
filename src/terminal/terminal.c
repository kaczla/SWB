#include "terminal.h"

struct winsize get_terminal_size()
{
  struct winsize terminal;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &terminal);
  return terminal;
}

struct termios get_terminal_attributes()
{
  struct termios term_attr;
  tcgetattr(fileno(stdin), &term_attr);
  return term_attr;
}

void set_terminal_attributes(struct termios term_attr)
{
  tcsetattr(fileno(stdin), TCSANOW, &term_attr);
}

int get_char()
{
  return fgetc(stdin);
}
