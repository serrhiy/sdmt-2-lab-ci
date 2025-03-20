#include "List.hpp"
#include <cassert>
#include <iostream>

auto main(const int argc, const char* argv[]) -> int {
  auto list = List<int>();
  list.append(1);
  list.insert(0, 0);
  list.insert(2, 1);
  list.insert(-1, 0);
  assert(list.get(0) == -1);
  assert(list.get(1) == 0);
  assert(list.get(2) == 2);
  assert(list.get(3) == 1);
  return 0;
}
