#include <iostream>
#include <vector>

int fib(int index, std::vector<int> &memo) {
  if (index < 1) {
    std::cout << "please enter a positive index.\n";
    return 1;
  }
  if (index == 1 || index == 2) {
    return 1;
  }
  if (memo[index] != -1) {
    return memo[index];
  }
  int res{fib(index - 1, memo) + fib(index - 2, memo)};

  memo[index] = res;
  return res;
}

int main() {
  int index{};
  std::cout << "Enter fibonacci number index: ";
  std::cin >> index;

  std::vector<int> memo(index + 1, -1);

  std::cout << "number at position " << index << ": " << fib(index, memo)
            << '\n';

  return 0;
}
