### 📚 EXERCISES

---

1. If you haven’t already, do the TRY THIS exercises from this chapter.

2. The following program takes in a temperature value in Celsius and converts it to Kelvin. This code has many errors in it. Find the errors, list them, and correct the code.

```c
double ctok(double c)                 // converts Celsius to Kelvin
{
    int k = c + 273.25;
    return int
}

int main()
{
    double c = 0;                     // declare input variable
    cin >> d;                         // retrieve temperature to input variable
    double k = ctok("c");             // convert temperature
    Cout << k << '/n' ;               // print out temperature
}
```

3. Absolute zero is the lowest temperature that can be reached; it is -273.15C, or 0K. The above program, even when corrected, will produce erroneous results when given a temperature below this. Place a check in the main program that will produce an error if a temperature is given below -273.15C.

4. Do **exercise 3** again, but this time handle the error inside `ctok()`.

5. Add to the program so that it can also convert from Kelvin to Celsius.

6. Write a program that converts from Celsius to Fahrenheit and from Fahrenheit to Celsius. Use estimation (**§4.7.1**) to see if your results are plausible.

7. Quadratic equations are of the form `a*x2 + b*x + c = 0`. To solve these, one uses the quadratic formula: `search classic formala`. There is a problem, though: if *b2- 4ac* is less than zero, then it will fail. Write a program that can calculate *x* for a quadratic equation. Create a function that prints out the roots of a quadratic equation, given *a*, *b*, *c*. When the program detects an equation with no real roots, have it print out a message. How do you know that your results are plausible? Can you check that they are correct?

8. Write a program that reads and stores a series of integers and then computes the sum of the first *N* integers. First ask for *N*, then read the values into a `vector`, then calculate the sum of the first *N* values. For example:
    Please enter the number of values you want to sum: **3**
    Please enter some integers (press ’|’ to stop): **12 23 13 24 15** |
    The sum of the first **3** numbers ( **12 23 13** )is **48**
Handle all inputs. For example, make sure to give an error message if the user asks for a sum of more numbers than there are in the vector.

9. Modify the program from the previous exercise to write out an error if the result cannot be represented as an `int`.

10. Modify the program from the previous exercise to use `double` instead of `int`. Also, make a `vector` of `double`'s containing the *N-1* differences between adjacent values and write out that `vector` of differences.

11. Write a program that writes out the first N values of the Fibonacci series, that is, the series that starts with *1 1 2 3 5 8 13 21 34*. The next number of the series is the sum of the two previous ones. Find the largest Fibonacci number that fits in an `int`.

12. Implement a little guessing game called (for some obscure reason) “Bulls and Cows.” The program has a `vector` of four different integers in the range 0 to 9 (e.g., 1234 but not 1122) and it is the user’s task to discover those numbers by repeated guesses. Say the number to be guessed is 1234 and the user guesses 1359; the response should be “1 bull and 1 cow” because the user got one digit (1) right and in the right position (a bull) and one digit (3) right but in the wrong position (a cow). The guessing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.

13. The program is a bit tedious because the answer is hard-coded into the program. Make a version where the user can play repeatedly (without stopping and restarting the program) and each game has a new set of four digits. You can get four random digits by calling the random number generator **random_int(0,9)** from **PPP_support** (and **§4.7.5**) four times. You will note that if you run that program repeatedly, it will pick the same sequence of four digits each time you start the program. To avoid that, ask the user to enter a number (any number) and call `seed(n)`, also from **PPP_support**, where n is the number the user entered before calling **random_int(0,10)**. Such an n is called a seed, and different seeds give different sequences of random numbers.

14. Read (day-of-the-week,value) pairs from standard input. For example:
```Tuesday 23 Friday 56 Tuesday −3 Thursday 99```
Collect all the values for each day of the week in a `vector<int>`. Write out the values of the seven day-of-the-week `vector`s. Print out the sum of the values in each `vector`. Ignore illegal days of the week, such as **Funday**, but accept common synonyms such as **Mon** and **monday**. Write out the number of rejected values.