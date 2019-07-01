/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <dtony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 13:31:03 by dtony             #+#    #+#             */
/*   Updated: 2019/06/05 13:31:03 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfjoin(char *s1, char const *s2)
{
	char	*ret;

	if (!s1)
		return (ft_strdup(s2));
	if (s2)
	{
		if (!(ret = (char *)malloc(ft_strlen(s1) +
								ft_strlen(s2) + 1)))
			return (NULL);
		ft_strcpy(ret, s1);
		ft_strcat(ret, s2);
        free(s1);
        s1 = NULL;
		return (ret);
	}
	return (NULL);
}