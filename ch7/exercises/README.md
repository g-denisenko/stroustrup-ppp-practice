### 📚 EXERCISES Chapter 7

---

1. Modify the calculator program from `Chapter 6` to make the input stream an explicit parameter (as shown in __`§7.4.8`__), rather than simply using `cin`. Also give the `Token_stream` constructor (__`§6.8.2`__) an `istream&` parameter so that when we figure out how to make our own `istream`s (e.g., attached to files), we can use the calculator for those. Hint: Don’t try to copy an `istream`.

2. Write a function `print()` that prints a vector of `int`s to `cout`. Give it two arguments: a `string` for “labeling” the output and a `vector`.

3. Create a `vector` of Fibonacci numbers and print them using the function from __`exercise 2`__. To create the `vector`, write a function, `fibonacci(x,y,v,n)`, where `integer`s `x` and `y` are `int`s, `v` is an empty `vector<int>`, and `n` is the number of elements to put into `v`; `v[0]` will be `x` and `v[1]` will be `y`. A Fibonacci number is one that is part of a sequence where each element is the sum of the two previous ones. For example, starting with 1 and 2, we get 1, 2, 3, 5, 8, 13, 21, ... . Your `fibonacci()` function should make such a sequence starting with its `x` and `y` arguments.

4. An `int` can hold integers only up to a maximum number. Find an approximation of that maximum number by using `fibonacci()`.

5. Write two functions that reverse the order of elements in a `vector<int>`. For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function should produce a new `vector` with the reversed sequence, leaving its original `vector` unchanged. The other reverse function should reverse the elements of its `vector` without using any other `vector`s (hint: `swap`).

6. Write versions of the functions from __`exercise 5`__, but with a `vector<string>`.

7. Read five names into a v`ector<string> name`, then prompt the user for the ages of the people named and store the ages in a `vector<double> age`. Then print out the five (`name[i],age[i]`) pairs. Sort the names (`sort(name.begin(),name.end())`) and print out the (`name[i],age[i]`) pairs. The tricky part here is to get the `age` `vector` in the correct order to match the sorted `name vector`. Hint: Before sorting `name`, take a copy and use that to make a copy of `age` in the right order after sorting `name`.

8. Do the previous __`exercise`__ but allow an arbitrary number of names.

9. Write a function that given two `vector<double>`s `price` and `weight` computes a value (an “index”) that is the sum of all `price[i]*weight[i]`. Make sure to have `weight.size()==price.size()`.

10. Write a function `maxv()` that returns the largest element of a `vector` argument.

11. Write a function that finds the smallest and the largest element of a `vector` argument and also computes the mean and the median. Do not use global variables. Either return a `struct` containing the results or pass them back through reference arguments. Which of the two ways of returning several result values do you prefer and why?

12. Improve `print_until_s()` from __`§7.4.2`__. Test it. What makes a good set of test cases? Give reasons. Then, write a `print_until_ss()` that prints until it sees a second occurrence of its `quit` argument.

13. Write a function that takes a `vector<string>` argument and returns a `vector<int>` containing the number of characters in each `string`. Also find the longest and the shortest `string` and the lexicographically first and last `string`. How many separate functions would you use for these tasks? Why?

14. Can we declare a non-reference function argument `const` (e.g., `void f(const int);`)? What might that mean? Why might we want to do that? Why don’t people do that often? Try it; write a couple of small programs to see what works.