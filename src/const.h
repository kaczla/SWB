#ifndef CONST_H
#define CONST_H

#include <linux/limits.h>

#define MAX_LENGTH 255
#define MAX_SIZE 255

#ifdef SUPPORT_UNICODE
  #define BOX_DRAWINGS_HORIZONTAL "═"
  #define BOX_DRAWINGS_VERTICAL "║"
  #define BOX_DRAWINGS_DOWN_AND_RIGHT "╔"
  #define BOX_DRAWINGS_DOWN_AND_LEFT "╗"
  #define BOX_DRAWINGS_UP_AND_RIGHT "╚"
  #define BOX_DRAWINGS_UP_AND_LEFT "╝"
#else
  #define BOX_DRAWINGS_HORIZONTAL "─"
  #define BOX_DRAWINGS_VERTICAL "│"
  #define BOX_DRAWINGS_DOWN_AND_RIGHT "┌"
  #define BOX_DRAWINGS_DOWN_AND_LEFT "┐"
  #define BOX_DRAWINGS_UP_AND_RIGHT "└"
  #define BOX_DRAWINGS_UP_AND_LEFT "┘"
#endif

#define NEW_LINE "\n"
#define SPACE " "

#endif
