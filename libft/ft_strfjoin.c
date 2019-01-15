/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtony <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 18:54:34 by dtony             #+#    #+#             */
/*   Updated: 2019/01/07 18:54:39 by dtony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strfjoin(char const *s1, char const *s2)
{
    char    *ret;

    if (s1 && s2)
    {
        if (!(ret = (char *)malloc(ft_strlen(s1) +
                                   ft_strlen(s2) + 1)))
            return (NULL);
        ft_strcpy(ret, s1);
        ft_strcat(ret, s2);
		free(s1);
        return (ret);
    }
    return (NULL);
}
