#pragma once

#include <cstddef>
#include <stdexcept>

template <typename T>
class List {
  struct Node {
    Node* previous;
    Node* next;
    T value;

    template<typename U>
    Node(Node* previous, Node* next, U&& value)
      : previous{ previous },
        next{ next },
        value{ std::forward<U>(value) } { }
  };

  std::size_t size = 0;
  Node* head = nullptr;
  Node* tail = nullptr;

  auto getNodeByIndex(const int index) const -> Node* {
    if (index < 0 || index >= size) {
      throw std::out_of_range("Invalid index: " + std::to_string(index));
    }
    auto node = head;
    for (auto counter = 0; counter < index; counter++) node = node->next;
    return node;
  }
public:
  List() = default;

  List(const List<T>& list) {
    for (auto node = list.head; node != nullptr; node = node->next) {
      this->append(node->value);
    }
  };

  List(List<T>&& list) noexcept
    : size{ list.size },
      head{ list.head },
      tail{ list.tail }
    {
      list.size = 0;
      list.head = nullptr;
      list.tail = nullptr;
    }

  auto operator=(const List<T>& list) -> List<T>& = delete;
  auto operator=(List<T>&& list) noexcept -> List<T>&;

  [[nodiscard]] auto length() const -> std::size_t { return size; }

  template<typename U>
  auto append(U&& value) -> void {
    auto* node = new Node(tail, nullptr, std::forward<U>(value));
    if (head == nullptr) head = node;
    else tail->next = node;
    tail = node;
    size++;
  }

  template<typename U>
  auto insert(U&& value, int index) -> void {
    auto node = getNodeByIndex(index);
    auto* newNode = new Node(node->previous, node, std::forward<U>(value));
    if (node == head) head = newNode;
    else node->previous->next = newNode;
    node->previous = newNode;
    size++;
  }

  auto remove(const int index) -> T {
    const auto node = getNodeByIndex(index);
    auto value = std::move(node->value);
    if (node == head) {
      if (head->next == nullptr) head = tail = nullptr;
      else {
        head = head->next;
        head->previous = nullptr;
      }
    } else if (node == tail) {
      tail = tail->previous;
      tail->next = nullptr;
    } else {
      auto next = node->next;
      auto previous = node->previous;
      previous->next = next;
      next->previous = previous;
    }
    delete node;
    size--;
    return value;
  }

  auto removeAll(const T& value) -> void {
    auto index = 0;
    for (auto node = head; node != nullptr; node = node->next, index++) {
      if (node->value == value) remove(index);
    }
  }

  auto get(const int index) const -> T { return getNodeByIndex(index)->value; }

  auto clone() const noexcept -> List<T> {
    return List{ *this };
  }

  auto reverse() -> void {
    for (auto node = head; node != nullptr; node = node->previous) {
      std::swap(node->next, node->previous);
    }
    std::swap(head, tail);
  }

  auto findFirst(const T& value) -> int {
    auto index = 0;
    for (auto node = head; node != nullptr; node = node->next, index++) {
      if (value == node->value) return index;
    }
    return -1;
  }

  auto findLast(const T& value) -> int {
    auto index = size - 1;
    for (auto node = tail; node != nullptr; node = node->previous, index--) {
      if (value == node->value) return index;
    }
    return -1;
  }

  auto clear() -> void {
    auto first = head;
    while (first != nullptr) {
      const auto temp = first->next;
      delete first;
      first = temp;
    }
    size = 0;
    head = tail = nullptr;
  }

  auto extend(const List<T>& list) -> void {
    for (auto node = list.head; node != nullptr; node = node->next) {
      append(node->value);
    }
  }

  ~List() {
    clear();
  }
};
