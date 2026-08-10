#include <iostream>
#include <vector>

int main() { return 0; }

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
