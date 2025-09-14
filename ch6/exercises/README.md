### 📚 EXERCISES

---

1. Allow underscores in the calculator’s variable names.

2. Provide an assignment operator, `=,` so that you can change the value of a variable after you have introduced it using `let`. Discuss why that can be useful and how it can be a source of problems.

3. Provide named constants that you really can’t change the value of. Hint: You have to add a member to `Variable` that distinguishes between constants and variables and check for it in `set_value()`. If you want to let the user define constants (rather than just having pi and e defined as constants), you’ll have to add a notation to let the user express that, for example, `const pi = 3.14;`.

4. The `get_value()`, `set_value()`, `is_declared()`, and `define_name()` functions all operate on the variable `var_table`. Define a class called `Symbol_table` with a member var_table of type `vector<Variable>` and member functions `get()`, `set()`, `is_declared()`, and `declare()`. Rewrite the calculator to use a variable of type `Symbol_table`.

5. Modify `Token_stream::get()` to return `Token(print)` when it sees a newline. This implies looking for whitespace characters and treating newline (`'\n'`) specially. You might find the standard-library function `isspace(ch)`, which returns `true` if `ch` is a whitespace character, useful.

6. Part of what every program should do is to provide some way of helping its user. Have the calculator print out some instructions for how to use the calculator if the user presses the H key (both upper- and lowercase).

7. Change the `q` and `h` commands to be `quit` and `help`, respectively.

8. The grammar in __`§6.6.4`__ is incomplete (we did warn you against overreliance on comments); it does not define sequences of statements, such as `4+4; 5−6;`, and it does not incorporate the grammar changes outlined in __`§6.8`__. Fix that grammar. Also add whatever you feel is needed for that comment as the first comment of the calculator program and its overall comment.

9. Suggest three improvements (not mentioned in this chapter) to the calculator. Implement one of them.

10. Modify the calculator to operate on `int`s (only); give errors for overflow and underflow. Hint: Use `narrow` (__`§6.5`__).

11. Revisit two programs you wrote for the exercises in __`§3`__ or `Chapter 4`. Clean up that code according to the rules outlined in this chapter. See if you find any bugs in the process.

12. Modify the calculator to accept input from any `istream`.