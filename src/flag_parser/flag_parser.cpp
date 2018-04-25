/**
 * This file contains implementations for methods in the flag_parser.h file.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "flag_parser/flag_parser.h"
#include <iostream>
#include <cstdlib>
#include <getopt.h>
#include <fstream>
#include <string.h>

using namespace std;


void print_usage() {
  cout <<
      "Usage: mem-sim [options] filename\n"
      "\n"
      "Options:\n"
      "  -v, --verbose\n"
      "      Output information about every memory access.\n"
      "\n"
      "  -s, --strategy (FIFO | LRU)\n"
      "      The replacement strategy to use. One of FIFO or LRU.\n"
      "\n"
      "  -f, --max-frames <positive integer>\n"
      "      The maximum number of frames a process may be allocated.\n"
      "\n"
      "  -h --help\n"
      "      Display a help message about these flags and exit\n"
      "\n";
}


bool parse_flags(int argc, char** argv, FlagOptions& flags) {
  // TODO: implement me

  // Command-line flags accepted by this program.
  static struct option flag_options[] = {
    {"verbose", no_argument,       0, 'v'},
    {"strategy",    required_argument,       0, 's'},
    {"max-frames",  required_argument, 0, 'f'},
    {"help",       no_argument,       0, 'h'},
    {0, 0, 0, 0}
  };

  int option_index;
  char flag_char;

  // Parse flags entered by the user.
  while (true) {
    flag_char = getopt_long(argc, argv, "-vs:f:h", flag_options, &option_index);

    // Detect the end of the options.
    if (flag_char == -1) {
      break;
    }

    switch (flag_char) {
      case 'v':
        flags.verbose = true;
        break;

      case 's':
        if (strcmp(optarg, "FIFO") == 0) {
          flags.strategy = ReplacementStrategy::FIFO;
        } else if (strcmp(optarg, "LRU") == 0) {
          flags.strategy = ReplacementStrategy::LRU;
        } else {
          return false;
        }
        break;

      case 'f':
        if(atoi(optarg) < 1) return false;
        flags.max_frames = atoi(optarg);
        break;

      case 'h':
        //print_usage();
        //exit(EXIT_SUCCESS);
        return false;
        break;

      case 1:
        flags.filename = optarg;
        break;

      default:
        //print_usage();
        // exit(EXIT_FAILURE);
        return false;
    }
  }

  if (flags.filename == "") {
    //print_usage();
    //exit(EXIT_FAILURE);
    return false;
  }

  return true;
}
