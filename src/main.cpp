/**
 * This file contains the main() function that drives the simulation. You'll
 * need to add logic to this file to create a Simulation instance and invoke its
 * run() method.
 */

#include <cstdlib>
#include "flag_parser/flag_parser.h"
#include "simulation/simulation.h"

using namespace std;


/**
 * The main entry point to the simulation.
 */
int main(int argc, char** argv) {
  // TODO: implement me
	Simulation sim;
	FlagOptions flags;

	if(parse_flags(argc, argv, flags)) sim.flags = flags;
	sim.run();

  return EXIT_SUCCESS;
}
