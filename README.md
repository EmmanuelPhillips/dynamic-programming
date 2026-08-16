# dynamic programming

## overview

my repository to do with all questions regarding dynamic programming. this is my
weakest area in dsa, and it is heavily tested in interviews and definitely
builds stronger problem solving ability. it is essential i develop these skills

--------------------------------------------------------------------------------

## coin change

### goal

to be able to figure out the minimum number of coins needed to give x amount of
change

### memoisation approach

#### what i learnt

the core idea of dynamic programming: breaking a problem into overlapping
subproblems, solving each one once, and reusing the result instead of
recomputing it. i learnt the difference between memoisation (top-down, recursion
plus a cache) and tabulation (bottom-up, iterative), and implemented memoisation
here specifically. i also learnt the difference between a naive recursive
approach and a greedy approach. my first instinct was actually greedy (always
take the biggest coin that fits), which happens to work for coins like {1, 2, 5}
but fails for arbitrary coin sets, dp guarantees the correct answer regardless
of the denominations given. practically, i learnt that a memo cache should be
indexed directly by the subproblem's input (change amount), not searched
through, and that it needs a sentinel value (e.g. -2) to distinguish "not yet
solved" from a real answer

#### challenges

this was genuinely difficult. i wrote the naive recursive version myself with
minimal help, but i struggled badly with memoisation, i needed heavy guidance to
understand where the cache check needed to go (before the loop, to actually skip
redundant work) and where the cache write needed to go (after the loop finishes,
not mid-loop, since the answer isn't final until every coin's been tried). i
initially thought the cache needed to be a vector of vectors that i'd search
through, rather than directly indexed by the change value itself. i want to be
honest that i relied on being given the corrected structure rather than deriving
it independently, this is a genuine weak point right now, not a small gap

#### changes for next time

attempt the next dp problem with zero code given to me, conceptual hints only.
specifically force myself to work out unaided: what the recursive relation is,
what needs to be cached, and where the cache check/write belong in the function,
before looking at any solution

--------------------------------------------------------------------------------

## fibonacci

### goal

to calculate the nth fibonacci number, using 1-based indexing (position 1 and 2
both return 1, position 3 returns 2, etc, matching how i'd naturally count
rather than starting at 0)

### memoisation approach

#### what i learnt

this felt significantly easier than coin change, mainly because fibonacci has a
single, fixed recursive relation with no choice involved (unlike coin change,
where i had to try every coin and compare results). this let me focus purely on
getting the memoisation structure right without also juggling a decision at each
step. i also learnt about integer overflow the hard way, testing index 100
returned a nonsensical negative number, since fib(100) is far larger than a
standard int can hold. i understand this is because int silently wraps around on
overflow rather than throwing an error. the practical fix (switching to long
long, or unsigned long long with a different sentinel approach) is understood
conceptually, but i chose not to implement it for this exercise, not worth the
added complexity for what this problem is meant to teach me

#### challenges

honestly, i'm not fully sure how much of this being easier was genuine
understanding versus doing it immediately after coin change, with the concepts
still fresh. i want to properly test this by attempting a similarly structured
problem after a longer gap and seeing if it's still straightforward

#### changes for next time

retest myself on a simple 1d memoisation problem after a few days' gap, not
immediately after another dp problem, to get an honest read on whether this has
actually sunk in or whether it was short-term recall

### tabulation approach

#### what i learnt

tabulation builds the answer bottom-up with a loop, instead of recursing down
from n and caching results. i seed the known base cases directly into the table
before the loop starts, since there's no recursion to naturally hit them. each
loop iteration only reads values already computed earlier in the same table, so
by the time you reach index n, everything it depends on already exists. i also
decided to build the table inside the function rather than passing it in from
main, since nothing outside fib() actually needs to inspect the intermediate
values, only the final answer. this felt like a better interface than my
memoised version, which passes the memo table in by reference, useful there
since main() needed to own and size it before the first call, but not needed
here since tabulation builds and discards the table entirely within one function
call. this was noticeably easier than writing the memoised version, mainly
because there's no recursion to reason about at all, just a single indexing
convention to get right and a straightforward forward loop

#### challenges

my first attempt had a sizing/indexing mismatch, the vector was sized to n
instead of n+1, and my base cases were seeded at index 0/1 while the rest of the
function assumed 1-based indexing. this was a repeat of an indexing carelessness
i've hit before, worth being more careful about upfront rather than fixing after
testing catches it

#### changes for next time

attempt coin change with tabulation next, expect this to be harder than
fibonacci since it needs a nested loop (checking every coin against every
amount) rather than a single pass

--------------------------------------------------------------------------------

## longest common subsequence (lcs)

### goal

given two strings, find the length of the longest subsequence that appears in
both, in the same relative order, not necessarily contiguous

### memoisation approach

#### what i learnt

this was my first 2d dp problem, the cache needed to be a grid (vector of
vectors) rather than a single 1d vector, indexed by a position in each string
simultaneously, rather than a single shrinking value like fibonacci or coin
change. i learnt the recursive relation isn't a simple forward scan through both
strings, my first instinct was to walk both strings in lockstep, but this can't
find subsequences that require skipping characters in only one string while
staying in place on the other. the actual relation checks whether the current
characters match: if they do, add 1 and recurse on both strings shifted back by
one, if they don't, try shifting back on s1 only or s2 only, and take whichever
gives the longer result. i also reinforced two mistakes from coin change that
resurfaced here: passing the memo table by value instead of by reference
(silently breaking memoisation without breaking correctness), and only writing
to the cache in one branch of an if/else rather than both, meaning half the
subproblems never actually got cached

