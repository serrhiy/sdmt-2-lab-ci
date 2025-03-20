#include "List.hpp"

template<typename T>
auto List<T>::length() const -> std::size_t {
  return size;
}
