### 📚 DRILL Chapter 8

---

Write `Day`, `Month`, and their associated functions as described above. Complete the final version of `Date` with default constructor, `is_valid()`, `Month`, `Year`, etc. Define a `Date` called `today` initialized to February 2, 2020. Then, define a `Date` called `tomorrow` and give it a value by copying `today` into it and increasing its day by one using `add_day()`. Finally, output `today` and `tomorrow` using a `<<` defined as in __`§9.6`__ and __`§9.7`__.

Your check for a valid date, `is_valid()`, may be very simple. Feel free to ignore leap years. However, don’t accept a month that is not in the [1,12] range or a day of the month that is not in the [1,31] range. Test each version with at least one invalid date (e.g., 2004, 13, -5).