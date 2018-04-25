/**
 * This file contains implementations for methods in the PhysicalAddress class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "physical_address/physical_address.h"
#include <bitset>

using namespace std;


string PhysicalAddress::to_string() const {
  // TODO: implement me
	bitset<FRAME_BITS> frame_bits(frame);
	bitset<OFFSET_BITS> offset_bits(offset); 
  return frame_bits.to_string()+offset_bits.to_string();
}


ostream& operator <<(ostream& out, const PhysicalAddress& address) {
  // TODO: implement me'
  return out
      << address.to_string()
      << " [frame: " << address.frame
      << "; offset: " << address.offset
      << "]";;
}
