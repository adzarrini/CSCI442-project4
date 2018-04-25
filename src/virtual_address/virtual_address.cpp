/**
 * This file contains implementations for methods in the VirtualAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "virtual_address/virtual_address.h"
#include <bitset>

using namespace std;


VirtualAddress VirtualAddress::from_string(int process_id, string address) {
  // TODO: implement me
	bitset<PAGE_BITS> page_bits(address.substr(0, PAGE_BITS));
	bitset<OFFSET_BITS> offset_bits(address.substr(PAGE_BITS));

  return VirtualAddress(process_id, page_bits.to_ulong(), offset_bits.to_ulong());
}


string VirtualAddress::to_string() const {
  // TODO: implement me
  bitset<PAGE_BITS> page_bits(page);
	bitset<OFFSET_BITS> offset_bits(offset); 
  return page_bits.to_string()+offset_bits.to_string();
}


ostream& operator <<(ostream& out, const VirtualAddress& address) {
  // TODO: implement me
  return out
      << "PID " << address.process_id
      << " @ " << address.to_string()
      << " [page: " << address.page
      << "; offset: " << address.offset
      << "]";
}
