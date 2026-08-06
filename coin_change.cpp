#include <iostream>
#include <vector>

int min_coins(int change, const std::vector<int> &coins,
              std::vector<int> &memo) {
  if (change < 0) {
    return -1;
  } // impossible to give change
  if (change == 0) {
    return 0;
  } // no change needed
  int overall_min{-1};
  if (memo[change] != -2) {
    return memo[change];
  }
  for (int coin : coins) {
    int res{min_coins(change - coin, coins, memo)};
    if (res != -1) {
      int current_min{res + 1};
      if (overall_min == -1 || current_min < overall_min) {
        overall_min = current_min;
      }
    }
  }
  memo[change] = overall_min;
  return overall_min;
}

int main() {
  std::vector<int> coins{1, 2, 5};
  int change{};
  std::cout << "Enter change needed: ";
  std::cin >> change;

  std::vector<int> memo(
      change + 1, -2); // sets length to change+1, defaults all values to -2
  std::cout << "Min coins needed: " << min_coins(change, coins, memo) << '\n';

  return 0;
}
