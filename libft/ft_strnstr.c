/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:14:07 by dtony             #+#    #+#             */
/*   Updated: 2018/12/12 16:08:08 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s;

	s = (char *)str;
	i = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (s);
	while (s[i] && !(i > len))
	{
		j = 0;
		while (s[i + j] == to_find[j] && i + j < len)
		{
			if (to_find[j + 1] == '\0')
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
