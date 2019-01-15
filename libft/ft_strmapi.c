/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:51:01 by dtony             #+#    #+#             */
/*   Updated: 2018/12/12 19:07:35 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = -1;
	if (s)
	{
		if (!(map = (char *)malloc(ft_strlen(s) + 1)))
			return (NULL);
		while (s[++i])
			map[i] = f(i, s[i]);
		map[i] = '\0';
		return (map);
	}
	return (NULL);
}
