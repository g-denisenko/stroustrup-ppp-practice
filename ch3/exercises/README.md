### 📚 EXERCISES 

---

1. If you haven’t already, do the **TRY THIS** exercises from this chapter.

2. Write a program that reads a string from input and then, for each character read, prints out the character and its integer value on a line.

3. If we define the median of a sequence as “*a number so that exactly as many elements come before it in the sequence as come after it,*” fix the program in **§3.6.3** so that it always prints out a median. Hint: A median need not be an element of the sequence.

4. Read a sequence of `double` values into a `vector`. Think of each value as the distance between two cities along a given route. Compute and print the total distance (the sum of all distances). Find and print the smallest and greatest distance between two neighboring cities. Find and print the mean distance between two neighboring cities.

5. Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program asks questions to figure out what the number is (e.g., “Is the number you are thinking of less than 50?”). Your program should be able to identify the number after asking no more than seven questions.

6. Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math operations – add, subtract, multiply, and divide – on two input values. Your program should prompt the user to enter three arguments: two `double` values and a character to represent an operation. If the entry arguments are `35.6`, `24.1`, and `'+'`, the program output should be `The sum of 35.6 and 4.1 is 59.7`. In *Chapter 5* and *Chapter 6*, we look at a much more sophisticated simple calculator.

7. Make a `vector` holding the ten `string` values `"zero"`, `"one"`, . . . `"nine"`. Use that in a program that converts a digit to its corresponding spelled-out value; e.g., the input `7` gives the output `seven`. Have the same program, using the same input loop, convert spelled-out numbers into their digit form; e.g., the input `seven` gives the output `7`.

8. Modify the *“mini calculator”* from *exercise 6* to accept (just) single-digit numbers written as either digits or spelled out.

9. There is an old story that the emperor wanted to thank the inventor of the game of chess and asked the inventor to name his reward. The inventor asked for one grain of rice for the first square, 2 for the second, 4 for the third, and so on, doubling for each of the 64 squares. That may sound modest, but there wasn’t that much rice in the empire! Write a program to calculate how many squares are required to give the inventor at least 1000 grains of rice, at least 1,000,000 grains, and at least 1,000,000,000 grains. You’ll need a loop, of course, and probably an `int` to keep track of which square you are at, an `int` to keep the number of grains on the current square, and an `int` to keep track of the grains on all previous squares. We suggest that you write out the value of all your variables for each iteration of the loop so that you can see what’s going on.

10. Try to calculate the number of rice grains that the inventor asked for in *exercise 9* above. You’ll find that the number is so large that it won’t fit in an `int` or a `double`. Observe what happens when the number gets too large to represent exactly as an `int` and as a `double`. What is the largest number of squares for which you can calculate the exact number of grains (using an `int`)? What is the largest number of squares for which you can calculate the approximate number of grains (using a `double`)?

11. Write a program that plays the game “Rock, Paper, Scissors.” If you are not familiar with the game do some research (e.g., on the Web using Google). Research is a common task for programmers. Use a *`switch`*-statement to solve this exercise. Also, the machine should give random answers (i.e., select the next rock, paper, or scissors randomly). Real randomness is too hard to provide just now, so just build a `vector` with a sequence of values to be used as “the next value.” If you build the `vector` into the program, it will always play the same game, so maybe you should let the user enter some values. Try variations to make it less easy for the user to guess which move the machine will make next.

12. Create a program to find all the prime numbers between 1 and 100. One way to do this is to write a function that will check if a number is prime (i.e., see if the number can be divided by a prime number smaller than itself) using a `vector` of primes in order (so that if the `vector` is called `primes`, `primes[0]==2`, `primes[1]==3`, `primes[2]==5`, etc.). Then write a loop that goes from 1 to 100, checks each number to see if it is a prime, and stores each prime found in a `vector`. Write another loop that lists the primes you found. You might check your result by comparing your `vector` of prime numbers with `primes`. Consider 2 the first prime.

13. Create a program to find all the prime numbers between 1 and 100. There is a classic method for doing this, called the *“Sieve of Eratosthenes.”* If you don’t know that method, get on the Web and look it up. Write your program using this method.

14. Write a program that takes an input value n and then finds the first **n** primes.

15. In the drill, you wrote a program that, given a series of numbers, found the max and min of that series. The number that appears the most times in a sequence is called the *mode*. Create a program that finds the mode of a set of positive integers.

16. Write a program that finds the min, max, and mode of a sequence of **string**s.

17. Write a program to solve quadratic equations. A quadratic equation is of the form *ax2 + bx + c = 0*. If you don’t know the formula for solving such an expression, do some research. Remember, researching how to solve a problem is often necessary before a programmer can teach the computer how to solve it. Use *double*s for the user inputs for **a**, **b**, and **c**. Since there are two solutions to a quadratic equation, output both **x1** and **x2**.

18. Write a program where you first enter a set of name-and-value pairs, such as **Joe 17** and **Barbara 22**. For each pair, add the name to a **vector** called **names** and the number to a **vector** called **scores** (in corresponding positions, so that if **names[7]=="Joe"** then **scores[7]==17**). Terminate input with **NoName 0**. Check that each name is unique and terminate with an error message if a name is entered twice. Write out all the (name,score) pairs, one per line.

19. Modify the program from the previous exercise so that once you have entered the name-and-value pairs, you ask for values: In a loop, when you enter a name, the program will output the corresponding score or **name not found**.

20. Modify the program from the previous exercise so that once you have entered the name-and-value pairs, you ask for names: In a loop, when you enter a value, the program will output all the names with that score or **score not found**.