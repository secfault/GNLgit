/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:50:04 by dtony             #+#    #+#             */
/*   Updated: 2018/12/12 16:13:31 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	int		*tab;

	i = 0;
	if (!(tab = (int *)malloc(size)))
		return (NULL);
	while (!(i > size))
	{
		tab[i] = 0;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
