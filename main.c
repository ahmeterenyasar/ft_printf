/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayasar <ayasar@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 10:04:50 by ayasar            #+#    #+#             */
/*   Updated: 2026/04/05 10:21:20 by ayasar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		ret_orjinal;
	int		ret_benim;
	char	*null_ptr;
	int		a;

	null_ptr = NULL;
	a = 42;
	ret_orjinal = printf("Orjinal: %s %d %x %p\n", null_ptr, 42, 255, &a);
	ret_benim = ft_printf("Benim  : %s %d %x %p\n", null_ptr, 42, 255, &a);
	printf("Return -> Orjinal: %d | Benim: %d\n", ret_orjinal, ret_benim);
	return (0);
}
