#include <cmath>
#include <iomanip>
#include <iostream>

class Calc {
  long double* prefix_logs_;

 public:
  Calc(size_t n) {
    prefix_logs_ = new long double[n];
    for (size_t i = 0; i < n; i++) {
      double num;
      std::cin >> num;
      prefix_logs_[i] =
          i > 0 ? prefix_logs_[i - 1] + std::log(num) : std::log(num);
    }
  }
  long double GetGeometricAverage(int a, int b) {
    return std::pow(2.718281828459,
                    (prefix_logs_[b] - (a > 0 ? prefix_logs_[a - 1] : 0)) /
                        static_cast<long double>(b - a + 1));
  }
  ~Calc() { delete[] prefix_logs_; }
};

int main() {
  int n;
  std::cin >> n;
  Calc calc(n);
  std::cin >> n;
  for (int i = 0; i < n; ++i) {
    int a, b;
    std::cin >> a >> b;
    std::cout.precision(9);
    std::cout << calc.GetGeometricAverage(a, b) << "\n";
  }
}
