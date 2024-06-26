/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehamm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:52:29 by ehamm             #+#    #+#             */
/*   Updated: 2024/02/26 10:37:18 by ehamm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(char *dest, char *src, int c, int n)
{
	while (n--)
	{
		if (*src == c)
		{
			*dest++ = *src++;
			return (dest);
		}
		*dest++ = *src;
	}
	return (NULL);
}
