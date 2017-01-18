#include "command.h"

char* command(int argc, char **argv)
{

  while ((c = getopt (argc, argv, "p:")) != -1) {
    switch (c) {
      case 'p':
        return optarg;
        break;
      case '?':
        if (optopt == 'p' )
          fprintf (stderr, "Option -%c requires an argument.\n", optopt);
        else if (isprint (optopt))
          fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        else
          fprintf (stderr,
                   "Unknown option character `\\x%x'.\n",
                   optopt);
        return 1;
      default:
       return "";
      }
  }


 }
