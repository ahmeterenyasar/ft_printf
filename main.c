#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int ret_orjinal;
    int ret_benim;
    char *null_ptr = NULL;

printf("--- TEST 1: Basit String ---\n");
    ret_orjinal = printf("Orjinal: %s\n", "Merhaba 42");
    ret_benim = ft_printf("Benim  : %s\n", "Merhaba 42");
    printf("Return -> Orjinal: %d | Benim: %d\n\n", ret_orjinal, ret_benim);

    printf("--- TEST 2: Sayilar ---\n");
    ret_orjinal = printf("Orjinal: %d, %i, %u\n", 42, -42, 4200);
    ret_benim = ft_printf("Benim  : %d, %i, %u\n", 42, -42, 4200);
    printf("Return -> Orjinal: %d | Benim: %d\n\n", ret_orjinal, ret_benim);

    printf("--- TEST 3: Hex ve Pointer ---\n");
    int a = 42;
    ret_orjinal = printf("Orjinal: %x, %X, %p\n", 255, 255, &a);
    ret_benim = ft_printf("Benim  : %x, %X, %p\n", 255, 255, &a);
    printf("Return -> Orjinal: %d | Benim: %d\n\n", ret_orjinal, ret_benim);

    printf("--- TEST 4: NULL String ---\n");
    ret_orjinal = printf("Orjinal: %s\n", null_ptr);
    ret_benim = ft_printf("Benim  : %s\n", null_ptr);
    printf("Return -> Orjinal: %d | Benim: %d\n\n", ret_orjinal, ret_benim);

    return (0);
}