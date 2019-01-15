/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:49:09 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 11:45:53 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*destcpy;
	unsigned char	*srccpy;
	size_t			i;

	destcpy = (unsigned char *)dest;
	srccpy = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		if (srccpy[i] == (unsigned char)c)
			return (destcpy + (i + 1));
		i++;
	}
	return (NULL);
}
