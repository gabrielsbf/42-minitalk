/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:59 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/23 19:15:13 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	char	*c_big;

	c_big = (char *)big;
	i_big = 0;
	if (*little == 0 || ((!c_big) && len == 0))
		return ((char *)c_big);
	while (c_big[i_big] != '\0' && len > i_big)
	{
		i_little = 0;
		while (c_big[i_big] == little[i_little]
			&& len > i_big && c_big[i_big] != '\0')
		{
			i_big++;
			i_little++;
		}
		if (little[i_little] == '\0')
			return (&c_big[i_big - i_little]);
		if (c_big[i_big] == little[0])
			i_big--;
		i_big++;
	}
	return (0);
}
