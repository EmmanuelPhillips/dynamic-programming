#include <iostream>
#include <string>
#include <string_view>
#include <vector>

int lcs(std::string_view s1, std::string_view s2,
        const std::vector<std::vector<int>> memo) {
  return 0;
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

  std::cout << "Longest common substring: " << lcs(s1, s2, memo) << '\n';

  return 0;
}
