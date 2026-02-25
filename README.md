*This project has been created as part of the 42 curriculum by maaugust.*

<div align="center">
  <img src="https://raw.githubusercontent.com/rfs-hybrid/42-piscine-artwork/main/assets/covers/cover-c04.png" alt="C 04 Cover" width="100%" />
</div>

<div align="center">
  <h1>💻 C 04: Strings & Base Conversions</h1>
  <p><i>Mastering integer parsing, terminal output, and algorithmic base conversions.</i></p>
  
  <img src="https://img.shields.io/badge/Language-C-blue" alt="Language badge" />
  <img src="https://img.shields.io/badge/Grade-100%2F100-success" alt="Grade badge" />
  <img src="https://img.shields.io/badge/Norminette-Passing-success" alt="Norminette badge" />
</div>

---

## 💡 Description
**C 04** shifts the focus from purely evaluating string characters to performing meaningful transformations between text and integers. 

In this module, you will build foundational C tools from scratch. You will learn how to print raw integers to the terminal, safely parse mathematical strings into integer variables, and develop algorithms capable of translating numbers across different mathematical bases (such as binary, octal, decimal, and hexadecimal).

---

## 🧠 Exercise Breakdown & Logic

*The following section explains the core concepts required to solve each exercise. It focuses on the fundamental logic of C programming, emphasizing manual memory manipulation and edge-case management.*

### 🔹 String & Number Output
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex00: ft_strlen`](ex00)** | **String Length:** Reproducing the standard `strlen` function. <br><br>**Logic:** We iterate through the string with a counter until we hit the null-terminator `\0`, returning the final count. |
| **[`ex01: ft_putstr`](ex01)** | **Standard Output:** Printing a string to the terminal using `write`. <br><br>**Logic:** We iterate through the string, using the `write` system call on each character until the null-terminator is reached. |
| **[`ex02: ft_putnbr`](ex02)** | **Printing Integers:** Creating a function that displays an `int` variable as text on the screen. <br><br>**Logic:** `write` only understands characters, not integers. We must use recursion to divide the number by 10, peeling off the last digit using modulo (`% 10`), converting it to its ASCII equivalent by adding `'0'`, and printing it. <br>*Crucial Trap:* It must handle all possible `int` values. You must explicitly handle `INT_MIN` (-2147483648), because converting it to a positive number will overflow a standard 32-bit signed integer! We solve this by safely casting the absolute value to an `unsigned int` before doing any math. |

### 🔢 Parsing & Base Conversions
| Exercise | Concept & Logic |
| :--- | :--- |
| **[`ex03: ft_atoi`](ex03)** | **ASCII to Integer:** Converting a string representation of a number into an actual `int` variable. <br><br>**Logic:** <br>1. **Whitespaces:** Skip all leading whitespace characters. <br>2. **Signs:** Count all consecutive `+` and `-` signs. If the total count of `-` signs is odd, the final number is negative. <br>3. **Digits:** Iterate through the valid base-10 digits, accumulating the total by multiplying the current result by 10 and adding the new digit (subtracting `'0'` to get its real integer value). Stop when a non-digit is found. |
| **[`ex04: ft_putnbr_base`](ex04)** | **Custom Base Output:** Displaying a number using a custom alphabet (base). <br><br>**Logic:** Similar to `ft_putnbr`, but instead of dividing by 10, we divide by the length of the provided `base` string. The modulo gives us the index of the character to print from the base string. <br>*Crucial:* The base must be validated first! It is invalid if it is empty, has a size of 1, contains duplicates, or contains `+` or `-`. |
| **[`ex05: ft_atoi_base`](ex05)** | **Custom Base Parsing:** Converting a string into an integer using a specific mathematical base. <br><br>**Logic:** The ultimate combo. We validate the base using the rules from `ex04`, but with an added restriction: the base cannot contain whitespaces either. We parse the string's whitespaces and signs exactly like `ex03`. Finally, we iterate through the string's digits. For each character, we find its matching index in the `base` string, and accumulate the result by multiplying by the base length and adding the index value. |

---

## 🛠️ Instructions

### 🧪 Compilation & Testing (The Master Test)
Unlike Shell scripts, C programs must be compiled before they can be executed. Furthermore, these exercises strictly ask for functions, not complete programs. 

To make testing incredibly easy while avoiding "undefined reference" linker errors, the **[`tester.c`](tester.c)** file in the root directory uses **C Preprocessor Macros** (`#ifdef`). This allows you to selectively compile and test only the exercises you want.

1. **Clone the repository:**
   ```bash
   git clone <your_repository_link>
   cd 42-Piscine/C-04
   ```

2. **Test a Single Exercise:**
   Pass the corresponding `-D EX**` flag to activate that specific test block inside **[`tester.c`](tester.c)**.
   ```bash
   # Example for ex00:
   cc -Wall -Wextra -Werror -D EX00 tester.c ex00/ft_strlen.c -o test_ex00
   ./test_ex00
   ```

3. **Test Multiple Exercises Together:**
   You can chain multiple `-D` flags to test several functions at once, provided you include all their `.c` files in the command.
   ```bash
   # Example for ex00 and ex01:
   cc -Wall -Wextra -Werror -D EX00 -D EX01 tester.c ex00/ft_strlen.c ex01/ft_putstr.c -o test_multiple
   ./test_multiple
   ```

4. **Test ALL Exercises at Once:**
   By passing the `-D TEST_ALL` master flag, you can activate the entire testing suite in one go!
   ```bash
   cc -Wall -Wextra -Werror -D TEST_ALL tester.c ex00/ft_strlen.c ex01/ft_putstr.c ex02/ft_putnbr.c ex03/ft_atoi.c ex04/ft_putnbr_base.c ex05/ft_atoi_base.c -o test_all
   ./test_all
   ```

> **⚠️ WARNING for 42 Students:** Do not push **[`tester.c`](tester.c)** or any executable files to your final Moulinette repository! They are strictly for local testing purposes. Submitting unauthorized files will result in a 0.

### 🚨 The Norm
Moulinette relies on a program called `norminette` to check if your files comply with the Norm. Every single `.c` and `.h` file must pass. 

**The 42 Header:**
Before writing any code, every file must start with the standard 42 header. `norminette` will automatically fail any file missing this specific signature.
```c
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maaugust <maaugust@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 23:17:04 by maaugust          #+#    #+#             */
/*   Updated: 2025/03/04 14:20:20 by maaugust         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
```

Run the following command before pushing:
```bash
norminette -R CheckForbiddenSourceHeader <file.c>
```

---

## 📚 Resources & References

* `man 3 write` - Manual for standard output writing.
* `man 3 atoi` - Manual for standard string to integer parsing.
* [42 Norm V4](https://cdn.intra.42.fr/pdf/pdf/96987/en.norm.pdf) - The strict coding standard for 42 C projects.
* [Official 42 Norminette Repository](https://github.com/42School/norminette) - The open-source linter enforcing the strict 42 coding standard.

### 🤖 AI Usage Guidelines
* **Code:** No AI-generated code was used to solve these exercises. All C functions were built manually to strictly comply with the 42 Norm and deeply understand manual memory manipulation, enforcing the concept that learning is about developing the ability to find an answer, not just getting one directly.
* **Documentation:** AI tools were utilized to structure this `README.md` and format the logic breakdowns to create a clean, accessible educational resource for fellow 42 students.
