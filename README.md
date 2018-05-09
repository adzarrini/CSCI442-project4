# Project 4

A simulation of a trival OS memory manager.

Name: Allee Zarrini

flag_parser: Implements the flag options for inputs. Flags including verbose, strategy, and max frames with help.

frame: Representation for frame of memory

page_table: Has a page table for a single process. In here we distinguish between our two strategies by choosing either getting the oldest page, or the least recently used page.

page: Represents a single page of a process

process: A simplified process used for memory simulation. 

physical_address: Representation for address that directly corresponds to a spot in physical memory.

virtual_address: virtual address includes page of process and offset into that page. Representatino with size constraints of bits and offset bits

simulation: memory simulation class. Based on the processes and their address with their values. 

main: Initializes simulation and runs the simulation.

All folders above contain a .h that includes variables and methods that describe their features with a .cpp that defines these methods that are used. They also contail a file that tests the proper functionality of these methods.

Number of Hours: 15 hrs

Belady's anomaly: Beladys' anomaly is the phenomeon which states that increasing page frames result in an increase in page faults. This is mainly occurs in FIFO. In LRU however, as the page frames increase, page faults decrease. 

Wikepdia and Stack Overflow used to answer the above question.
Created inputs/sim_3 for Belady's anomaly. 


Help from other classmates was essential in finishing this project. Main collaborator: Tylear Quast. Assistance from other students in alamode as well. 

# Graded 
 * final deliverable score: 180/180
 * total score: 200/200 

