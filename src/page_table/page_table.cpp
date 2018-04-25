/**
 * This file contains implementations for methods in the PageTable class.
 *
 * You'll need to add code here to make the corresponding tests pass.
 */

#include "page_table/page_table.h"
#include <limits>

using namespace std;


size_t PageTable::get_present_page_count() const {
  // TODO: implement me
  size_t page_count = 0;
  for(size_t i = 0; i < rows.size(); i++) {
  	if(rows[i].present) page_count++;
  }
  return page_count;
}


size_t PageTable::get_oldest_page() const {
  // TODO: implement me
  size_t temp = std::numeric_limits<std::size_t>::max();
  size_t oldest = -1;
  for(size_t i = 0; i < rows.size(); i++) {
    if(rows[i].present && rows[i].loaded_at < temp) {
      oldest = i;
      temp = rows[i].loaded_at;
    }
  }
  return oldest;
}


size_t PageTable::get_least_recently_used_page() const {
  // TODO: implement me
  size_t temp = std::numeric_limits<std::size_t>::max();
  size_t recent = -1;
  for(size_t i = 0; i < rows.size(); i++) {
    if(rows[i].present && rows[i].last_accessed_at < temp) {
      recent = i;
      temp = rows[i].last_accessed_at;
    }
  }
  return recent;
}