#### challenges

figuring out the actual subproblems needed was the hardest part, i understood
the general dp pattern (cache check, recurse, cache write) from coin change, but
working out what i and j should represent, and why the base case is when either
hits 0, took real effort to reason through rather than pattern match

#### changes for next time

before writing any code, explicitly write out (in comments or on paper) what the
recursive relation is and what the base case represents, rather than starting
with a loop-based instinct and correcting it after. this would likely catch the
"lockstep scanning" mistake before writing any code at all

--------------------------------------------------------------------------------

## knapsack

### goal

given a set of items, each with a weight and a value, and a knapsack with a
maximum weight capacity, choose a subset of items to maximise total value
without exceeding capacity. each item can only be used once

### memoisation approach

#### what i learnt

this was another 2d dp problem, but unlike lcs, the two axes represent something
different: which item you're currently deciding about, and how much capacity you
have left, not two positions in two separate sequences. the recursion is a
genuine binary choice per item, take it or leave it, rather than a
comparison-based relation like lcs had. i learnt the weight check
(`items[i][0] <= j`) has nothing to do with the memo table at all, it's just a
real-world feasibility check asking "does this item physically fit in the space
i have left". the memo table itself stores answers to subproblems, not weights
or values from the items list, i confused these two things initially. i also hit
the same bug pattern twice more, returning early from an if branch and skipping
the memo write, and forgetting to update the actual return value at the end of
the function. both are becoming familiar mistakes now, worth actively checking
for on every new dp problem

#### challenges

i genuinely didn't understand what i'd written even after it worked. i could get
the code to produce the right output but couldn't explain what i and j meant,
why the comparison was against j and not something in memo, or what each memo
cell actually represented. asking for a step-by-step visual trace of the
recursion and memo table filling in was what actually made it click, seeing
memo[i][j] get written cell by cell, and seeing a later call hit an
already-filled cell and return instantly instead of recursing, made the abstract
explanation concrete. this is a real gap to be honest about: i was
pattern-matching the structure from coin change and lcs rather than reasoning
through knapsack's specific logic from scratch, my "on paper" notes show me
initially trying to force it into lcs's diagonal-grid shape, which wasn't the
right fit

#### changes for next time

before writing any code on the next dp problem, explicitly state in plain
english what i and j (or whatever the parameters are) represent, and get that
confirmed as correct before touching the recursive relation. this would have
caught the mismatch earlier. if a problem doesn't click after getting it
working, ask for a visual trace immediately rather than moving on with
surface-level understanding, this was much faster at building real intuition
than reading an explanation again

--------------------------------------------------------------------------------

## climbing stairs

### goal

given a staircase with n steps, where each move can climb 1 or 2 steps, find the
number of distinct ways to reach the top

### memoisation approach

#### what i learnt

this is structurally identical to fibonacci, the answer for n stairs is
literally fibonacci(n+1), which only became obvious after testing my output (5
for n=4, 8 for n=5) and recognising the sequence. the recursive relation follows
directly from thinking about the last move: to reach step n, you either took a
single step from n-1, or a double step from n-2, so the total ways to reach n is
the sum of ways to reach each of those two positions. i went into this on
intuition rather than writing the relation out in plain english first, which was
against what i said i'd do in my knapsack readme. it worked out fine here since
the problem was simple enough, but it's not proof the habit isn't still worth
building for harder problems

#### challenges

i added an unnecessary "+1" to the recursive formula
(`1 + stairs(n-1) + stairs(n-2)`), which doesn't correspond to anything real in
the problem, it wasn't caught until tracing through a small case by hand. the
actual relation is just the sum of the two prior results, no extra term. this
was a useful reminder to sanity check outputs against a hand-counted small
example before trusting the code, rather than assuming it's right because it
compiles and runs

#### changes for next time

go back to writing the plain-english explanation of the recursive relation
before coding, even for problems that feel intuitive, since the "+1" bug shows
intuition alone isn't a reliable enough check

--------------------------------------------------------------------------------

## house robber

### goal

given an array of house values along a street, choose a subset of houses to rob
that maximises total value, without robbing two adjacent houses

### memoisation approach

#### what i learnt

this introduced a genuine choice per element, similar in spirit to knapsack's
take/leave, but in 1d. the two options are rob the current house (add its value,
then skip to two houses back) or don't rob it (move to just one house back), and
the answer at each step is the max of those two paths. answering the three
questions before coding this time (what does the parameter represent, what
happens under each choice, what's the base case) genuinely helped, compared to
climbing stairs where i skipped that step and it happened to work out anyway.
writing out that robbing moves the index back by 2 and not robbing moves it back
by 1 made the recursive calls obvious before i wrote any code

#### challenges

my first working attempt had two real bugs: i recursed on the "rob" path without
ever adding the actual value of the house being robbed, and my base case
(`num_houses >= 0`) let the recursion continue into negative territory, which
would have caused an out-of-bounds memo access and crashed. the second bug is a
repeat of a pattern i've now hit a few times, checking the memo or doing work
before confirming the base case properly stops the recursion. i'm starting to
recognise this as a habit to specifically watch for: base case first, fully
stopping any further recursion or indexing, before anything else happens in the
function

#### changes for next time

specifically double check, for every new dp problem, that the base case is
checked first and correctly prevents any negative or out-of-bounds indexing
before the memo check or recursive calls happen. consider attempting house
robber ii (houses in a circle, first and last are also adjacent) to test
adapting an already-solved pattern to a new constraint, rather than starting a
completely new problem from scratch each time
