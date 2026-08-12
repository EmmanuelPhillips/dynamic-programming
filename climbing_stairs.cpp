#include <iostream>
#include <vector>

int stairs(int num_stairs, std::vector<int> &memo) {
  if (memo[num_stairs] != -1) {
    return memo[num_stairs];
  }
  if (num_stairs <= 1) {
    return 1;
  } else {
    memo[num_stairs] =
        stairs(num_stairs - 1, memo) + stairs(num_stairs - 2, memo);
  }
  return memo[num_stairs];
}

int main() {
  int num_stairs{};
  std::cout << "Enter number of stairs: ";
  std::cin >> num_stairs;

  std::vector<int> memo(num_stairs + 1, -1);

  std::cout << "There are " << stairs(num_stairs, memo) << " ways to climb "
            << num_stairs << " stairs.\n";
  return 0;
}
