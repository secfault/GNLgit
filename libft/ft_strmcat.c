/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:12:20 by dtony             #+#    #+#             */
/*   Updated: 2019/01/07 18:14:24 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmcat(char *dest, const char *src)
{
	char	*new;

	new = NULL;
	if (dest && src)
	{
		if (!(new = malloc(ft_strlen(dest) + ft_strlen(src) + 1)))
			return (NULL);
		new = ft_strcat(dest, src);
		free(dest);
	}
	return (new);
}
