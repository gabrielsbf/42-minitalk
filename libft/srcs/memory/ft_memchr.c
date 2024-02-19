/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:46:26 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:30 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr( const void *s, int c, size_t n )
{
	unsigned char	*ptr;
	unsigned char	ch;
	size_t			limit;

	ch = (unsigned char)c;
	ptr = (unsigned char *)s;
	limit = 0;
	while (n > limit)
	{
		if (*(ptr + limit) == ch)
			return ((void *)(ptr + limit));
		limit++;
	}
	return (NULL);
}
