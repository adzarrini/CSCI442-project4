/**
 * This file contains the definition of the Simulation class.
 *
 * You're free to modify this class however you see fit. Add new methods to help
 * keep your code modular.
 */

#pragma once
#include "process/process.h"
#include "virtual_address/virtual_address.h"
#include "physical_address/physical_address.h"
#include "flag_parser/flag_parser.h"
#include "page_table/page_table.h"
#include "frame/frame.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cassert>
#include <map>
#include <deque>

/**
 * Class responsible for running the memory simulation.
 */
class Simulation {
// PUBLIC CONSTANTS
public:

  /**
   * The maximum number of frames in the simulated system (512).
   */
  static const size_t NUM_FRAMES = 1 << 9;

  /*
   * Flags associated to the file. This is for the input file as well.
   */
  FlagOptions flags;
  
  // PUBLIC API METHODS
public:

  /**
   * Runs the simulation.
   */
  void run();

// PRIVATE METHODS
private:

  /**
   * Performs a memory access for the given virtual address, translating it to
   * a physical address and loading the page into memory if needed. Returns the
   * byte at the given address.
   */
  char perform_memory_access(const VirtualAddress& address);

  /**
   * Handles a page fault, attempting to load the given page for the given
   * process into memory.
   */
  void handle_page_fault(Process* process, size_t page);

// INSTANCE VARIABLES
private:
  
  std::map<int, Process*> processes;

  size_t free_frames = NUM_FRAMES;

  size_t page_faults = 0;

  size_t memory_accesses = 0;

};
