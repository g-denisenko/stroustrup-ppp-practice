### 📚 DRILL

---

1. Starting from the file `calculator08buggy.cpp`, get the calculator to compile.

2. Go through the entire program and add appropriate comments.

3. As you commented, you found errors (deviously inserted especially for you to find). Fix them; they are not in the text of the book.

4. Testing: prepare a set of inputs and use them to test the calculator. Is your list pretty complete? What should you look for? Include negative values, 0, very small, very large, and “silly” inputs.

5. Do the testing and fix any bugs that you missed when you commented.

6. Add a predefined name `k` meaning `1000`.

7. Give the user a square root function `sqrt()`, for example, `sqrt(2+6.7)`. Naturally, the value of `sqrt(x)` is the square root of `x`; for example, `sqrt(9)` is `3`. Use the standard-library `sqrt()` function to implement that calculator `sqrt()`. Remember to update the comments, including the grammar.

8. Catch attempts to take the square root of a negative number and print an appropriate error message.

9. Allow the user to use `pow(x,i)` to mean “Multiply `x` with itself `i` times”; for example, `pow(2.5,3)` is `2.5*2.5*2.5`. Require `i` to be an integer using the technique we used for `%` (`§6.5`).

10. Change the “declaration keyword” from `let` to `#`.

11. “Change the “quit keyword” from `quit` to `exit`. That will involve defining a string for `quit` just as we did for `let` in `§6.8.2`.
This material may be protected by copyright.