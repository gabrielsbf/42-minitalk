/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:13 by gabrfern          #+#    #+#             */
/*   Updated: 2023/11/03 14:08:14 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i_begin;
	size_t	i_last;

	if (!s1)
		return (NULL);
	i_begin = 0;
	i_last = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[i_begin]) != 0)
		i_begin++;
	if (i_begin > i_last)
	{
		ptr = ft_calloc(1, sizeof(char));
		if (!ptr)
			return (NULL);
		*ptr = '\0';
		return (ptr);
	}
	while (ft_strrchr(set, s1[i_last]) != 0)
		i_last--;
	ptr = ft_substr(s1, i_begin, i_last - i_begin + 1);
	return (ptr);
}
