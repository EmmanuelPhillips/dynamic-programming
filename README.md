# dynamic programming
## overview
my repository to do with all questions regarding dynamic programming. this is my weakest area in DSA, and it is heavily tested in interviews and definitely builds stronger problem solving ability. it is essential i develop these skills
--- -
## coin change
### goal
to be able to figure out the minimum number of coins needed to give x amount of change.
### what i learnt
the core idea of dynamic programming: breaking a problem into overlapping subproblems, solving each one once, and reusing the result instead of recomputing it. i learnt the difference between memoisation (top-down, recursion plus a cache) and tabulation (bottom-up, iterative), and implemented memoisation here specifically.
i also learnt the difference between a naive recursive approach and a greedy approach. my first instinct was actually greedy (always take the biggest coin that fits), which happens to work for coins like {1, 2, 5} but fails for arbitrary coin sets, dp guarantees the correct answer regardless of the denominations given.
practically, i learnt that a memo cache should be indexed directly by the subproblem's input (change amount), not searched through, and that it needs a sentinel value (e.g. -2) to distinguish "not yet solved" from a real answer.
### challenges
this was genuinely difficult. i wrote the naive recursive version myself with minimal help, but i struggled badly with memoisation, i needed heavy guidance to understand where the cache check needed to go (before the loop, to actually skip redundant work) and where the cache write needed to go (after the loop finishes, not mid-loop, since the answer isn't final until every coin's been tried). i initially thought the cache needed to be a vector of vectors that i'd search through, rather than directly indexed by the change value itself.
i want to be honest that i relied on being given the corrected structure rather than deriving it independently, this is a genuine weak point right now, not a small gap.
### changes for next time
attempt the next dp problem with zero code given to me, conceptual hints only. specifically force myself to work out unaided: what the recursive relation is, what needs to be cached, and where the cache check/write belong in the function, before looking at any solution.
also want to implement the tabulation (bottom-up) version of coin change as a follow-up, to compare it against the memoized version and understand why it avoids recursion/stack depth issues.

