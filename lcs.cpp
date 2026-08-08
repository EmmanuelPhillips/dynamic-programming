#include <cstddef>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int lcs(std::string_view s1, std::string_view s2, int i, int j,
        std::vector<std::vector<int>> memo) {

  if (i == 0 || j == 0) {
    return 0;
  }

  if (memo[i][j] != -1) {
    return memo[i][j];
  }

  int res{0};

  if (s1[i - 1] == s2[j - 1]) {
    res = (1 + lcs(s1, s2, i - 1, j - 1, memo));
  } else {
    return std::max(lcs(s1, s2, i - 1, j, memo), lcs(s1, s2, i, j - 1, memo));
  }

  memo[i][j] = res;
  return res;
}

int main() {
  std::string s1{};
  std::cout << "Enter a string: ";
  std::cin >> s1;

  std::string s2{};
  std::cout << "Enter a string: ";
  std::cin >> s2;

  std::vector<std::vector<int>> memo(s1.length() + 1,
                                     std::vector<int>(s2.length() + 1, -1));

  int i{static_cast<int>(s1.length())};
  int j{static_cast<int>(s2.length())};

  std::cout << "Longest common subsequence: " << lcs(s1, s2, i, j, memo)
            << '\n';

  return 0;
}
