#include <Statistics.h>

#include <iostream>

int main() {
  swo::stats::Statistics a;

  int x = 0;
  while (std::cin >> x) {
    a.collect(x);
  }

  std::cout << "Count: " << a.count() << '\n';
  std::cout << "Sum: " << a.sum() << '\n';
  std::cout << "Average: " << a.average() << '\n';
  //std::cout << "Standard deviation: " << a.standard_deviation();
}
