#include "List.hpp"
#include <cassert>
#include <iostream>

constexpr auto items = 10;

auto removeFromBegining() -> void {
  auto list = List<int>();
  for (auto index = 0; index < items; index++) list.append(index);
  for (auto index = 0; index < items; index++) {
    const auto value = list.remove(0);
    assert(list.length() == items - index - 1);
    assert(value == index);
  }
  assert(list.length() == 0);
}

auto removeFromEnding() -> void {
  auto list = List<int>();
  for (auto index = 0; index < items; index++) list.append(index);
  for (auto index = 0; index < items; index++) {
    const auto position = items - index - 1;
    const auto value = list.remove(position);
    assert(list.length() == position);
    assert(value == position);
  }
  assert(list.length() == 0);
}

auto removeFromMiddle() -> void {
  auto list = List<int>();
  for (auto index = 0; index < items; index++) list.append(index);
  assert(list.remove(5) == 5);
  assert(list.remove(5) == 6);
  assert(list.remove(4) == 4);
  assert(list.remove(0) == 0);
  assert(list.remove(5) == 9);
  assert(list.length() == 5);
}

auto main(const int argc, const char* argv[]) -> int {
  removeFromBegining();
  removeFromEnding();
  removeFromMiddle();
  return 0;
}
