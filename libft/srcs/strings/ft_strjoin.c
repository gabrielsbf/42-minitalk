/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:06:49 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/31 20:06:51 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sz1;
	size_t	sz2;
	size_t	len;
	char	*ptr;

	if (!s1 || !s2)
		return (NULL);
	sz1 = ft_strlen(s1);
	sz2 = ft_strlen(s2);
	len = sz1 + sz2;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	ft_strlcpy(ptr, s1, sz1 + 1);
	ft_strlcat(ptr, s2, len + 1);
	return (ptr);
}
