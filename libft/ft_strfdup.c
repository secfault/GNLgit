/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:45:32 by dtony             #+#    #+#             */
/*   Updated: 2019/01/07 19:32:52 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfdup(char *dest, char *src)
{
	char	*new;

	new = NULL;
	if (dest && src)
	{
		new = ft_strdup(src);
		free(dest);
	}
	return (new);
}
