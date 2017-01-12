/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:09:21 by mchemakh          #+#    #+#             */
/*   Updated: 2016/11/14 21:51:37 by mchemakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	int		i;
	char	*cdest;
	char	*csrc;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	while (n > 0)
	{
		cdest[i] = csrc[i];
		i++;
		n--;
	}
	return (cdest);
}
