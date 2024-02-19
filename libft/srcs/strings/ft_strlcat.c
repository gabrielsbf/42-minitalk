/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:12:56 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/23 20:58:28 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	if ((!dst) && size == 0)
		return (0);
	src_len = ft_strlen(src);
	dest_len = ft_strlen((const char *)dst);
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && size > (dest_len + i + 1))
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
