#include <iostream>
#include <vector>

int knapsack(int capacity, std::vector<std::vector<int>> &items,
             std::vector<std::vector<int>> &memo, int i, int j) {
  if (i == items.size() || j == 0) {
    return 0;
  } // if no bag space, or no items left.

  if (memo[i][j] != -1) {
    return memo[i][j];
  } // if alr known answer, then return that

  int res{0};
  if (items[i][0] <= j) {
    int leave = knapsack(capacity, items, memo, i + 1, j);
    int take =
        items[i][1] + knapsack(capacity, items, memo, i + 1, j - items[i][0]);

    res = std::max(leave, take);
  } else {
    res = knapsack(capacity, items, memo, i + 1, j);
  }

  memo[i][j] = res;
  return res;
}

int main() {

  int capacity{};
  std::cout << "enter knapsack capacity: ";
  std::cin >> capacity;

  std::vector<std::vector<int>> items{
      {2, 3}, // weight 2, value 3
      {3, 4}, // weight 3, value 4
      {4, 5}, // weight 4, value 5
      {5, 8}, // weight 5, value 8
      {9, 10} // weight 9, value 10
  }; // [weight][value]

  std::vector<std::vector<int>> memo(
      items.size() + 1,
      std::vector<int>(capacity + 1, -1)); // [value][capacity remaining]
  int i{0u};
  int j{0u};

  std::cout << "max value with capacity " << capacity
            << " is: " << knapsack(capacity, items, memo, i, j) << '\n';

  return 0;
}

/* breaking it down "on paper"
 * - will have:
 *   - a vector of items at indexes
 *   - int of target weight
 *   - int of current tracked weight left
 *   - memo setup.
 * - the recursion:
 *   - when one item is chosen, you can either take or leave it
 *   - the recursion could come from here i think?
 *   - the other option im thinking of is similar to coin_change.cpp, where the
 * memoisation was used to store the best ways to make values less than the
 * overall capacity.
 *   - i like this second idea more, as it seems to have.
 *
 * - new thinking:
 *   - i read the rest of the problem, there is also a value attributed to each
 * item.
 *   - the important thing is maxing out the value, without going over weight.
 *   - this makes it harder than coin_change.
 *
 *   - thinking of this as an array that has weight on one axis and value on the
 * other?
 *   - i might have to use some logic where its kind of like "if weight is
 * compatible and value is compatible, then move to square diagonally right (aka
 * ++i and ++j in code), and memoise".
 *   - otherwise, take the max of the recursion of increasing just i and just j.
 *
 *   - adjusting the memo, it would make more sense to store item index, and
 * then remaining capacity. this way, you can see "the best value achievable
 * using items from [i] onward, given x capacity"
 *
 */
