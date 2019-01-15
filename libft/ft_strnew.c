/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:13:09 by dtony             #+#    #+#             */
/*   Updated: 2018/12/05 11:13:30 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	i = 0;
	if (!(str = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (!(i > size))
	{
		str[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}
