/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:14:42 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 11:14:44 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	s = (char *)str;
	if (to_find[0] == '\0')
		return (s);
	while (s[i])
	{
		j = 0;
		while (s[i + j] == to_find[j])
		{
			if (to_find[j + 1] == '\0')
				return (s + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
