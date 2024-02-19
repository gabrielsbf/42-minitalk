/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:58:17 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/18 17:58:18 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*strc;
	int		i;

	strc = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)&strc[i]);
		i++;
	}
	if (s[i] == c)
		return ((char *)&strc[i]);
	return (0);
}
