/**
 * This file contains implementations for the methods defined in the Simulation
 * class.
 *
 * You'll probably spend a lot of your time here.
 */

#include "simulation/simulation.h"
#include <limits>

using namespace std;


void Simulation::run() {
  // TODO: implement me
	string fileName = flags.filename;
	ifstream in(fileName);
	if(!in) exit(EXIT_FAILURE);

	size_t numProcess;
	in >> numProcess;
	int proc;
	string fName;
	for(size_t i = 0; i < numProcess; i++) {
		in >> proc >> fName;
		ifstream pin(fName);
		if(!pin) exit(EXIT_FAILURE);
		Process *process = Process::read_from_input(pin);
		pin.close();
		processes[proc] = process;

		// cout << "PID: " << proc
		// 		 << "\tBytes size: " << process->size()
		// 		 << endl;
	}

	cout << endl;
	
	string address;
	while(!in.eof()) {
		in >> proc >> address;
		VirtualAddress virtual_address = VirtualAddress::from_string(proc, address);
		if(flags.verbose) cout << virtual_address << endl;
		perform_memory_access(virtual_address);
	}

	in.close();

	cout << endl << "DONE!" << endl << endl;

	for(map<int,Process*>::iterator it = processes.begin(); it != processes.end(); ++it){
		cout << "Process " << it->first << ":\t"
		<< "ACCESSES: " << it->second->memory_accesses
		<< "\tFAULTS: " << it->second->page_faults
		<< "\tFAULT RATE: " << setprecision(2) << fixed << it->second->get_fault_percent()
		<< "\tRSS: " << it->second->get_rss() << endl;
	}
	cout << endl;
	cout << "Total memory accesses:\t" << memory_accesses << endl;
	cout << "Total page faults:\t" << page_faults << endl;
	cout << "Total frames remaining:\t" << free_frames << endl;
	
	cout << endl;
}


char Simulation::perform_memory_access(const VirtualAddress& address) {
  // TODO: implement me
  Process* process = processes[address.process_id];
  process->memory_accesses++;
  size_t page = address.page;
  memory_accesses++;
  process->page_table.rows[page].last_accessed_at = 
		process->memory_accesses;
	if(!processes[address.process_id]->page_table.rows[address.page].present) {
		if(flags.verbose) cout << "\t-> PAGE FAULT" << endl;
		handle_page_fault(process, page);
	}
	else {
		if(flags.verbose) cout << "\t-> IN MEMORY" << endl;
	}
	
	size_t frame = process->page_table.rows[page].frame;
	PhysicalAddress physical_address(frame, address.offset);
	if(flags.verbose) {
		cout << "\tphysical address " << physical_address << endl;
		cout << "\tRSS: " << process->get_rss() << endl;
		cout << endl;
	}
  return 0;
}


void Simulation::handle_page_fault(Process* process, size_t page) {
  // TODO: implement me
  size_t frame = 0;
  if(process->get_rss() >= size_t(flags.max_frames) || free_frames <= 0) {
  	size_t pageReplace = (flags.strategy == ReplacementStrategy::FIFO)
  	? process->page_table.get_oldest_page()
  	: process->page_table.get_least_recently_used_page();

  	frame = process->page_table.rows[pageReplace].frame;
  	process->page_table.rows[pageReplace].loaded_at = -1;
  	process->page_table.rows[pageReplace].present = false;
  }
  else {
  	free_frames--;
  }
  process->page_table.rows[page].present = true;
  process->page_table.rows[page].frame = frame;
  process->page_table.rows[page].loaded_at = process->memory_accesses;
  

  //cout << frame <<endl;

  process->page_faults++;
  page_faults++;

}
