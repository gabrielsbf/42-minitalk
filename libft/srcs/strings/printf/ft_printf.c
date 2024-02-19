/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:17:00 by gabrfern          #+#    #+#             */
/*   Updated: 2023/12/06 15:17:02 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	return_arg(va_list args, char type, int *result)
{
	if (!ft_strchr("cspdiuxX%", type))
		return (0);
	if (type == 'c')
		ft_putchar_r(va_arg(args, int), 1, result);
	else if (type == 's')
		ft_putstr_r(va_arg(args, char *), 1, result);
	else if (type == 'p')
		ft_puthex_r(va_arg(args, unsigned long), 1, 1, result);
	else if (type == 'd' || type == 'i')
		ft_putnbr_r(va_arg(args, int), 1, result);
	else if (type == 'u')
		ft_putnbu_r(va_arg(args, unsigned int), 1, result);
	else if (type == 'x')
		ft_puthex_r(va_arg(args, unsigned int), 1, 0, result);
	else if (type == 'X')
		ft_puthex_upper_r(va_arg(args, unsigned int), 1, result);
	else if (type == '%')
		ft_putchar_r('%', 1, result);
	return (1);
}

int	ft_printf(const char *text, ...)
{
	va_list	args;
	int		result;
	int		i;

	result = 0;
	i = 0;
	va_start(args, text);
	while (text[i] != '\0')
	{
		while(text[i] == '%')
		{
			if (text[i] == '%' && text[i++] != '\0' && return_arg(args, text[i], &result) == 1)
				i++;
			else
			{
				ft_putchar_r(text[i], 1, &result);
				i++;
			}
		}
		if (text[i] == '\0')
			break ;
		ft_putchar_r(text[i], 1, &result);
		i++;
	}
	va_end(args);
	return (result);
}

// int	main(void)
// {
// 	#include <stdio.h>
// 	#include <limits.h>
// 	// int val = 200;
// 	// int *pointer = &val;
// 	int ft_printf_result = ft_printf("ULONG = %x -- UINT = %x\n", 9223372036854775807,UINT_MAX);
// 	printf("%d\n", ft_printf_result);
// 	int printf_result = printf("ULONG = %x -- UINT = %x\n", 9223372036854775807,UINT_MAX);
// 	printf("%d\n", printf_result);
// }
