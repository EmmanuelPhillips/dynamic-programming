#include <iostream>
#include <vector>

int min_coins(int change, const std::vector<int> &coins) { return 1; }

int main() {
  int change{11};
  std::vector<int> coin_options{1, 2, 5};

  std::cout << "Min coins needed: " << min_coins(change, coin_options);

  return 0;
}
