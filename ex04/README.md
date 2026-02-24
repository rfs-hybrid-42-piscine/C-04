# 🟢 Exercise 04: ft_putnbr_base

## 📝 Objective
Create a function that displays a number in a given base system in the terminal (e.g., binary, hexadecimal, octal).

## 💡 The Logic
This builds upon the recursion from `ft_putnbr`, but makes the divisor dynamic based on the length of the provided alphabet.

1. **Base Validation:** A base is invalid (and prints nothing) if it is empty, length 1, contains duplicate characters, or contains `+` or `-`. We use nested loops to check for duplicates efficiently.
2. **Safe Math:** Just like in `ex02`, we cast the number to an `unsigned int` to prevent `INT_MIN` overflow.
3. **Recursive Base Conversion:** Instead of dividing by 10, we divide by the length of the base string. To print the correct character, we calculate the modulo (`nbr % base_len`) and use that result as the index to access the specific character inside the `base` array.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_putnbr_base.c`](ft_putnbr_base.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-04` directory. You must pass the `-D EX04` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX04 ../tester.c ft_putnbr_base.c -o test_ex04
   ./test_ex04
   ```
