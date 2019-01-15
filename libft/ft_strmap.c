/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:52:06 by dtony             #+#    #+#             */
/*   Updated: 2018/12/12 19:05:37 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = -1;
	if (s)
	{
		if (!(map = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[++i])
			map[i] = f(s[i]);
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
