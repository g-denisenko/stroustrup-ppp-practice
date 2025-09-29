### 📚 EXERCISES Chapter 8

---

1. List plausible operations for the examples of real-world objects in __`§8.1`__ (e.g., a toaster)

2. Design and implement a `Name_pairs` class holding (name,age) pairs where name is a `string` and age is a `double`. Represent that as a `vector<string>` (called `name`) and a` vector<double>` (called `age`) member. Provide an input operation `read_names()` that reads a series of names. Provide a `read_ages()` operation that prompts the user for an age for each name. Provide a `print()` operation that prints out the (`name[i]`,`age[i]`) pairs (one per line) in the order determined by the `name` vector. Provide a `sort()` operation that sorts the `name` vector in alphabetical order and reorganizes the `age` vector to match. Implement all “operations” as member functions. Test the class (of course: test early and often).

3. Replace `Name_pair::print()` with a (global) operator `<<` and define `==` and `!=` for `Name_pair`s.

4. Do the previous exercise again but implement `Name_pair`s using a `Name_pair` class.

5. This exercise and the next few require you to design and implement a `Book` class, such as you can imagine as part of software for a library. Class `Book` should have members for the ISBN, title, author, and copyright date. Also store data on whether or not the book is checked out. Create functions for returning those data values. Create functions for checking a book in and out. Do simple validation of data entered into a `Book`; for example, accept ISBNs only of the form `n−n−n−x` where `n` is an integer and `x` is a digit or a letter. Store an ISBN as a `string`.

6. Add operators for the `Book` class. Have the `==` operator check whether the ISBN numbers are the same for two books. Have `!=` also compare the ISBN numbers. Have a `<<` print out the title, author, and ISBN on separate lines.

7. Create an enumerated type for the `Book` class called `Genre`. Have the types be fiction, nonfiction, periodical, biography, and children. Give each book a `Genre` and make appropriate changes to the `Book` constructor and member functions.

8. Create a `Patron` class for the library. The class will have a user’s name, library card number, and library fees (if owed). Have functions that access this data, as well as a function to set the fee of the user. Have a helper function that returns a Boolean (`bool`) depending on whether or not the user owes a fee.

9. Create a `Library` class. Include vectors of `Books` and `Patrons`. Include a `struct` called `Transaction` to record when a book is checked out. Have it include a `Book`, a `Patron`, and a `Date`. Make a vector of `Transactions` to keep a record of which books are out. Create functions to add books to the library, add patrons to the library, and check out books. Whenever a user checks out a book, have the library make sure that both the user and the book are in the library. If they aren’t, report an error. Then check to make sure that the user owes no fees. If the user does, report an error. If not, create a `Transaction`, and place it in the vector of `Transactions`. Also write a function that will return a vector that contains the names of all `Patrons` who owe fees.

10.  Implement `leapyear(int)`.

11. Design and implement a set of useful helper functions for the `Date` class with functions such as `next_workday()` (assume that any day that is not a Saturday or a Sunday is a workday) and `week_of_year()` (assume that week 1 is the week with January 1 in it and that the first day of a week is a Sunday).

12. Change the representation of a `Date` to be the number of days since January 1, 1970 (known as day 0), represented as a      (that is, an `int` that can hold much larger integers than plain `int`), and re-implement the `Date` member functions from __`§8.4.2`__. Be sure to reject dates outside the range we can represent that way (feel free to reject days before day 0, i.e., no negative days).

13. Design and implement a rational number class, `Rational`. A rational number has two parts: a numerator and a denominator, for example, 5/6 (five-sixths, also known as approximately .83333). Look up the definition if you need to. Provide assignment, addition, subtraction, multiplication, division, and equality operators. Also, provide a conversion to `double`. Why would people want to use a `Rational` class?

14. Design and implement a `Money` class for calculations involving dollars and cents where arithmetic has to be accurate to the last cent using the 4/5 rounding rule (.5 of a cent rounds up; anything less than .5 rounds down). Represent a monetary amount as a number of cents in a `long int`, but input and output as dollars and cents, e.g., $123.45. Do not worry about amounts that don’t fit into a `long int`.

15. Refine the `Money` class by adding a currency (given as a constructor argument). Accept a floating-point initializer as long as it can be exactly represented as a `long int`. Don’t accept illegal operations. For example, `Money*Money` doesn’t make sense, and `USD1.23+DKK5.00` makes sense only if you provide a conversion table defining the conversion factor between U.S. dollars (USD) and Danish kroner (DKK).

16. Define an input operator (`>>`) that reads monetary amounts with currency denominations, such as `USD1.23` and `DKK5.00`, into a `Money` variable. Also define a corresponding output operator (`<<`).

17. Give an example of a calculation where a `Rational` gives a mathematically better result than `Money`.

18. Give an example of a calculation where a `Rational` gives a mathematically better result than `double`.