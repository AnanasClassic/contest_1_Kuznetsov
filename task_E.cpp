#include <deque>
#include <iostream>

class GoblinQueue {
  std::deque<int> left_;
  std::deque<int> right_;
  void NormaliseCentralElement() {
    if (right_.size() > left_.size()) {
      left_.emplace_back(right_.front());
      right_.pop_front();
    }
  }

 public:
  GoblinQueue() {}
  void EmplaceBack(int num) {
    right_.emplace_back(num);
    NormaliseCentralElement();
  }
  void EmplaceMiddle(int num) {
    right_.emplace_front(num);
    NormaliseCentralElement();
  }
  int PopFront() {
    int num = left_.front();
    left_.pop_front();
    NormaliseCentralElement();
    return num;
  }
};

int main() {
  GoblinQueue goblin_queue;
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    char command;
    std::cin >> command;
    if (command == '+') {
      int num;
      std::cin >> num;
      goblin_queue.EmplaceBack(num);
    } else if (command == '*') {
      int num;
      std::cin >> num;
      goblin_queue.EmplaceMiddle(num);
    } else {
      std::cout << goblin_queue.PopFront() << "\n";
    }
  }
}
