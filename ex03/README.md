# 🟢 Exercise 03: ft_atoi

## 📝 Objective
Write a function that converts the initial portion of a string into its integer representation.

## 💡 The Logic
This function mimics the standard `atoi` behavior but adds a twist: it must handle multiple `+` and `-` signs.

1. **Whitespaces:** We first use a `while` loop to skip over any leading spaces or invisible control characters (`\t`, `\n`, `\r`, etc.).
2. **Signs:** We loop through consecutive `+` and `-` characters. Every time we encounter a `-`, we multiply our `sign` variable by `-1`. If there is an odd number of minuses, the final result will be negative.
3. **Digit Accumulation:** Once we hit the numbers, we loop as long as the character is between `'0'` and `'9'`. To build the integer, we take our current result, multiply it by `10` (shifting it to the left), and add the mathematical value of the current character (`*str - '0'`). The loop stops the moment a non-digit is encountered.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_atoi.c`](ft_atoi.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-04` directory. You must pass the `-D EX03` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX03 ../tester.c ft_atoi.c -o test_ex03
   ./test_ex03
   ```
