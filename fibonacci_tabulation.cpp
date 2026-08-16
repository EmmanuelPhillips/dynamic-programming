#include <iostream>
#include <vector>

int fib(int n) {
  std::vector<int> nums(n + 1, -1);
  nums[1] = 1;
  nums[2] = 1;
  for (int i{3}; i <= n; ++i) {
    nums[i] = nums[i - 1] + nums[i - 2];
  }
  return nums[n];
}

int main() {
  int n{};
  std::cout << "Enter an index: ";
  std::cin >> n;

  std::cout << "fibonacci number at that index is: " << fib(n) << '\n';

  return 0;
}
