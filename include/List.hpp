#pragma once

#include <cstddef>
#include <stdexcept>

#include <iostream>

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

  auto append(const T& value) -> void {
    auto* node = new Node(tail, nullptr, value);
    if (head == nullptr) head = node;
    else tail->next = node;
    tail = node;
    size++;
  }

  auto insert(const T& value, int index) noexcept -> void;
  auto remove(int index) noexcept -> T;
  auto removeAll(const T& value) noexcept -> void;

  auto get(const int index) const -> T {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Invalid index: " + std::to_string(index));
    }
    auto node = head;
    for (auto counter = 0; counter < index; counter++) node = node->next;
    return node->value;
  }

  auto clone() const noexcept -> List<T>;
  auto reverse() -> void;
  auto findFirst(const T& value) -> int;
  auto findLast(const T& value) -> int;
  auto clear() noexcept -> void;
  auto extend(const List<T>& list) -> void;

  ~List() {
    auto first = head;
    while (first != nullptr) {
      const auto temp = first->next;
      delete first;
      first = temp;
    }
  }
};
