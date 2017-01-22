#ifndef TERMINAL_H
#define TERMINAL_H

#include <sys/ioctl.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

struct winsize get_terminal_size();

struct termios get_terminal_attributes();

void set_terminal_attributes(struct termios term_attr);

int get_char();

#endif
