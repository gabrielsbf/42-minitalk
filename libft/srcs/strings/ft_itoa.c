/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:44:07 by gabrfern          #+#    #+#             */
/*   Updated: 2023/11/07 17:44:08 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	count_numb(int n)
{
	int		counter;
	int		n_numb;

	counter = 1;
	n_numb = n;
	if (n_numb == -2147483648)
		return (11);
	if (n_numb < 0)
	{
		n_numb = n_numb * -1;
		counter++;
	}
	while (n_numb > 9)
	{
		n_numb = n_numb / 10;
		counter++;
	}
	return (counter);
}

static void	is_intmin(int n, char *ptr, int last_n)
{
	if (n == -2147483648)
	{
		while (last_n > 0 && ptr[last_n - 1] == 0)
		{
			ptr[last_n - 1] = -(n % 10) + 48;
			n = n / 10;
			last_n--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*ptr;
	int		last_n;

	last_n = count_numb(n);
	ptr = ft_calloc(last_n + 1, sizeof(char));
	if (!ptr)
		return (NULL);
	ptr[last_n] = 0;
	is_intmin(n, ptr, last_n);
	if (n == 0)
		ptr[0] = 48;
	if (n < 0)
	{
		ptr[0] = '-';
		n = n * -1;
	}
	while (last_n > 0 && ptr[last_n - 1] == 0)
	{
		ptr[last_n - 1] = (n % 10) + 48;
		n = n / 10;
		last_n--;
	}
	return (ptr);
}
