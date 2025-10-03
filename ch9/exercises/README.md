### 📚 EXERCISES Chapter 9

---

1. Write a program that reads a text file and converts its input to all lowercase, producing a new file.

2. Write a program that given a file name and a word will output each line that contains that word together with the line number. Hint: getline().

3. Write a program that removes all vowels from a file (“disemvowels”). For example, __`Once upon a time!`__ becomes __`nc pn tm!`__. Surprisingly often, the result is still readable; try it on your friends.

4. Write a program called `multi_input.cpp` that prompts the user to enter several integers in any combination of octal, decimal, or hexadecimal, using the `0` and `0x` base prefixes; interprets the numbers correctly; and converts them to decimal form. Then your program should output the values in properly spaced columns like this:
```c++
    0x43    hexadecimal     converts to      67    decimal
    0123    octal           converts to      83    decimal
    65      decimal         converts to      65    decimal
```

5. Write a program that reads strings and for each string outputs the character classification of each character, as defined by the character classification functions presented in __`§9.10.3`__. Note that a character can have several classifications (e.g., x is both a letter and an alphanumeric).

6. Write a program that replaces punctuation with whitespace. Consider `.` (dot), `;` (semicolon), `,` (comma), `?` (question mark), `−` (dash), `’` (single quote) punctuation characters. Don’t modify characters within a pair of double quotes ("). For example, “__`− don’t use the as−if rule.`__” becomes “__`don t use the as if rule `__”.

7. Modify the program from the previous exercise so that it replaces `don’t` with `do not`, `can’t` with `cannot`, etc.; leaves hyphens within words intact (so that we get “__`do not use the as−if rule `__”); and converts all characters to lowercase.

8. Use the program from the previous exercise to make a sorted list of words. Run the result on a multi-page text file, look at the result, and see if you can improve the program to make a better list.

9. Write a function `vector<string> split(const string& s)` that returns a `vector` of whitespace-separated substrings from the argument `s`.

10. Write a function `vector<string> split(const string& s, const string& w)` that returns a `vector` of whitespace-separated substrings from the argument `s`, where whitespace is defined as “ordinary whitespace” plus the characters in `w`.

11. Reverse the order of characters in a text file. For example, __`asdfghjkl`__ becomes __`lkjhgfdsa`__. Warning: There is no really good, portable, and efficient way of reading a file backward.

12. Reverse the order of words (defined as whitespace-separated strings) in a file. For example, __`Norwegian Blue parrot`__ becomes __`parrot Blue Norwegian`__. Assume that all the strings from the file will fit into memory at once.

13. Write a program that reads a text file and writes out how many characters of each character classification (__`§9.10.3`__) are in the file.

14. Write a program that reads a file of whitespace-separated numbers and outputs a file of numbers using scientific format and precision 8 in four fields of 20 characters per line.

15. Write a program to read a file of whitespace-separated numbers and output them in order (lowest value first), one value per line. Write a value only once, and if it occurs more than once write the count of its occurrences on its line. For example, `75573 117 5` should give
```c++
    3
    5    3
    7    2
    117
```

16. Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.

17. Write a program that creates a file of data in the form of the temperature `Reading` type defined in __`§9.3.2`__. For testing, fill the file with at least 50 “temperature readings.” Call this program `store_temps.cpp` and the file it creates `raw_temps.txt`.

18. Write a program that reads the data from __`raw_temps.txt`__ created in __`exercise 2`__ into a vector and then calculates the mean and median temperatures in your data set. Call this program __`temp_stats.cpp`__.

19. Modify the __`store_temps.cpp`__ program from __`exercise 2`__ to include a temperature suffix c for Celsius or f for Fahrenheit temperatures. Then modify the __`temp_stats.cpp`__ program to test each temperature, converting the Celsius readings to Fahrenheit before putting them into the vector.

20. Write the function __`print_year()`__ mentioned in __`§9.9.2`__.

21. Define a `Roman_int` class for holding Roman numerals (as `int`s) with a `<<` and `>>`. Provide `Roman_int` with an `as_int()` member that returns the int value, so that if `r` is a `Roman_int`, we can write __`cout << "Roman" << r << " equals " << r.as_int() << ’\n’;`__.

22. Make a version of the calculator from `Chapter 6` that accepts Roman numerals rather than the usual Arabic ones, for example, XXI + CIV == CXXV.

23. Write a program that accepts two file names and produces a new file that is the contents of the first file followed by the contents of the second; that is, the program concatenates the two files.

24. Write a program that takes two files containing sorted whitespace-separated words and merges them, preserving order.

25. Add a command `from x` to the calculator from __`Chapter 6`__ that makes it take input from a file `x`. Add a command `to y` to the calculator that makes it write its output (both standard output and error output) to file `y`. Write a collection of test cases based on ideas from __`§6.3`__ and use that to test the calculator. Discuss how you would use these commands for testing.

26. Write a program that produces the sum of all the whitespace-separated integers in a text file. For example, bears: 17 elephants 9 end should output 26.