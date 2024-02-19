/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:51:53 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/24 18:51:55 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			limit;
	unsigned char	*dest_p;
	unsigned char	*src_p;

	dest_p = (unsigned char *)dst;
	src_p = (unsigned char *)src;
	limit = 0;
	if (!dest_p && !src_p)
		return (NULL);
	while (n > limit)
	{
		*(dest_p + limit) = *(src_p + limit);
		limit++;
	}
	return (dst);
}
