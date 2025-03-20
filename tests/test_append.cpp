#include "List.hpp"
#include <cassert>

auto main(const int argc, const char* argv[]) -> int {
  auto list = List<char>();
  assert("Empty list should has 0 length" && list.length() == 0);
  auto length = 0;
  for (auto symbol = 'a'; symbol != 'z' + 1; symbol++) {
    list.append(symbol);
    assert(list.get(length) == symbol);
    assert(list.length() == ++length);
  }
  return 0;
}
