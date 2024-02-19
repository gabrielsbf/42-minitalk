/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_r.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:16:42 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/31 20:20:15 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putstr_r(char *s, int fd, int *result)
{
	int	len;

	if (!s)
	{
		write(1, "(null)", 6);
		*result = *result + 6;
	}
	else{
		len = ft_strlen(s);
		*result = *result + len;
		write(fd, s, len);
	}
}
