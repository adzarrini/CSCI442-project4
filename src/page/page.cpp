/**
 * This file contains implementations for methods in the Page class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page/page.h"
#include <algorithm>

using namespace std;


// Ensure PAGE_SIZE is initialized.
const size_t Page::PAGE_SIZE;


Page* Page::read_from_input(std::istream& in) {
  // TODO: implement me
  if(in.peek()==-1) return nullptr;

  vector<char> bytes;
  size_t counter = 0;
	while(counter++ < Page::PAGE_SIZE && in.peek() != -1) {
		bytes.push_back(char(in.get()));
	}

  return new Page(bytes);
}


size_t Page::size() const {
  // TODO: implement me
  return (size_t) bytes.size();
}


bool Page::is_valid_offset(size_t offset) const {
  // TODO: implement me
  if(offset < size()) return true;
  return false;
}


char Page::get_byte_at_offset(size_t offset) {
  // TODO: implement me
  return bytes[offset];
}
