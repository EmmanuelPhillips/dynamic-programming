#include <iostream>
#include <vector>

int min_coins(int change, const std::vector<int> &coins) {
  if (change < 0) {
    return -1;
  } // impossible to give change
  if (change == 0) {
    return 0;
  } // no change needed
  int overall_min{-1};
  for (int coin : coins) {
    int res{min_coins(change - coin, coins)};
    if (res != -1) {
      int current_min{res + 1};
      if (overall_min == -1 || current_min < overall_min) {
        overall_min = current_min;
      }
    }
  }
  return overall_min;
}

int main() {
  std::vector<int> coins{1, 2, 5};
  int change{};
  std::cout << "Enter change needed: ";
  std::cin >> change;

  std::cout << "Min coins needed: " << min_coins(change, coins) << '\n';

  return 0;
}
