#include "List.hpp"
#include <cassert>

auto main(const int argc, const char* argv[]) -> int {
  auto list = List<char>();
  auto length = 0;
  assert("Empty list should has 0 length" && list.length() == length++);
  list.append('a');
  assert("List with 1 item should has length 1" && list.length() == length++);
  for (auto symbol = 'b'; symbol != 'z' + 1; symbol++) {
    list.append(symbol);
    assert(list.length() == length++);
  }
  return 0;
}
