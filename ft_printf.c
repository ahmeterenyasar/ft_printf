

#include "ft_printf.h"

int ft_printf(const char* str, ...)
{
    int i;
    va_list args;
    int print_len;

    i = 0;
    print_len = 0;
    va_start(args, str);
    while (str[i])
    {
        if (str[i] == '%')
        {
            print_len += ft_formats(args, str[i + 1]);
            i++;
        }
        else
        {
            print_len += ft_print_char(str[i]);
        }
        i++;
    }
    va_end(args);
    return (print_len);
    
}