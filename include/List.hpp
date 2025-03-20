#pragma once

#include <cstddef>

template <typename T>
class List {
  struct Node {
    Node* previous;
    Node* next;
    T value;
  };

  std::size_t size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;
public:
  List() = default;
  List(const List<T>& list) = delete;
  List(const List<T>&& list) noexcept;
  auto operator=(const List<T>& list) -> List<T>& = delete;
  auto operator=(List<T>&& list) noexcept -> List<T>&;

  [[nodiscard]] auto length() const -> std::size_t { return size; }

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
