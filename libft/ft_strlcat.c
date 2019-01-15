/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:46:37 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 10:46:38 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	destlength;
	size_t	srclength;

	i = 0;
	destlength = ft_strlen(dest);
	srclength = ft_strlen((char *)src);
	if (size <= destlength)
		return (srclength + size);
	while ((dest[i] != '\0') && i < (size - 1))
		i++;
	while (*src && i < (size - 1))
	{
		dest[i] = *src;
		i++;
		src++;
	}
	dest[i] = '\0';
	return (destlength + srclength);
}
