# ft_printf

*This project has been created as part of the 42 curriculum by ayasar.*

## Description

`ft_printf` is a 42 project that reimplements the core behavior of libc's `printf` function.
The goal is to correctly handle variadic arguments (`stdarg.h`), format parsing, base conversions, and printed character counting.

This implementation supports all mandatory conversions:
- `%c` character
- `%s` string
- `%p` pointer (hex)
- `%d` / `%i` signed decimal
- `%u` unsigned decimal
- `%x` / `%X` unsigned hex (lower/upper)
- `%%` percent sign

## Instructions

### Build

```bash
make
```

Output: `libftprintf.a`

### Clean

```bash
make clean
make fclean
make re
```

### Usage

```c
#include "ft_printf.h"

int main(void)
{
	ft_printf("Hello %s %d %x\n", "42", 42, 42);
	return (0);
}
```

Example linking:

```bash
cc -Wall -Wextra -Werror your_file.c libftprintf.a -o your_program
```

## Algorithm and Data Structure

### Approach

`ft_printf` parses the format string from left to right in a single pass.
When `%` is encountered, the next character is interpreted as a specifier and dispatched to the relevant helper function.
Each helper function returns the number of printed characters, and the accumulated total is returned as an `int`.

### Rationale for chosen structures

- **Separated helper functions**: `ft_print_char`, `ft_print_str`, `ft_print_nbr`, `ft_print_unsigned`, `ft_print_hex`, `ft_print_ptr`
   - Improves readability
   - Makes Norm line limits easier to manage
   - Simplifies debugging
- **Recursive number printing**:
   - Naturally prints decimal/hex values from the most significant digit
   - Produces output directly with `write` without an extra buffer
- **No extra data structures**:
   - No table/map is required for this scope
   - Keeps memory usage minimal

## Resources

### Documentation
- [printf(3) Linux man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C variadic arguments (cppreference)](https://en.cppreference.com/w/c/variadic)
- [Hexadecimal number system](https://en.wikipedia.org/wiki/Hexadecimal)

### AI Usage
AI was used in the following capacity for this project:
- **Code Review**: AI tools were used to review code for potential bugs and style improvements
- **Documentation**: Assistance in formatting and structuring this README file
- **Debugging Support**: Help in understanding edge cases and error scenarios
- **No Direct Code Generation**: The core implementation logic was written independently to ensure learning objectives were met

## Notes

- The project is compiled with `cc -Wall -Wextra -Werror`.
- `Makefile` rules: `all`, `clean`, `fclean`, `re`, `$(NAME)`.
- The library is generated at the repository root as `libftprintf.a`.