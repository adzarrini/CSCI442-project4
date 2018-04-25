/**
 * This file contains implementations for the methods defined in the Simulation
 * class.
 *
 * You'll probably spend a lot of your time here.
 */

#include "simulation/simulation.h"

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

		cout << "PID: " << proc
				 << "\tBytes size: " << process->size()
				 << endl;
	}

	cout << endl;

	string address;
	while(in) {
		in >> proc >> address;
		VirtualAddress virtual_address = VirtualAddress::from_string(proc, address);
		cout << virtual_address << endl;
	}

	in.close();
}


char Simulation::perform_memory_access(const VirtualAddress& address) {
  // TODO: implement me
  return 0;
}


void Simulation::handle_page_fault(Process* process, size_t page) {
  // TODO: implement me
}
