#include <iostream>

struct Element {
  int value;
  Element* next;
  int min;
  Element(int value, Element* next, int min)
      : value(value), next(next), min(min) {}
  Element(int value) : value(value), next(nullptr), min(value) {}
};

class Stack {
  int size_;
  Element* head_;

 public:
  Stack() : size_(0), head_(nullptr) {}
  int Size() { return size_; }
  void Push(int value) {
    if (size_ != 0) {
      Element* element = new Element(value, head_, std::min(value, head_->min));
      head_ = element;
    } else {
      Element* element = new Element(value);
      head_ = element;
    }
    ++size_;
  }
  std::string Pop() {
    if (size_ == 0) {
      return "error";
    }
    int num = head_->value;
    Element* new_head = head_->next;
    delete head_;
    head_ = new_head;
    --size_;
    return std::to_string(num);
  }
  std::string Back() {
    if (size_ == 0) {
      return "error";
    }
    return std::to_string(head_->value);
  }
  std::string Min() {
    if (size_ == 0) {
      return "error";
    }
    return std::to_string(head_->min);
  }
  void Clear() {
    while (size_ != 0) {
      Pop();
    }
  }
  Element Get() { return *head_; }
  ~Stack() { Clear(); }
};

class Queue {
  Stack add_;
  Stack delete_;
  void SwapElements() {
    if (delete_.Size() != 0) {
      return;
    }
    while (add_.Size() != 0) {
      delete_.Push(std::stoi(add_.Pop()));
    }
  }

 public:
  Queue() {}
  void Enqueue(int value) { add_.Push(value); }
  std::string Dequeue() {
    SwapElements();
    return delete_.Pop();
  }
  std::string Front() {
    SwapElements();
    return delete_.Back();
  }
  int Size() { return add_.Size() + delete_.Size(); }
  std::string Min() {
    SwapElements();
    if (delete_.Size() != 0) {
      if (add_.Size() != 0) {
        return std::to_string(
            std::min(std::stoi(add_.Min()), std::stoi(delete_.Min())));
      }
      return delete_.Min();
    }
    if (add_.Size() != 0) {
      return add_.Min();
    }
    return "error";
  }
  void Clear() {
    add_.Clear();
    delete_.Clear();
  }
  ~Queue() { Clear(); }
};

int main() {
  Queue queue;
  int n;
  std::cin >> n;
  std::string command;
  for (int i = 0; i < n; ++i) {
    std::cin >> command;
    if (command == "enqueue") {
      int num;
      std::cin >> num;
      queue.Enqueue(num);
      std::cout << "ok\n";
    } else if (command == "dequeue") {
      std::cout << queue.Dequeue() << "\n";
    } else if (command == "front") {
      std::cout << queue.Front() << "\n";
    } else if (command == "size") {
      std::cout << queue.Size() << "\n";
    } else if (command == "clear") {
      queue.Clear();
      std::cout << "ok\n";
    } else if (command == "min") {
      std::cout << queue.Min() << "\n";
    }
  }
}
