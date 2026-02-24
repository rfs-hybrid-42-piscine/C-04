# 🟢 Exercise 05: ft_atoi_base

## 📝 Objective
Write a function that converts a string representation of a number in a specific custom base back into a standard integer.

## 💡 The Logic
This combines the parsing logic of `ex03` with the base mathematics of `ex04`.

1. **Strict Base Validation:** We validate the base exactly as we did in `ex04`, with one extra rule: the base cannot contain whitespaces either.
2. **Parsing:** We parse leading whitespaces and mathematical signs exactly like standard `ft_atoi`.
3. **Base Translation:** We read the characters of the string. For each character, we use a helper function (`ft_get_base_index`) to find its matching index inside the `base` string. If it's not found (returns `-1`), we break the loop. 
4. **Accumulation:** To build the final integer, we multiply our current result by the base's length, and add the index value of the current character. Finally, we multiply by the calculated sign.

*Norm Trick:* The `while` loop logic is heavily condensed using post-increment operators (e.g., `ft_get_base_index(*str++, base)`) to stay strictly under the 25-line limit imposed by Norminette.

## 🛠️ Step-by-Step Solution

1. **The Code:**
   *Check out the source file here:* **[`ft_atoi_base.c`](ft_atoi_base.c)**

2. **Testing:**
   Use the master **[`tester.c`](../tester.c)** file provided in the root `C-04` directory. You must pass the `-D EX05` flag to the compiler to selectively activate the test for this specific exercise!
   ```bash
   cc -Wall -Wextra -Werror -D EX05 ../tester.c ft_atoi_base.c -o test_ex05
   ./test_ex05
   ```
