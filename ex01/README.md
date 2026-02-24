# 🟢 Exercise 01: ft_putstr

## 📝 Objective
Create a function that prints a string of characters to the standard output.

## 💡 The Logic
Because we cannot use `printf`, we must interact directly with the operating system using the `write` system call from `<unistd.h>`.

After checking for a `NULL` pointer, we use a `while` loop to iterate through the string. We pass each character individually to `write(1, str++, 1)`. The `++` operator advances the pointer to the next memory address immediately after writing the current character, making the loop incredibly concise. The loop stops when it encounters the null byte `\0`.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_putstr.c`](ft_putstr.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-04` directory. You must pass the `-D EX01` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX01 ../tester.c ft_putstr.c -o test_ex01
   ./test_ex01
   ```
