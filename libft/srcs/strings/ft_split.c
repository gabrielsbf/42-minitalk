/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:05:57 by gabrfern          #+#    #+#             */
/*   Updated: 2023/11/14 20:32:09 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static unsigned int	num_arr(const char *str, char c)
{
	unsigned int	i;
	unsigned int	char_count;
	unsigned int	c_encounter;

	c_encounter = 0;
	char_count = 0;
	i = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != c)
			char_count++;
		if (str[i] == c && char_count > 0)
		{
			c_encounter++;
			char_count = 0;
		}
		i++;
	}
	if (char_count > 0)
		c_encounter++;
	return (c_encounter);
}

static unsigned int	num_char(const char *str, char c, unsigned int index)
{
	unsigned int	i_arr;
	unsigned int	i;
	unsigned int	char_count;

	char_count = 0;
	i = 0;
	i_arr = 0;
	if (c == '\0')
		return (1);
	while (str[i])
	{
		if (str[i] != c)
			char_count++;
		if (str[i] == c && char_count > 0)
		{
			if (i_arr == index)
				break ;
			i_arr++;
			char_count = 0;
		}
		i++;
	}
	return (char_count);
}

static char	**case_null(char **ptr_arr, char const *s)
{
	if (ft_strlen(s) > 0)
	{
		ptr_arr[0] = malloc((ft_strlen(s) + 1) * sizeof(char *));
		ft_strlcpy(ptr_arr[0], s, ft_strlen(s) + 1);
		return (ptr_arr);
	}
	else
	{
		ptr_arr[0] = malloc(1 * sizeof(char *));
		if (!(ptr_arr[0]))
		{
			free(ptr_arr);
			return (NULL);
		}
		ptr_arr[0] = NULL;
		return (ptr_arr);
	}
}

static char	**do_malloc(char const *s, char c)
{
	char	**ptr_arr;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	ptr_arr = (char **)malloc((num_arr(s, c) + 1) * sizeof(char *));
	if (!ptr_arr)
		return (NULL);
	while (i < (int)num_arr(s, c))
	{
		ptr_arr[i] = (char *)malloc((num_char(s, c, i) + 1) * sizeof(char));
		if (!ptr_arr[i])
		{
			while (i >= 0)
				free(ptr_arr[i--]);
			free(ptr_arr);
			return (NULL);
		}
		i++;
	}
	ptr_arr[i] = NULL;
	return (ptr_arr);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr_arr;
	unsigned int	i;
	unsigned int	i_char;
	unsigned int	index_s;

	i = 0;
	index_s = 0;
	ptr_arr = do_malloc(s, c);
	if (!ptr_arr)
		return (NULL);
	if (c == '\0' || !s)
		return (case_null(ptr_arr, s));
	while (i < num_arr(s, c))
	{
		i_char = 0;
		while (i_char < num_char(s, c, i))
		{
			while (*(s + index_s) == c)
				index_s++;
			ptr_arr[i][i_char++] = *(s + index_s++);
		}
		ptr_arr[i++][i_char] = '\0';
	}
	return (ptr_arr);
}
