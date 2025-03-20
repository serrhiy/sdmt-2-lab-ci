#pragma once

#include <cstddef>
#include <memory>

template <typename T>
class List {
  struct Node {
    std::unique_ptr<Node> previous;
    std::unique_ptr<Node> next;
    T value;
  };

  std::size_t size = 0;
  std::unique_ptr<Node> head = nullptr;
public:
  List() = default;
  List(const List<T>& list) = delete;
  List(const List<T>&& list) noexcept;
  auto operator=(const List<T>& list) -> List<T>& = delete;
  auto operator=(List<T>&& list) noexcept -> List<T>&;

  [[nodiscard]] auto length() const -> std::size_t;
  auto append(const T& value) noexcept -> void;
  auto insert(const T& value, int index) noexcept -> void;
  auto remove(int index) noexcept -> T;
  auto removeAll(const T& value) noexcept -> void;
  auto get(int index) const -> T;
  auto clone() const noexcept -> List<T>;
  auto reverse() -> void;
  auto findFirst(const T& value) -> int;
  auto findLast(const T& value) -> int;
  auto clear() noexcept -> void;
  auto extend(const List<T>& list) -> void;
  ~List() = default;
};
