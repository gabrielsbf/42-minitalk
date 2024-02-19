/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbu_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:20:05 by gabrfern          #+#    #+#             */
/*   Updated: 2023/12/06 15:20:06 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putnbu_r(unsigned int n, int fd, int *result)
{
	if (n > 9)
	{
		ft_putnbu_r(n / 10, fd, result);
		ft_putnbu_r(n % 10, fd, result);
	}
	else
		ft_putchar_r(n + '0', fd, result);
}
