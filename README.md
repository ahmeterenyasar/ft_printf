# ft_printf

*This project has been created as part of the 42 curriculum by ahmet-eren-yasar.*

## Description

The **ft_printf** project is a recoding of the standard C library function `printf()`. This project aims to deepen understanding of variadic functions, string formatting, and efficient output handling in C. By implementing our own version of printf, we gain insight into how formatted output works at a low level and learn to handle various data types and format specifiers.

The implementation supports the following conversions:
- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address in hexadecimal format
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (base 16) lowercase format
- `%X` - Print a number in hexadecimal (base 16) uppercase format
- `%%` - Print a percent sign

## Instructions

### Compilation

To compile the library, run:
```bash
make
```

This will create a static library file named `libftprintf.a`.

### Cleaning

To remove object files:
```bash
make clean
```

To remove object files and the library:
```bash
make fclean
```

To recompile everything from scratch:
```bash
make re
```

### Usage

1. Compile the library using `make`
2. Include the header in your C file:
   ```c
   #include "ft_printf.h"
   ```
3. Compile your program with the library:
   ```bash
   gcc your_file.c libftprintf.a -o your_program
   ```
4. Use `ft_printf()` just like the standard `printf()`:
   ```c
   ft_printf("Hello %s!\n", "World");
   ft_printf("Number: %d, Hex: %x\n", 42, 42);
   ```

### Testing

A test file `main.c` is included in the repository. You can compile and run it:
```bash
gcc main.c libftprintf.a -o test
./test
```

## Algorithm and Data Structure

### Implementation Strategy

The `ft_printf` function uses a **variadic function approach** with the `stdarg.h` library to handle a variable number of arguments. The core algorithm follows these steps:

1. **Parsing**: Iterate through the format string character by character
2. **Format Detection**: When a `%` character is encountered, identify the next character as a format specifier
3. **Type Dispatching**: Based on the format specifier, call the appropriate printing function
4. **Output Tracking**: Each printing function returns the number of characters printed, which are accumulated to return the total count

### Data Structure Choice

The implementation uses a **function pointer approach** through conditional branching (`if-else` statements). While a more advanced implementation could use an array of function pointers indexed by format specifier for O(1) lookup, the current approach is:

- **Simple and readable**: Easy to understand and maintain
- **Sufficient for the scope**: With only 9 format specifiers, the performance difference is negligible
- **Memory efficient**: No static lookup table needed

### Key Technical Decisions

1. **Modular Design**: Each conversion type is handled by a separate function (`ft_print_char`, `ft_print_str`, `ft_print_hex`, etc.), making the code maintainable and testable.

2. **Recursive Number Printing**: For integer and hexadecimal conversions, a recursive approach is used to print digits from most significant to least significant.

3. **Character-by-Character Output**: Using `write()` system call with individual characters for simplicity, though buffering could improve performance.

4. **Return Value Tracking**: Every print function returns the number of characters printed, ensuring accurate total count as per the original `printf()` behavior.

## Resources

### Documentation
- [printf man page](https://man7.org/linux/man-pages/man3/printf.3.html) - Official documentation for printf
- [stdarg.h documentation](https://en.cppreference.com/w/c/variadic) - Variadic functions in C
- [42 ft_printf subject](https://github.com/42Paris/ft_printf) - Official project subject

### Articles and Tutorials
- [Secrets of printf](https://www.cprogramming.com/tutorial/printf-format-strings.html) - Understanding printf format specifiers
- [Variadic Functions in C](https://www.gnu.org/software/libc/manual/html_node/Variadic-Functions.html) - GNU C Library manual on variadic functions
- [Base conversion algorithms](https://en.wikipedia.org/wiki/Hexadecimal) - Understanding hexadecimal conversion

### AI Usage
AI was used in the following capacity for this project:
- **Code Review**: AI tools were used to review code for potential bugs and style improvements
- **Documentation**: Assistance in formatting and structuring this README file
- **Debugging Support**: Help in understanding edge cases and error scenarios
- **No Direct Code Generation**: The core implementation logic was written independently to ensure learning objectives were met

## Features

- ✅ Handles all mandatory conversions: `c`, `s`, `p`, `d`, `i`, `u`, `x`, `X`, `%%`
- ✅ Returns the number of characters printed
- ✅ Proper error handling for NULL pointers
- ✅ Handles negative numbers for signed integers
- ✅ Correct hexadecimal conversion (uppercase and lowercase)
- ✅ Pointer address formatting with `0x` prefix
- ✅ Compiled with strict flags: `-Wall -Wextra -Werror`

## Technical Choices

### Why Not Use Standard Library Functions?

The project specifically requires implementation without using standard library functions like `printf` family functions. We use only:
- `write()` - for output
- `malloc()` - if needed for string manipulation (though minimized in this implementation)
- `va_start()`, `va_arg()`, `va_end()` - for variadic argument handling

### Compilation Flags

The project is compiled with `-Wall -Wextra -Werror` to ensure:
- All warnings are enabled
- No potential bugs slip through
- Code follows best practices
- Clean, production-quality code

## Project Structure

```
.
├── ft_printf.c         # Main printf function and format dispatcher
├── ft_printf.h         # Header file with function prototypes
├── ft_print_chars.c    # Character and string printing functions
├── ft_print_nums.c     # Numeric conversion functions
├── ft_print_hex.c      # Hexadecimal conversion functions
├── Makefile           # Build automation
├── main.c             # Test file
└── README.md          # This file
```

---

**Note**: This project is part of the 42 Network's common core curriculum and follows the school's norm and coding standards.