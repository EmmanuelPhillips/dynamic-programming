#include <iostream>
#include <vector>

int rob_houses(std::vector<int> &houses, int num_houses,
               std::vector<int> &memo) {
  if (num_houses <= 0) {
    return 0;
  }

  if (memo[num_houses] != -1) {
    return memo[num_houses];
  }

  int rob{houses[num_houses - 1] + rob_houses(houses, num_houses - 2, memo)};
  int dont_rob{rob_houses(houses, num_houses - 1, memo)};

  int res{std::max(rob, dont_rob)};
  memo[num_houses] = res;
  return res;
}

int main() {
  std::vector<int> houses{3, 1, 4, 7, 9, 5};
  int num_houses{static_cast<int>(houses.size())};

  std::vector<int> memo(num_houses + 1, -1);

  std::cout << "Max value from robbing this set of houses: "
            << rob_houses(houses, num_houses, memo) << '\n';

  return 0;
}

/* thinking on paper
 * you have two options: rob or dont rob. based off of this, you will then have
 * another two "paths". rob 2 houses down, or rob the adjacent house, or rob
 * neither. we need to find the max of both paths. for this, im guessing we will
 * always return max(rob, dont rob)
 * the base case is when there is no adjacent house?
 */
