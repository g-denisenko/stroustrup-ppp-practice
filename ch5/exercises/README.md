### 📚 EXERCISES

---

1. If you haven’t already, do the **TRY THIS** exercises from this chapter.

2. Add the ability to use `{}` as well as `()` in the program, so that `{(4+5)*6} / (3+4)` will be a valid expression.

3. Add a factorial operator: use a suffix `!` operator to represent “factorial.” For example, the expression `7!` means `7 * 6 * 5 * 4 * 3 * 2 * 1`. Make `!` bind tighter than `*` and `/`; that is, `7*8!` means `7*(8!)` rather than `(7*8)!`. Begin by modifying the grammar to account for a higher-level operator. To agree with the standard mathematical definition of factorial, let `0!` evaluate to `1`. Hint: The calculator functions deal with `doubles`, but factorial is defined only for `int`s, so just for `x!`, assign the `x` to an `int` and calculate the factorial of that `int`.
4. Define a class *`Name_value`* that holds a string and a value. Rework exercise 20 in Chapter 3 to use a *`vector<Name_value>`* instead of two `vectors`.

5. Write a grammar for bitwise logical expressions. A bitwise logical expression is much like an arithmetic expression except that the operators are `!` (not), `˜` (complement), `&` (and), `|` (or), and `ˆ` (exclusive or). Each operator does its operation to each bit of its integer operands (see PPP2.§25.5). `!` and `˜` are prefix unary operators. A `ˆ` binds tighter than a `|` (just as `*` binds tighter than `+`) so that `x|yˆz` means `x|(yˆz)` rather than `(x|y)ˆz`. The `&` operator binds tighter than `ˆ` so that `xˆy&z` means `xˆ(y&z)`.

6. Redo the *`“Bulls and Cows”`* game from exercise 12 in Chapter 4 to use four letters rather than four digits.

7. Write a program that reads digits and composes them into integers. For example, `123` is read as the characters 1, 2, and 3. The program should output `123` is `1 hundred and 2 tens and 3 ones`. The number should be output as an `int` value. Handle numbers with one, two, three, or four digits. Hint: To get the integer value `5` from the character `'5'` subtract `'0'`, that is, `'5'−'0'==5`.

8. A permutation is an ordered subset of a set. For example, say you wanted to pick a combination to a vault. There are 60 possible numbers, and you need three different numbers for the combination. There are *`P(60, 3)`* permutations for the combination, where *`P`* is defined by the formula *`P(a, b) = (a!) / ((a - b)!)`* where *!* is used as a suffix factorial operator. For example, `4!` is `4*3*2*1`.
Combinations are similar to permutations, except that the order of the objects doesn’t matter. For example, if you were making a “banana split” sundae and wished to use three different flavors of ice cream out of five that you had, you probably wouldn’t care if you put a scoop of vanilla at the beginning or the end or the serving dish. The formula for combinations is *`C(a, b) = (P(a, b)) / (b!)`*.
Design a program that asks users for two numbers, asks them whether they want to calculate permutations or combinations, and prints out the result. This will have several parts. Do an analysis of the above requirements. Write exactly what the program will have to do. Then, go into the design phase. Write pseudo code for the program and break it into subcomponents. This program should have error checking. Make sure that all erroneous inputs will generate good error messages.