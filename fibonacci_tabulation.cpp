#include <iostream>
#include <vector>

int fib(std::vector<int> &nums, int n) {
  for (int i{3}; i <= n; ++i) {
    nums[i] = nums[i - 1] + nums[i - 2];
  }
  return nums[n];
}

int main() {
  int n{};
  std::cout << "Enter an index: ";
  std::cin >> n;

  std::vector<int> nums(n + 1, -1);
  nums[1] = 1;
  nums[2] = 1;

  std::cout << "fibonacci number at that index is: " << fib(nums, n) << '\n';

  return 0;
}
