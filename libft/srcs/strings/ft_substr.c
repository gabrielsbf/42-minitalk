/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:08:14 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/31 20:08:15 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			s_size;
	size_t			i_ptr;
	char			*ptr;

	if (!s)
		return (NULL);
	i_ptr = 0;
	s_size = ft_strlen(s);
	if (s_size <= start)
		len = 0;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while (i_ptr < len && s_size > start)
	{
		ptr[i_ptr] = s[start];
		start++;
		i_ptr++;
	}
	ptr[i_ptr] = '\0';
	return (ptr);
}
