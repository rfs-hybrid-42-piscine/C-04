# 🟢 Exercise 02: ft_putnbr

## 📝 Objective
Create a function that displays the number passed as a parameter. The function must be able to handle all possible values of the `int` type.

## 💡 The Logic
The `write` function only understands characters, not raw integers. We must mathematically break the integer down into individual digits and convert them to their ASCII character equivalents.

1. **The Overflow Trap:** The lowest possible integer (`INT_MIN`) is `-2147483648`. If you simply multiply this by `-1` to make it positive, it overflows the 32-bit signed integer limit (`2147483647`). To solve this, we safely cast the absolute value to an `unsigned int` before doing any math.
2. **Recursion:** We use recursion to divide the number by 10 (`n / 10`) until we reach the first digit. 
3. **ASCII Conversion:** As the recursion unwinds, we take the modulo (`n % 10`) to isolate the last digit, and add the character `'0'` (ASCII 48) to it. This perfectly converts the integer `5` into the character `'5'`, which can then be safely written to the screen.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_putnbr.c`](ft_putnbr.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-04` directory. You must pass the `-D EX02` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX02 ../tester.c ft_putnbr.c -o test_ex02
   ./test_ex02
   ```
